score=eval(input("请输入成绩："))
if score>=60 and score<70:
    grade='D'
elif score>=70 and score<80:
    grade='C'
elif score>=80 and score<90:
    grade='B'
elif score>=90:
    grade='A'
else:
    grade='E'
print(grade)
