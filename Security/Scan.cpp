#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>
#include <tins/tins.h>

#define randPort 1541
using namespace std;
using namespace Tins;

typedef pair<Sniffer *, string> sniffer_data;

class Scanner
{
public:
    Scanner(int type,
            const NetworkInterface &interface,
            const IPv4Address &address,
            const vector<string> &ports);

    void run(int type);

private:
    int type;
    void send_syns(const NetworkInterface &iface, IPv4Address dest_ip);
    void send_acks(const NetworkInterface &iface, IPv4Address dest_ip);
    void send_fins(const NetworkInterface &iface, IPv4Address dest_ip);
    void send_udps(const NetworkInterface &iface, IPv4Address dest_ip);
    bool callback(PDU &pdu);
    static void *thread_proc(void *param);
    void launch_sniffer();

    NetworkInterface iface;
    IPv4Address host_to_scan;
    set<uint16_t> ports_to_scan;
    Sniffer sniffer;
};
Scanner::Scanner(int type,
                 const NetworkInterface &interface,
                 const IPv4Address &address,
                 const vector<string> &ports)
    : iface(interface), host_to_scan(address), sniffer(interface.name())
{
    this->type = type;
    sniffer.set_filter(
        "tcp and ip src " + address.to_string() + " and tcp[tcpflags] & (tcp-rst|tcp-syn) != 0");
    for (size_t i = 0; i < ports.size(); ++i)
    {
        ports_to_scan.insert(atoi(ports[i].c_str()));
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
    sniffer.sniff_loop(make_sniffer_handler(this, &Scanner::callback));
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
            if (tcp.get_flag(TCP::RST))
            {
                // This indicates we should stop sniffing.
                if (tcp.get_flag(TCP::SYN))
                    return false;
                cout << "Port: " << setw(5) << tcp.sport() << " closed\n";
            }
            // Is SYN flag on? Then port is open!
            else if (tcp.flags() == (TCP::SYN | TCP::ACK))
            {
                cout << "Port: " << setw(5) << tcp.sport() << " open\n";
            }
        }
        if (this->type == 2)
        {
            if (tcp.get_flag(TCP::RST))
            {
                cout << "Port: " << setw(5) << tcp.sport() << " unfiltered\n";
                return false;
            }
            else
                cout << "Port: " << setw(5) << tcp.sport() << " filtered\n";
        }
        if (this->type == 3)
        {
            if (tcp.get_flag(TCP::RST))
            {
                cout << "Port: " << setw(5) << tcp.sport() << " closed\n";
            }
            else
            {
                cout << "Port: " << setw(5) << tcp.sport() << " open , filtered\n";
                return false;
            }
            return true;
        }
        if (this->type == 4)
        {
            // UDP scan
            // If we receive an ICMP error, the port is closed.
            if (ip.protocol() == IPPROTO_ICMP)
            {
                cout << "Port: " << setw(5) << tcp.sport() << " closed\n";
            }
            else
            {
                cout << "Port: " << setw(5) << tcp.sport() << " open or filtered\n";
            }
        }
    }
    return true;
}

void Scanner::run(int type)
{
    pthread_t thread;
    this->type = type;
    // Launch our sniff thread.
    pthread_create(&thread, 0, &Scanner::thread_proc, this);
    // Start sending SYNs to port.
    if (type == 1)
    {
        send_syns(iface, host_to_scan);
    }
    else if (type == 2)
    {
        send_acks(iface, host_to_scan);
    }
    else if (type == 3)
    {
        send_fins(iface, host_to_scan);
    }
    else if (type == 4)
    {
        send_udps(iface, host_to_scan);
    }
    // Wait for our sniffer.
    void *dummy;
    pthread_join(thread, &dummy);
}

// Send syns to the given ip address, using the destination ports provided.
void Scanner::send_syns(const NetworkInterface &iface, IPv4Address dest_ip)
{
    // Retrieve the addresses.
    NetworkInterface::Info info = iface.addresses();
    PacketSender sender;
    // Allocate the IP PDU
    IP ip = IP(dest_ip, info.ip_addr) / TCP();
    // Get the reference to the TCP PDU
    TCP &tcp = ip.rfind_pdu<TCP>();
    // Set the SYN flag on.
    tcp.set_flag(TCP::SYN, 1);
    // Just some random port.
    tcp.sport(randPort);
    cout << "Sending SYNs..." << endl;
    for (set<uint16_t>::const_iterator it = ports_to_scan.begin(); it != ports_to_scan.end(); ++it)
    {
        // Set the new port and send the packet!
        tcp.dport(*it);
        sender.send(ip);
    }
    // Wait 1 second.
    sleep(1);
    /* Special packet to indicate that we're done. This will be sniffed
     * by our function, which will in turn return false.
     */
    tcp.set_flag(TCP::RST, 1);
    tcp.sport(*ports_to_scan.begin());
    // Pretend we're the scanned host...
    ip.src_addr(dest_ip);
    // We use an ethernet pdu, otherwise the kernel will drop it.
    EthernetII eth = EthernetII(info.hw_addr, info.hw_addr) / ip;
    sender.send(eth, iface);
}

