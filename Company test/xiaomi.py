# arr=list(map(int,input().split()))
# max_num = arr[0]
# temp = arr[0]
# for i in range(1,len(arr)):
#     temp=max(temp+arr[i],arr[i])
#     max_num=max(max_num,temp)
#
# print(max_num)



price=list(map(int,input().split()))
n=len(price)
profit=[[0]*n for i in range(3)]
for k in range(1,3):
    pre_max=-price[0]
    for i in range(1,n):
        pre_max=max(pre_max,profit[k-1][i-1]-price[i])
        profit[k][i]=max(profit[k][i-1],price[i]+pre_max)

print(profit[-1][-1])