money=input("请输入带有符号的金额：")
while money[-1] not in ['N','n']:
    if money[-1] in ['D','d']:
        Y=6.4*eval (money[0:-1])
        print("折合人民币{:.2f}Y".format(Y))
    elif money[-1] in ['Y','y']:
        D=0.15625*eval(money[0:-1])
        print("折合美元{:.2f}D".format(D))
    else:
        print("输入的格式错误")
    money=input("请输入带有符号的金额：")
