#include <bits/stdc++.h>
#include <tins/tins.h>
#include <fcntl.h>
#define randPort 1541
using namespace std;
using namespace Tins;

bool timeout = false;
vector<int> open_ports;
vector<int> closed_ports;
vector<int> filtered_ports;
vector<int> unfiltered_ports;
vector<int> ports;
vector<IPv4Address> hosts;
vector<IPv4Address> alive_hosts;
vector<IPv4Address> dead_hosts;
IPv4Address next_ip(const IPv4Address &ip)
{
    uint32_t ip_int = ip;
    ip_int = htonl(ntohl(ip_int) + 1); // Network byte order adjustment
    return IPv4Address(ip_int);
}
unsigned long ipToLong(const string &ip)
{
    unsigned long val = 0;
    size_t start = 0;
    size_t end = ip.find('.');
    while (end != string::npos)
    {
        val = (val << 8) + stoi(ip.substr(start, end - start));
        start = end + 1;
        end = ip.find('.', start);
    }
    val = (val << 8) + stoi(ip.substr(start));
    return val;
}
class NetworkScanner
{
public:
    NetworkScanner(const NetworkInterface &interface, const vector<IPv4Address> &hosts, int type);
    ~NetworkScanner() { sniffer.stop_sniff(); }
    void run();

private:
    bool callback(PDU &pdu);
    void send_echo_requests(IPv4Address host);
    void send_arp_request(IPv4Address host);
    void launch_sniffer();
    void check_timeouts();

    NetworkInterface iface;
    vector<IPv4Address> hosts_to_scan;
    map<IPv4Address, int> attempts;
    Sniffer sniffer;
    PacketSender sender;
    int scan_type;
};
NetworkScanner::NetworkScanner(const NetworkInterface &interface, const vector<IPv4Address> &hosts, int type)
    : iface(interface), hosts_to_scan(hosts), sniffer(interface.name()), sender(interface)
{
    scan_type = type;
    if (type == 1)
    {
        sniffer.set_filter("icmp and icmp[icmptype] = icmp-echoreply");
    }
    else
    {
        sniffer.set_filter("arp and arp[op] = 2"); // ARP reply
    }

    for (auto &host : hosts_to_scan)
    {
        attempts[host] = 0;
    }
}

bool NetworkScanner::callback(PDU &pdu)
{
    if (scan_type == 1)
    {
        const IP &ip = pdu.rfind_pdu<IP>();
        const ICMP &icmp = pdu.rfind_pdu<ICMP>();
        if (icmp.type() == ICMP::ECHO_REPLY)
        {
            auto it = attempts.find(ip.src_addr());
            if (it != attempts.end() && it->second <= 3)
            {
                alive_hosts.push_back(ip.src_addr());
                attempts.erase(it); // Stop further attempts for this host
            }
        }
    }
    else if (scan_type == 2)
    {
        const ARP &arp = pdu.rfind_pdu<ARP>();
        if (arp.opcode() == ARP::REPLY)
        {
            IPv4Address src_ip = arp.sender_ip_addr();
            alive_hosts.push_back(src_ip);
            attempts.erase(src_ip); // Assume only 1 ARP request was needed
        }
    }
    return true;
}

void NetworkScanner::send_echo_requests(IPv4Address host)
{
    if (scan_type == 1 && attempts[host] < 3)
    {
        IP ip(host, iface.addresses().ip_addr);
        ICMP icmp;
        icmp.type(ICMP::ECHO_REQUEST);
        auto request = ip / icmp;
        sender.send(request);
        attempts[host]++;
    }
    else if (scan_type == 2)
    {
        send_arp_request(host);
    }
}

void NetworkScanner::send_arp_request(IPv4Address host)
{
    EthernetII eth = EthernetII(HWAddress<6>("ff:ff:ff:ff:ff:ff"), iface.hw_address()) /
                     ARP(iface.addresses().ip_addr, host, iface.hw_address(), HWAddress<6>("00:00:00:00:00:00"));
    eth.rfind_pdu<ARP>().opcode(ARP::REQUEST);
    sender.send(eth);
    attempts[host]++;
}

