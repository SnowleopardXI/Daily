def power_x_n(x,n):
    s=1
    for i in range(n):
        s=s*x
    return s
x=int(input("请输入一个整数："))
n=int(input("请输入它的幂次："))

print("{}的{}次方为：{}".format(x,n,power_x_n(x,n)))
