score={"Mary":87,"Tom":42,"Amy":98,"Gavin":100,"Paul":77}
m = 'Mary'
for key in score.keys():
    if score[m] < score[key]:
         m = key      
print("成绩最高的学生为{}，成绩为{}".format(m,score[m]))
