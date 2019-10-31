# 有n个保温箱，每个保温箱装有一定货物ai,保温箱最大容量bi，
# 在最短时间内用最少的保温箱将货物装好，转移一个货物花费时间1秒.
# 输入
# 第一行：整数n,保温箱数量
# 第二行：n个正整数,a1,a2....表示第i个保温箱已有货物
# 第三行：n个正整数,b1,b2...表示第i个保温箱容积，ai<=bi

n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
# n=4
# a=[3,3,4,3]
# b=[4,7,6,5]
mask_b=b.copy()
mask_b.sort(reverse = True)
a_sum=sum(a)
for i in range(len(mask_b)):
    if sum(mask_b[:i+1])==a_sum:
        index=[b.index(j) for j in mask_b[:i+1]]
        count=i+1
        break
seconds=0
for id in index:
    seconds+=b[id]-a[id]
out=[str(count)]+[str(seconds)]
out=" ".join(out)
print(out)


