f=open("out.txt","w+")
f.write('Python')
f.seek(0)
c=f.read(2)
print(c)
f.close()
