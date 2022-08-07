year=int(input("请输入年份："))
if year%4==0 and year%100!=0 and year%400==0:
    print("{}年是闰年！".format(year))
elif year%400==0:
    print("{}年是闰年！".format(year))
else:
    print("{}年不是闰年！".format(year))