void NetworkScanner::launch_sniffer()
{
    try
    {
        sniffer.sniff_loop(bind(&NetworkScanner::callback, this, placeholders::_1));
    }
    catch (const Tins::invalid_interface &e)
    {
        cout << "Sniffer stopped: Invalid interface - " << e.what() << endl;
    }
    catch (const std::exception &e)
    {
        cout << "Sniffer stopped: " << e.what() << endl;
    }
}

void NetworkScanner::check_timeouts()
{
    while (!attempts.empty())
    {
        this_thread::sleep_for(chrono::seconds(1));
        for (auto it = attempts.begin(); it != attempts.end();)
        {
            if (it->second >= 3)
            {
                it = attempts.erase(it); // Max attempts reached, remove from tracking
            }
            else
            {
                send_echo_requests(it->first);
                ++it;
            }
        }
        if (attempts.empty())
        {
            timeout = true; // Set global timeout if all hosts have reached max attempts
            // cout << "All hosts timed out 3 times. Stopping all tasks." << endl;
        }
    }
}

void NetworkScanner::run()
{
    thread sniffer_thread(&NetworkScanner::launch_sniffer, this);
    if (this->scan_type == 1)
    {
        for (auto &host : hosts_to_scan)
        {
            send_echo_requests(host);
        }
    }
    else if (this->scan_type == 2)
    {
        for (auto &host : hosts_to_scan)
        {
            send_arp_request(host);
        }
    }
    check_timeouts(); // This will handle retransmissions and timeout checks
    if (timeout)
        sniffer.stop_sniff(); // Stop sniffing if global timeout is triggered
    sniffer_thread.join();
}

void scan(const IPv4Address &ip, const vector<IPv4Address> &hosts, int type)
{
    NetworkInterface iface(ip);
    IPv4Address local_ip = iface.addresses().ip_addr;
    alive_hosts.push_back(local_ip);
    NetworkScanner scanner(iface, hosts, type);
    scanner.run();
}
class Scanner
{
public:
    Scanner(int type,
            const NetworkInterface &interface,
            const IPv4Address &address,
            const vector<int> &ports);
    ~Scanner() { sniffer.stop_sniff(); }
    void run(int type);

private:
    int type;
    void send_tcp(const NetworkInterface &iface, IPv4Address dest_ip);
    void send_udps(const NetworkInterface &iface, IPv4Address dest_ip);
    bool callback(PDU &pdu);
    bool udpCallback(PDU &pdu);
    static void *thread_proc(void *param);
    void launch_sniffer();

    NetworkInterface iface;
    IPv4Address local_ip;
    IPv4Address host_to_scan;
    set<uint16_t> ports_to_scan;
    Sniffer sniffer;
};

Scanner::Scanner(int type,
                 const NetworkInterface &interface,
                 const IPv4Address &address,
                 const vector<int> &ports)
    : iface(interface), host_to_scan(address), sniffer(interface.name())
{
    this->type = type;
    if (type == 4)
        sniffer.set_filter("udp and ip src " + address.to_string());
    else
        sniffer.set_filter("tcp and ip src " + address.to_string() + " and tcp[tcpflags] & (tcp-rst|tcp-syn) != 0");
    for (size_t i = 0; i < ports.size(); ++i)
    {
        ports_to_scan.insert(ports[i]);
    }
}
void *Scanner::thread_proc(void *param)
{
    Scanner *data = (Scanner *)param;
    data->launch_sniffer();
    return 0;
}

void Scanner::launch_sniffer()
{
    if (this->type == 4)
    {
        sniffer.sniff_loop(make_sniffer_handler(this, &Scanner::udpCallback));
    }
    else
    {
        sniffer.sniff_loop(make_sniffer_handler(this, &Scanner::callback));
    }
}

