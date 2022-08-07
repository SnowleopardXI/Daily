sum=0
for i in range(2,50):
    for j in range(2,i):
        if i%j==0:
            break
    else:
        sum+=i
        print(i,end=" ")
print("\n","前50素数的和为:{}".format(sum))




