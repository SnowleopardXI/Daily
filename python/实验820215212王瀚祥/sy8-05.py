score=int(input("请输入一个0~100之间的整数："))
grade=""
if score>100 or score<0:
    score=int(input("输入有误，请输入一个0~100之间的整数："))

else:
    if score>=90:
        grade="A"
    elif score>=80:
        grade="B"
    elif score>=70:
        grade="C"
    elif score>=60:
        grade="D"
    else:
        grade="E"
print("您的分数是{}，等级是{}".format(score,grade))