bool Scanner::callback(PDU &pdu)
{
    // Retrieve the IP and TCP layers from the PDU.
    const IP &ip = pdu.rfind_pdu<IP>();
    const TCP &tcp = pdu.rfind_pdu<TCP>();

    // Check if the host that we're scanning sent this packet and
    // the source port is one of those that we scanned.
    if (ip.src_addr() == host_to_scan && ports_to_scan.count(tcp.sport()) == 1)
    {
        if (this->type == 1)
        {
            if (tcp.flags() == (TCP::SYN | TCP::ACK))
            {
                open_ports.push_back(tcp.sport());
            }
            else if (tcp.flags() == (TCP::SYN | TCP::RST))
            {
                return false;
            }
            else if (tcp.get_flag(TCP::RST))
            {
                closed_ports.push_back(tcp.sport());
            }
            else
            {
                filtered_ports.push_back(tcp.sport());
            }
        }
        if (this->type == 2)
        {
            if (tcp.flags() == (TCP::ACK | TCP::RST))
            {
                return false;
            }
            if (tcp.get_flag(TCP::RST))
            {
                unfiltered_ports.push_back(tcp.sport());
            }
            else
            {
            }
        }
        if (this->type == 3 || this->type == 5)
        {
            if (tcp.get_flag(TCP::RST))
            {
                if (tcp.get_flag(TCP::FIN))
                    return false;
                closed_ports.push_back(tcp.sport());
            }
            else
            {
                open_ports.push_back(tcp.sport());
            }
        }
    }
    return true;
}

bool Scanner::udpCallback(PDU &pdu)
{
    const IP &ip = pdu.rfind_pdu<IP>();    // Assume IP PDU is always present
    const UDP &udp = pdu.rfind_pdu<UDP>(); // Assume UDP PDU is always present

    if (udp.sport() == 1131 && udp.dport() == 31337)
    {
        return false;
    }

    if (ip.src_addr() == host_to_scan && ports_to_scan.count(udp.sport()) == 1)
    {
        try
        {
            // Assume the ICMP error is nested within another IP PDU which itself contains the original IP header and UDP header
            const IP &inner_ip = pdu.rfind_pdu<RawPDU>().to<IP>(); // Extract the IP PDU encapsulated in a RawPDU
            const ICMP &icmp = inner_ip.rfind_pdu<ICMP>();         // Find ICMP inside the encapsulated IP PDU
            if (icmp.type() == 3 && icmp.code() == 3)
            {
                closed_ports.push_back(udp.sport());
                cout << "Port " << udp.sport() << " is closed" << endl;
            }
            // PDU 长度大于 100 说明是 open 端口
            else if (pdu.size() > 100)
            {
                open_ports.push_back(udp.sport());
                cout << "Port " << udp.sport() << " is open" << endl;
            }
            else
            {
                filtered_ports.push_back(udp.sport());
                cout << "Port " << udp.sport() << " is filtered" << endl;
            }
        }
        catch (std::exception &e)
        { // Handle the exception if ICMP PDU is not found
            open_ports.push_back(udp.sport());
        }
    }

    return true;
}

void Scanner::run(int type)
{
    pthread_t thread;
    pthread_create(&thread, 0, &Scanner::thread_proc, this);
    if (type == 4)
    {
        send_udps(iface, host_to_scan);
    }
    else
    {
        send_tcp(iface, host_to_scan);
    }
    void *dummy;
    pthread_join(thread, &dummy);
}
// Send syns to the given ip address, using the destination ports provided.
void Scanner::send_tcp(const NetworkInterface &iface, IPv4Address dest_ip)
{
    NetworkInterface::Info info = iface.addresses();
    PacketSender sender;
    // IP PDU
    IP ip = IP(dest_ip, info.ip_addr) / TCP();
    TCP &tcp = ip.rfind_pdu<TCP>();
    switch (this->type)
    {
    case 1:
    {
        tcp.set_flag(TCP::SYN, 1);
        cout << "Sending SYNs..." << endl;
        break;
    }
    case 2:
    {
        tcp.set_flag(TCP::ACK, 1);
        cout << "Sending ACKs..." << endl;
        break;
    }
    case 3:
    {
        tcp.set_flag(TCP::FIN, 1);
        cout << "Sending FINs..." << endl;
        break;
    }
    case 5:
    {
        tcp.set_flag(TCP::FIN, 1);
        tcp.set_flag(TCP::URG, 1);
        tcp.set_flag(TCP::PSH, 1);
        cout << "Sending XMAS packets..." << endl;
        break;
    }
    }
    tcp.sport(randPort);
    for (set<uint16_t>::const_iterator it = ports_to_scan.begin(); it != ports_to_scan.end(); ++it)
    {
        tcp.dport(*it);
        sender.send(ip);
    }
    cout << "Waiting 2 seconds..." << endl;
    sleep(2);
    tcp.set_flag(TCP::RST, 1);
    tcp.sport(*ports_to_scan.begin());
    ip.src_addr(dest_ip);
    EthernetII eth = EthernetII(info.hw_addr, info.hw_addr) / ip;
    sender.send(eth, iface);
    sleep(1);
    sniffer.stop_sniff();
}

