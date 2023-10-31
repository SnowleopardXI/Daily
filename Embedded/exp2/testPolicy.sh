#!/bin/bash

# 清空现有规则
iptables -F

# 设置默认策略为拒绝
iptables -P INPUT DROP
iptables -P OUTPUT DROP
iptables -P FORWARD DROP

# 允许与已建立或相关的连接的数据包
iptables -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT
iptables -A OUTPUT -m state --state ESTABLISHED,RELATED -j ACCEPT

# 允许 SSH 远程（通常是 TCP 端口 22）
iptables -A INPUT -p tcp --dport 22 -j ACCEPT

# 允许 Web 服务（通常是 TCP 端口 80 和 443）
iptables -A INPUT -p tcp --dport 80 -j ACCEPT