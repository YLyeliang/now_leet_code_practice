import numpy as np

# 字典的遍历测试
# a={1:2,3:4,5:6}
#
# if 1 in a.keys():
#     print(a[0])
#
# for i in a.items():
#     print(i)

# 语法中 and的测试
num1=3
num2=4
num1=num2
num2=num1+num2

root=123
q=root and [root] # equals to  q= [root] if root else None or False(depends on root)
print(q)

a=[1,2,3,4,5]
print([b for b in a])
print(a.__len__())

print("{}")