void Scanner::send_udps(const NetworkInterface &iface, IPv4Address dest_ip)
{
    // Retrieve the network interface information.
    NetworkInterface::Info info = iface.addresses();
    PacketSender sender;
    IP ip = IP(dest_ip, info.ip_addr) / UDP();
    // Get the reference to the UDP PDU
    UDP &udp = ip.rfind_pdu<UDP>();
    udp.sport(1000);

    cout << "Sending UDP packets..." << endl;
    for (set<uint16_t>::const_iterator it = ports_to_scan.begin(); it != ports_to_scan.end(); ++it)
    {
        if (*it != 53)
        { // Create random payload
            string payload = "Hello, this is a UDP packet!";
            RawPDU raw(payload);
            udp.inner_pdu(raw);
            udp.dport(*it);
            sender.send(ip);
        }
        else
        {
            // Send a DNS query to port 53
            DNS dns;
            dns.add_query(DNS::query("example.com", DNS::A, DNS::IN));
            dns.recursion_desired(true);
            udp.inner_pdu(dns); // Attach the DNS query to UDP
            udp.dport(*it);
            sender.send(ip);
        }
    }
    sleep(2);
    // Now send a special packet to a special port.
    udp.sport(1131);
    udp.dport(31337); // Special destination port, chosen for distinction.
    ip.src_addr(dest_ip);
    EthernetII eth = EthernetII(info.hw_addr, info.hw_addr) / ip;
    sender.send(ip);
    sleep(1);
    sniffer.stop_sniff();
}

void scan(const string &ip_address, const vector<int> &ports, int type)
{
    IPv4Address ip(ip_address);
    NetworkInterface iface(ip);
    cout << "Sniffing on interface: " << iface.name() << endl;
    Scanner scanner(type, iface, ip, ports);
    scanner.run(type);
}

