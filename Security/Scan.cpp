#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>
#include <tins/tins.h>

#define randPort 1541
using namespace std;
using namespace Tins;

typedef pair<Sniffer *, string> sniffer_data;
bool response_received = false;
vector<int> open_ports;
vector<int> closed_ports;
vector<int> filtered_ports;
vector<int> unfiltered_ports;
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
    IPv4Address local_ip;
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
    bool stop_sniffing = false;
    int timeout = 1000; // timeout in milliseconds

    while (!stop_sniffing)
    {
        auto start_time = std::chrono::steady_clock::now();
        std::cout << "Sniffing..." << std::endl;

        // 使用try和catch捕获可能的异常
        try
        {
            sniffer.sniff_loop([this, &stop_sniffing, start_time, timeout](PDU &pdu)
                               {
                    this->callback(pdu);
                    if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count() >= timeout) {
                        stop_sniffing = true; // 设置标志停止嗅探
                        return false; // 通知sniff_loop停止
                    }
                    return true; });
        }
        catch (const std::exception &e)
        {
            std::cerr << "Sniffing error: " << e.what() << std::endl;
            break; // 出错时退出循环
        }

        // 在循环末尾再次检查超时以确保停止
        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count() >= timeout)
        {
            stop_sniffing = true;
        }
    }

    // 外部停止嗅探
    sniffer.stop_sniff();
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
                if (tcp.get_flag(TCP::SYN))
                    closed_ports.push_back(tcp.sport());
                else
                    filtered_ports.push_back(tcp.sport());
            }
            // Is SYN flag on? Then port is open!
            else if (tcp.flags() == (TCP::SYN | TCP::ACK))
            {
                open_ports.push_back(tcp.sport());
            }
            return false;
        }
        if (this->type == 2)
        {
            if (tcp.get_flag(TCP::RST))
            {
                unfiltered_ports.push_back(tcp.sport());
            }
            else
            {
                filtered_ports.push_back(tcp.sport());
            }
            false;
        }
        if (this->type == 3)
        {
            if (tcp.get_flag(TCP::RST) && !tcp.get_flag(TCP::FIN))
            {
                closed_ports.push_back(tcp.sport());
            }
            else
            {
                open_ports.push_back(tcp.sport());
            }
            return false;
        }
        if (this->type == 4)
        {
            // If we receive an ICMP error, the port is closed.
            if (ip.protocol() == IPPROTO_ICMP)
            {
                cout << "Port: " << setw(5) << tcp.sport() << " closed\n";
            }
            else
            {
                cout << "Port: " << setw(5) << tcp.sport() << " open or filtered\n";
            }
            return false;
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
    NetworkInterface::Info info = iface.addresses();
    PacketSender sender;
    // IP PDU
    IP ip = IP(dest_ip, info.ip_addr) / TCP();
    TCP &tcp = ip.rfind_pdu<TCP>();

    tcp.set_flag(TCP::SYN, 1);
    tcp.sport(randPort);
    cout << "Sending SYNs..." << endl;
    for (set<uint16_t>::const_iterator it = ports_to_scan.begin(); it != ports_to_scan.end(); ++it)
    {
        tcp.dport(*it);
        sender.send(ip);
    }
    sleep(1);
    tcp.set_flag(TCP::RST, 1);
    tcp.sport(*ports_to_scan.begin());
    ip.src_addr(dest_ip);
    EthernetII eth = EthernetII(info.hw_addr, info.hw_addr) / ip;
    sender.send(eth, iface);
}

// Send acks to the given ip address, using the destination ports provided.
void Scanner::send_acks(const NetworkInterface &iface, IPv4Address dest_ip)
{
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

IPv4Address next_ip(const IPv4Address &ip)
{
    uint32_t ip_int = ip;
    ip_int = htonl(ntohl(ip_int) + 1); // Network byte order adjustment
    return IPv4Address(ip_int);
}

bool icmp_callback(PDU &pdu)
{
    const IP &ip = pdu.rfind_pdu<IP>();
    if (ip.inner_pdu()->pdu_type() == PDU::ICMP)
    {
        const ICMP &icmp = pdu.rfind_pdu<ICMP>();
        if (icmp.type() == ICMP::ECHO_REPLY)
        {
            cout << "ICMP Echo Reply from " << ip.src_addr() << endl;
            response_received = true;
            return false;
        }
        if (icmp.type() == ICMP::DEST_UNREACHABLE)
        {
            response_received = false;
            return false;
        }
    }
    return true;
}

void icmp_scan(const string &ip_start, int num_addresses)
{
    NetworkInterface iface = NetworkInterface::default_interface();
    NetworkInterface::Info info = iface.addresses();
    PacketSender sender;

    IPv4Address ip(ip_start);

    for (int i = 0; i < num_addresses; i++)
    {
        response_received = false;
        for (int attempt = 0; attempt < 3 && !response_received; attempt++)
        {
            IP packet = IP(ip, info.ip_addr) / ICMP();
            sender.send(packet);
            if (attempt == 0)
                cout << "Pinging " << ip << ", attempt " << attempt + 1 << " ";
            else
                cout << attempt + 1 << " ";
            Sniffer sniffer(iface.name());
            sniffer.sniff_loop(icmp_callback);
            std::atomic<bool> stop_sniffing{false};

            // 启动超时控制线程
            std::thread timeout_thread([&]()
                                       {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                stop_sniffing = true;
                sniffer.stop_sniff(); });

            sniffer.sniff_loop([&](PDU &pdu)
                               { return icmp_callback(pdu) && !stop_sniffing.load(); });

            // 确保超时线程已完成
            if (timeout_thread.joinable())
            {
                timeout_thread.join();
            }

            if (response_received)
            {
                break;
            }
        }

        if (!response_received)
        {
            cout << "No response after 3 attempts for " << ip << endl;
        }

        ip = next_ip(ip); // 正确增加 IP 地址
    }
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
        num_addresses = stoi(ip_end.substr(ip_end.find_last_of('.') + 1)) - stoi(ip_start.substr(ip_start.find_last_of('.') + 1)) + 1;
        icmp_scan(ip_start, num_addresses);
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
        unsigned int portNum = portHigh - portLow + 1;
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
        if (type == 1 || type == 3)
        {
            if (open_ports.size() == 0)
            {
                cout << "Possible no open ports\n";
            }
            else
            {
                cout << "Open ports: ";
                for (int i = 0; i < open_ports.size(); i++)
                {
                    cout << open_ports[i] << " ";
                }
                cout << endl;
            }
            if (closed_ports.size() > 0)
            {
                cout << "Closed ports: ";
                for (int i = 0; i < closed_ports.size(); i++)
                {
                    cout << closed_ports[i] << " ";
                }
                cout << endl;
            }
        }
        else if (type == 2)
        {
            if (filtered_ports.size() == 0 || unfiltered_ports.size() == 0)
            {
                if (filtered_ports.size() == 0)
                {
                    cout << "All ports are unfiltered\n";
                }
                else
                {
                    cout << "All ports are filtered\n";
                }
            }
            else
            {
                cout << "Filtered ports: ";
                for (int i = 0; i < filtered_ports.size(); i++)
                {
                    cout << filtered_ports[i] << " ";
                }
                cout << endl;
                cout << "Unfiltered ports: ";
                for (int i = 0; i < unfiltered_ports.size(); i++)
                {
                    cout << unfiltered_ports[i] << " ";
                }
                cout << endl;
            }
        }
        else if (type == 4)
        {
            cout << "UDP scan completed\n";
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