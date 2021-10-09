# -*- coding: utf-8 -*-

import random
import time
author='''Author: 3awallstudio--Steve Ephraim Adam
Contact: yjzawall@gmail.com
File: name.py
Time: 2021/10/09 12:58:01
Software: Visual Code'''

def err():
    print("输入错误")

listf=["20212556-王安诺","20212552-程佳梦","20212553-赖婷","20212559-许婧慧","20212555-孙海燕",
"20212558-王玮琪","20212560-赵城雪","20212554-刘烁宣","20212557-王春畅","20212561-周桂聪"]

listm=["20212531-国文赫","20205040-刘起瑞","20212539-马志远","20212536-林杰","20212540-彭林康",
"20212550-张宇龙","20212534-李会彬","20212533-李晨阳","20212546-徐子涵","20212542-王凯涵",
"20212543-吴拓","20212551-周浩然","20212547-阳冉升","20212545-徐率淇","20212529-郭家旗",
"20212544-肖天旭","20212549-张翔睿","20212530-郭晔","20212538-马润超","20212532-李长金",
"20212528-高宇","20212548-杨广毅","20212537-龙翔","20212541-曲成义","20212535-廖梓杰"]

listg=listf+listm
print(author)
print('请选择一个选项:')
menu='''
            1:全局随机
            2:性别分类随机
'''
m=int(eval(input(menu)))
if m==1:
    print("请输入随机抽取的人数：")
    n=int(input())
    if n>=1 and n<35:
        x=random.sample(listg,n)
        print(x)
    else:
        err()
else:
    if m==2:
        print('请分别输入男女生人数，以回车分割：')
        print('本班男生25名，女生10名')
        m=int(input())
        f=int(input())
        if m>1 and m<=25:
            print('抽取的男生为%d名，分别为：'%(m))
            x=random.sample(listm,m)
            print(x)
        else:
            err()
        if f>1 and f<=10:
            print('抽取的女生为%d名，分别为：'%(f))
            x1=random.sample(listf,f)
            print(x1)
        else:
            err()