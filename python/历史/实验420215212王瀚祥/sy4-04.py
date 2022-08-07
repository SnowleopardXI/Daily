num1=int(input("请输入第一个数字："))
num2=int(input("请输入第二个数字："))
m=max(num1,num2)
n=min(num1,num2)
r=m%n
while r!=0:
    m=0
    n=r
    r=m%n
print(num1,"和",num2,"的最大公约数为：",n)
print(num1,"和",num2,"的最大公倍数为：",num1*num2//n)
