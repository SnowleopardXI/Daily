#include <bits/stdc++.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
#define ICMP_ECHO 8
#define ICMP_REPLY 0
// IP <-> int 转换
uint32_t ip_to_int(const string &ip)
{
    struct sockaddr_in sa;
    inet_pton(AF_INET, ip.c_str(), &(sa.sin_addr));
    return ntohl(sa.sin_addr.s_addr);
}

string int_to_ip(uint32_t ip)
{
    struct in_addr ip_addr;
    ip_addr.s_addr = htonl(ip);
    return inet_ntoa(ip_addr);
}

struct icmp_hdr
{
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t id;
    uint16_t sequence;
};

unsigned short checksum(void *b, int len)
{
    unsigned short *buf = (unsigned short *)b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}
#include <mutex>

// 全局互斥锁用于同步对available_ips的访问
std::mutex available_ips_mutex;

// 发送ICMP Echo请求并接收回复的函数
std::future<void> async_ping(const std::string &target_ip, std::vector<std::string> &available_ips)
{
    return std::async(std::launch::async, [target_ip, &available_ips]()
                      {
        int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
        if (sockfd < 0) {
            perror("Socket creation failed");
            return;
        }

        struct sockaddr_in dest_addr;
        dest_addr.sin_family = AF_INET;
        inet_pton(AF_INET, target_ip.c_str(), &dest_addr.sin_addr);

        // 构造ICMP Echo请求
        icmp_hdr icmp_packet;
        memset(&icmp_packet, 0, sizeof(icmp_packet));
        icmp_packet.type = ICMP_ECHO;
        icmp_packet.code = 0;
        icmp_packet.checksum = 0;
        icmp_packet.id = htons(1000);  // Arbitrary ID
        icmp_packet.sequence = htons(1);  // Sequence number
        icmp_packet.checksum = checksum(&icmp_packet, sizeof(icmp_packet));

        // 发送ICMP Echo请求
        if (sendto(sockfd, &icmp_packet, sizeof(icmp_packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) <= 0) {
            perror("Ping failed");
            close(sockfd);
            return;
        }

        // 接收ICMP Echo回复
        char buffer[1024];
        struct sockaddr_in from;
        socklen_t fromlen = sizeof(from);
        // Only accept ICMP packets from the target IP
        while (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&from, &fromlen) > 0) {
            if (from.sin_addr.s_addr == dest_addr.sin_addr.s_addr) {
                // Add the target IP to the list of available IPs
                std::lock_guard<std::mutex> lock(available_ips_mutex);
                available_ips.push_back(target_ip);
                break;
            }
        }
        
        close(sockfd); 
        });
}

int main()
{
    vector<string> ips, available_ips;
    vector<future<void>> futures;

    string ipStart, ipEnd;
    unsigned short netmask;
start:
    cout << "Enter IP Range (Start): ";
    cin >> ipStart;
    cout << "Enter IP Range (End): ";
    cin >> ipEnd;
    cout << "Enter IP netmask: ";
    cin >> netmask;
    // Generate IP pool
    uint32_t start = ip_to_int(ipStart);
    uint32_t end = ip_to_int(ipEnd);
    if (start > end)
    {
        cout << "Invalid IP range" << endl;
        goto start;
    }
    if (netmask > 32)
    {
        cout << "Invalid netmask" << endl;
        goto start;
    }
    if (start == end)
    {
        ips.push_back(int_to_ip(start));
    }

    for (uint32_t addr = start; addr <= end; addr++)
    {
        ips.push_back(int_to_ip(addr));
    }
    for (const auto &ip : ips)
    {
        futures.emplace_back(async_ping(ip, available_ips));
    }
    // 等待所有异步操作完成
    for (auto &f : futures)
    {
        f.get();
    }

    cout << "Available IPs:" << endl;
    for (const auto &ip : available_ips)
    {
        cout << ip << endl;
    }

    return 0;
}
