f=open("test.txt","r+",encoding="utf-8")
f.write("你好！")
f.seek(0)
print(f.read())
f.close

