def fib(n):
    if n==1 or n==2:
        return 1
    else:
        return fib(n-1)+fib(n-2)
n=eval(input("n="))
print("斐波那契数列中第{}项为{}".format(n,fib(n)))
