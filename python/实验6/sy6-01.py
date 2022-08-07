nums = []
iNumStr = input("请输入数字(直接输入回车退出): ")
while iNumStr != ""      :
    nums.append(eval(iNumStr))
    iNumStr = input("请输入数字(直接输入回车退出): ")
s = 0.0    
for i in nums :
    s = s + i
print("平均值为{:.2f}".format(s/len(nums)))
print("最大值为{}".format(max(nums)))
