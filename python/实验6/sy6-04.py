import random
list1=[]
for i in range(10):
    x=random.randint(10,99)
    list1.append(x)     
print("产生的数：",list1)
print("平均值：{}".format(sum(list1)/len(list1)))
