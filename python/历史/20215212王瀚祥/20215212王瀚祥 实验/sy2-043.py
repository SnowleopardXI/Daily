str_n=input("请输入一个整数：")
n=eval(str_n)
m=0
while n!=0:
    r=n%10
    m=m*10+r
    n=n//10
if m ==eval(str_n):
    print("是回文数！")
else:
    print("不是回文数！")
