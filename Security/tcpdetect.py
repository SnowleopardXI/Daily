import socket

def check_port(ip, port):
    socket.setdefaulttimeout(1)  # 设置默认超时时间
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # 创建TCP socket
    try:
        s.connect((ip, port))  # 尝试连接
        print(f"Port {port} is open on {ip}.")
    except socket.error as err:
        print(f"Port {port} is closed or not reachable on {ip}. Error: {err}")
    finally:
        s.close()  # 关闭socket连接

ip_address = '10.40.172.1' 
port_number = 6901 

check_port(ip_address, port_number)
