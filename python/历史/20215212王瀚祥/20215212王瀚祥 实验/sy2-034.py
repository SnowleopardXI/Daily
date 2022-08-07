x=eval(input("请输入x的值："))
n=eval(input("请输入n的值："))
s=1
for i in range(n):
    s=s*x
print("{}的{}次方是：{}".format(x,n,s))
