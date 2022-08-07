#sy3-04.py计算存款复利终值
money=eval(input("请输入存款金额（万元）："))
n=eval(input("请输入存款年限（年）："))
if n<5:
    money=money*(1+0.03)**n
elif n>=5 and n<8:
    money=money*(1+0.05)**n
elif n>8:
    money=money*(1+0.07)**n
else:
    print("年份错误！")
print("{}年后，复利终值为{:.2f}万元".format(n,money))
