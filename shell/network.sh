#!/bin/bash

#####################################################################
#本脚本放于主机，使用定时任务检测192.168.18.1是否网络畅通，如果不通则警告所有用户即将关机
#本脚本只能检测一个ip是否网络断开，可在开始部分加个循环，检测多个ip

####################################################################################

#初始化环境变量

source /root/.bash_profile

ping=`ping -c 10 192.168.18.1|awk 'NR==7 {print $4}'`

#如果十次均没ping通，则做以下操作

if [ $ping -eq 0 ]

then

wall "System will go down in 5 minutes due to network or power issue"
wall "Please execute commands in maintenance manual with administrative permission"

sleep 300

if [ $ping -eq 0 ]
then init 0
fi

fi