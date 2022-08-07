str_n=input("请输入一个整数：")
N=len(str_n)
for i in range(N//2):
    if str_n[i]!=str_n[N-1-i]:
        print("是回文数！")
        break
else:
    print("不是回文数！")