int result()
{
    size_t total_ports = ports.size();
    size_t open_count = open_ports.size();
    size_t closed_count = closed_ports.size();
    size_t filtered_count = filtered_ports.size();
    size_t unfiltered_count = unfiltered_ports.size();

    // Create a vector to hold the counts and descriptions
    std::vector<std::pair<size_t, std::string>> counts = {
        {open_count, "open"},
        {closed_count, "closed"},
        {filtered_count, "filtered"},
        {unfiltered_count, "unfiltered"}};

    // Sort by count, largest to smallest
    std::sort(counts.begin(), counts.end(), [](const std::pair<size_t, std::string> &a, const std::pair<size_t, std::string> &b)
              {
                  return a.first > b.first; // Sorting in descending order
              });

    // Printing the largest status count
    // If all ports are in one status
    if (counts.front().first == total_ports)
    {
        std::cout << "All ports are " << counts.front().second << std::endl;
    }
    else if (counts.front().first > 0)
    {
        std::cout << "Most ports are " << counts.front().second << " with " << counts.front().first << " ports." << std::endl;
    }

    // Find the smallest non-zero count
    std::pair<size_t, std::string> smallest_non_zero = {0, ""};
    for (auto &count : counts)
    {
        if (count.first > 0)
        {
            smallest_non_zero = count;
        }
    }
    // Printing all ports for the smallest non-zero status
    if (smallest_non_zero.first > 0)
    {
        std::cout << "Few " << smallest_non_zero.second << " ports: ";
        const std::vector<int> *port_vector;
        if (smallest_non_zero.second == "open")
            port_vector = &open_ports;
        else if (smallest_non_zero.second == "closed")
            port_vector = &closed_ports;
        else if (smallest_non_zero.second == "filtered")
            port_vector = &filtered_ports;
        else
            port_vector = &unfiltered_ports;

        for (int port : *port_vector)
            std::cout << port << " ";
        std::cout << std::endl;
    }
    return 0;
}
int main()
{
    string ip_address;
    string input;
    unsigned short choice;
mainMenu:
    cout << "Host and Port Scanner\n";
    cout << "1. Scan Host(s)\n";
    cout << "2. Scan Port(s)\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        string ip_start, ip_end;
        int num_addresses;
        cout << "Enter the starting IP address: ";
        cin >> ip_start;
        cout << "Enter the ending IP address: ";
        cin >> ip_end;
        long int start = ipToLong(ip_start);
        long int end = ipToLong(ip_end);
        num_addresses = end - start + 1;
        IPv4Address ip(ip_start);
        for (int i = 0; i < num_addresses; i++)
        {
            hosts.push_back(ip);
            ip = next_ip(ip);
        }
        cout << "ICMP Echo Request Scan\n";
        scan(ip, hosts, 1);
        cout << "ICMP Echo Request Scan Results\n";

        for (auto &host : alive_hosts)
        {
            cout << host.to_string() << endl;
        }
        for (const auto &host : hosts)
        {
            // Check if the host is not in alive_hosts
            if (find(alive_hosts.begin(), alive_hosts.end(), host) == alive_hosts.end())
            {
                // Add to dead_hosts if not found in alive_hosts
                dead_hosts.push_back(host);
            }
        }
        alive_hosts.clear();
        scan(ip, dead_hosts, 2);
        if (alive_hosts.size() > 0)
        {
            cout << "ARP Scan Results, they might have firewall\n";
            for (auto &host : alive_hosts)
            {
                cout << host.to_string() << endl;
            }
        }
    }
    else if (choice == 2)
    {
        unsigned short type = 0;
        unsigned short portLow = 0, portHigh = 65535;
        unsigned short option;
        cout << "Enter IP address to scan: ";
        cin >> ip_address;
    type:
        cout << "1. Manual Entry\n2. Common Ports\n";
        cin >> option;
        if (option == 1)
        {
            cout << "Enter the port range to scan\n";
            cin >> portLow >> portHigh;
            unsigned int portNum = portHigh - portLow + 1;
            for (int i = portLow; i <= portHigh; i++)
            {
                ports.push_back(i);
            }
        }
        else if (option == 2)
        {
            ports = {20, 21, 22, 23, 25, 53, 80, 110, 111, 135, 139, 143, 443, 445, 587, 993, 995, 1026, 1433, 1521, 1723, 3306, 3389, 5432, 5900, 8080};
            portLow = 26, portHigh = 8080;
        }
        else
        {
            cout << "Invalid option\n";
            goto type;
        }
        cout << "1. SYN Scan\n";
        cout << "2. ACK Scan\n";
        cout << "3. FIN Scan\n";
        cout << "4. UDP Scan\n";
        cout << "5. XMAS Scan\n";
        cin >> type;
        if (type < 1 || type > 5)
        {
            cout << "Invalid type\n";
            goto type;
        }
        try
        {
            scan(ip_address, ports, type);
        }
        catch (runtime_error &ex)
        {
            cout << "Error - " << ex.what() << endl;
        }
        switch (type)
        {
        case 1:
        {
            result();
            break;
        }
        case 2:
        {
            for (int port = portLow; port <= portHigh; ++port)
            {
                if (std::find(unfiltered_ports.begin(), unfiltered_ports.end(), port) == unfiltered_ports.end())
                {
                    // 如果端口不在 unfiltered 中，添加到 filtered
                    filtered_ports.push_back(port);
                }
            }
            result();
            break;
        }
        case 4:
        {
            std::unordered_set<int> open_ports_set(open_ports.begin(), open_ports.end());
            std::unordered_set<int> closed_ports_set(closed_ports.begin(), closed_ports.end());

            for (int port : ports)
            {
                if (open_ports_set.find(port) == open_ports_set.end() &&
                    closed_ports_set.find(port) == closed_ports_set.end())
                {
                    closed_ports.push_back(port);
                }
            }
            result();
            break;
        }
        case 3:
        case 5:
        {
            result();
            break;
        }
        }
    }
    else if (choice == 3)
    {
        return 0;
    }
    else
    {
        cout << "Invalid choice\n";
        goto mainMenu;
    }
    return 0;
}