// Send acks to the given ip address, using the destination ports provided.
void Scanner::send_acks(const NetworkInterface &iface, IPv4Address dest_ip)
{
    // Timeout of each packet is 10 seconds.
    NetworkInterface::Info info = iface.addresses();
    PacketSender sender;
    // Allocate the IP PDU
    IP ip = IP(dest_ip, info.ip_addr) / TCP();
    TCP &tcp = ip.rfind_pdu<TCP>();
    tcp.set_flag(TCP::ACK, 1);
    tcp.sport(randPort);
    cout << "Sending ACKs..." << endl;
    for (set<uint16_t>::const_iterator it = ports_to_scan.begin(); it != ports_to_scan.end(); ++it)
    {
        tcp.dport(*it);
        sender.send(ip);
    }
    // Wait 1 second.
    sleep(1);
    tcp.set_flag(TCP::RST, 1);
    tcp.sport(*ports_to_scan.begin());
    // Pretend we're the scanned host...
    ip.src_addr(dest_ip);
    // We use an ethernet pdu, otherwise the kernel will drop it.
    EthernetII eth = EthernetII(info.hw_addr, info.hw_addr) / ip;
    sender.send(eth, iface);
}

// Send fins to the given ip address, using the destination ports provided.
void Scanner::send_fins(const NetworkInterface &iface, IPv4Address dest_ip)
{
    NetworkInterface::Info info = iface.addresses();
    PacketSender sender;
    // Allocate the IP PDU
    IP ip = IP(dest_ip, info.ip_addr) / TCP();
    TCP &tcp = ip.rfind_pdu<TCP>();
    tcp.set_flag(TCP::FIN, 1);
    tcp.sport(randPort);
    cout << "Sending FINs..." << endl;
    for (set<uint16_t>::const_iterator it = ports_to_scan.begin(); it != ports_to_scan.end(); ++it)
    {
        tcp.dport(*it);
        sender.send(ip);
    }
    // Wait 1 second.
    sleep(1);
    tcp.set_flag(TCP::RST, 1);
    tcp.sport(*ports_to_scan.begin());
    // Pretend we're the scanned host...
    ip.src_addr(dest_ip);
    // We use an ethernet pdu, otherwise the kernel will drop it.
    EthernetII eth = EthernetII(info.hw_addr, info.hw_addr) / ip;
    sender.send(eth, iface);
}

// Send udps to the given ip address, using the destination ports provided.
void Scanner::send_udps(const NetworkInterface &iface, IPv4Address dest_ip)
{
    NetworkInterface::Info info = iface.addresses();
    PacketSender sender;
    // Allocate the IP PDU
    IP ip = IP(dest_ip, info.ip_addr) / UDP();
    UDP &udp = ip.rfind_pdu<UDP>();
    udp.sport(randPort);
    cout << "Sending UDPs..." << endl;
    for (set<uint16_t>::const_iterator it = ports_to_scan.begin(); it != ports_to_scan.end(); ++it)
    {
        udp.dport(*it);
        sender.send(ip);
    }
    // Wait 1 second.
    sleep(1);
    // Pretend we're the scanned host...
    ip.src_addr(dest_ip);
    // We use an ethernet pdu, otherwise the kernel will drop it.
    EthernetII eth = EthernetII(info.hw_addr, info.hw_addr) / ip;
    sender.send(eth, iface);
}

void scan(const string &ip_address, const vector<string> &ports, int type)
{
    IPv4Address ip(ip_address);
    NetworkInterface iface(ip);
    cout << "Sniffing on interface: " << iface.name() << endl;
    Scanner scanner(type, iface, ip, ports);
    scanner.run(type);
}

bool icmp_callback(const PDU& pdu) {
    const IP& ip = pdu.rfind_pdu<IP>();
    const ICMP& icmp = pdu.rfind_pdu<ICMP>();
    if (icmp.type() == ICMP::ECHO_REPLY) {
        cout << "Received reply from: " << ip.src_addr() << endl;
    }
    return true;
}

void icmp_scan(const string& ip_start, int num_addresses) {
    NetworkInterface iface = NetworkInterface::default_interface();
    NetworkInterface::Info info = iface.addresses();
    PacketSender sender;
    
    for (int i = 1; i <= num_addresses; ++i) {
        IPv4Address dest(ip_start + "." + to_string(i));
        IP ip = IP(dest, info.ip_addr) / ICMP(ICMP::ECHO_REQUEST, 0);
        ip.ttl(64);
        sender.send(ip, iface);
    }
    
    SnifferConfiguration config;
    config.set_filter("icmp and icmp[type] == icmp-echoreply");
    config.set_timeout(10); // Timeout in seconds
    Sniffer sniffer(iface.name(), config);
    sniffer.sniff_loop(icmp_callback);
}

int main()
{
    string ip_address;
    vector<string> ports;
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
        string ip_start, ip_end, prefix;
        int num_addresses;
        cout << "Enter the starting IP address: ";
        cin >> ip_start;
        cout << "Enter the ending IP address: ";
        cin >> ip_end;
        cout << "Enter the prefix: ";
        cin >> prefix;
        cout << "Scanning " << ip_start << " to " << ip_end << endl;
        num_addresses = stoi(ip_end.substr(ip_end.find_last_of('.') + 1)) - stoi(ip_start.substr(ip_start.find_last_of('.') + 1)) + 1;
        icmp_scan(prefix + ip_start, num_addresses);
    }
    else if (choice == 2)
    {
        unsigned short type = 0;
    type:
        unsigned short portLow = 0, portHigh = 65535;
        cout << "Enter IP address to scan: ";
        cin >> ip_address;
        cout << "Enter port range to scan: ";
        cin >> portLow >> portHigh;
        for (int i = portLow; i <= portHigh; i++)
        {
            ports.push_back(to_string(i));
        }
        cout << "1. SYN Scan\n";
        cout << "2. ACK Scan\n";
        cout << "3. FIN Scan\n";
        cout << "4. UDP Scan\n";
        cin >> type;
        if (type < 1 || type > 4)
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