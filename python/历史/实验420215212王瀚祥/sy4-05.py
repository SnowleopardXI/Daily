n=int(input("请输入一个整数: "))
s=1
for i in range(1,n+1):
    s*=i
print("{}的阶乘为{}".format(n,s))
