
s=str(input("输入一个字符串："))
a = {}
for i in s:
    a[i] = a.get(i,0)+1
print(a)