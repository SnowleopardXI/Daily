# coding:utf-8
# 传入数据库
import json
import time
import hashlib
import pymysql
import requests


# 获取时间戳
def getTime():
    return str(int(time.time()))


# 通用预约
def common_order(username, password, bookstatusid,token,loginid):
    
    # 登录获取token
    body={'password':hashlib.md5(str(password).encode()).hexdigest(),
        'code':username}
    loginURL = 'http://ligong.deshineng.com:8082/brmclg/api/logon/login'

    timestamp = getTime()
    headers = {
        "Accept": "application/json, text/javascript, */*; q=0.01",
        "Accept-Encoding": "gzip, deflate",
        "Accept-Language": "en-US,en;q=0.9",
        "Connection": "keep-alive",
        "Content-Length": "65",
        "Content-Type": "application/json",
        "Host": "ligong.deshineng.com:8082",
        "Origin": "http://ligong.deshineng.com:8082",
        "Referer": "http://ligong.deshineng.com:8082/brmclg/login.html?v=12&func=null&sn=null",
        "User-Agent": "Mozilla/5.0 (iPhone; CPU iPhone OS 16_0 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/16.0 Mobile/15E148 Safari/604.1",
        "X-Requested-With": "XMLHttpRequest",
        }
    login = requests.post(loginURL + "?time=" + timestamp, json=body, headers=headers)
    if login.status_code == 200:
        temp=(login.json()).get('data')
        token=str(temp.get('token'))#获取token
        loginid=str(temp.get('loginid'))#获取登录id
    else:
        print(f"{username}登录失败,预约失败")
    # 预约
    headers = {
        'token': token,
        'loginid': loginid,
        'Content-Type': 'application/json;charset=UTF-8'
    }
    payload = json.dumps({})
    timestamp = getTime()
    bookURL = 'http://ligong.deshineng.com:8082/brmclg/api/bathRoom/bookOrder' + "?time=" + timestamp + "&bookstatusid=" + bookstatusid
    bookURL = requests.request("POST", bookURL, headers=headers, data=payload)
    if bookURL.status_code == 200:
        if bookURL.json()['data']['succeed'] == 'Y':
            print(f"{username}预约成功")
        if bookURL.json()['data']['succeed'] == 'Q':
            print(f"{username}重复预约")
    else:
        with open('/home/ESMicaiah/out.txt', 'a+', encoding='utf-8') as f:
            print(f"{username}预约失败", file=f)
        print(f"{username}预约失败")

def fast_book(username, password, bookstatusid,token,loginid):
    # 预约
    headers = {
        'token': token,
        'loginid': loginid,
        'Content-Type': 'application/json;charset=UTF-8'
    }
    payload = json.dumps({})
    timestamp = getTime()
    bookURL = 'http://ligong.deshineng.com:8082/brmclg/api/bathRoom/bookOrder' + "?time=" + timestamp + "&bookstatusid=" + bookstatusid
    bookURL = requests.request("POST", bookURL, headers=headers, data=payload)
    if bookURL.status_code == 200:
        if bookURL.json()['data']['succeed'] == 'Y':
            print(f"{username}预约成功")
        if bookURL.json()['data']['succeed'] == 'Q':
            print(f"{username}重复预约")
    else:
        with open('/home/ESMicaiah/out.txt', 'a+', encoding='utf-8') as f:
            print(f"{username}预约失败", file=f)
        print(f"{username}预约失败")

# 查询数据库
conn = pymysql.connect(host='127.0.0.1', port=3306, user='bath', password='bathroom',
                       database='bathroom', charset='utf8')
cursor = conn.cursor(cursor=pymysql.cursors.DictCursor)
print(cursor)
# 定义SQL语句
sql = "SELECT * FROM orderUserList;"
# 执行SQL语句
cursor.execute(sql)
conn.commit()
# 游标对象关闭
searchList = cursor.fetchall()
cursor.close()
# 关闭连接
conn.close()

# 执行预约操作
for i in searchList:
    #common_order(i['username'],i['password'],i['bookstatusid'],i['token'],i['loginid'])
    fast_book(i['username'],i['password'],i['bookstatusid'],i['token'],i['loginid'])
