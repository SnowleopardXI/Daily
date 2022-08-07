year=int(input("请输入年份,输入0结束："))
while year!=0:
    if(year%4==0 and year%100!=0)or(year%400==0):
        print("{}年是闰年！".format(year))
    elif year==0:
        break
    else:
        print("{}年不是闰年".format(year))
    year=int(input("请输入年份,输入0结束："))
