TempStr=input("请输入带有符号的温度值：")
while TempStr[-1] not in ['N','n']:
    if TempStr[-1] in ['F','f']:
        C=(eval(TempStr[0:-1])+32)
        print("转换后的温度是{:.2f}C".format(C))
    elif TempStr[-1] in ['C','c']:
        F=1.8*eval(TempStr[0:-1])+32
        print("转换后的温度是{:.2f}F".format(F))
    else:
        print("输入的格式错误")
    TempStr=input("请输入带有符号的温度值：")
