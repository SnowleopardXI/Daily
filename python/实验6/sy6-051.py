def fib(n):
    a=0
    b=1
    for i in range(n):
        a,b=b,a+b
    return a
n=eval(input("n="))
print("斐波那契数列中第{}项为{}".format(n,fib(n)))
