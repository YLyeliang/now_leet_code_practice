
# 最长升序子序列
# arr=list(map(int,input().split(',')))
# l=len(arr)
# dp=[0 for i in range(l)]
# dp[0]=1
# submax=0
# for i in range(1,l):
#     sublong=0
#     for j in range(0,i):
#         if arr[j]<=arr[i]:
#             sublong=max(dp[j],sublong)
#     dp[i]=sublong+1
#     submax=max(dp[i],submax)
# print(submax)

# N*M的矩阵，每个数字表示海拔高度，第一行可以建造蓄水厂，可以往邻近城市送水，
# 但是只能往海拔低于它的相邻城市送水，依次送，必须所有城市都能送到水，
# 求建造蓄水厂的最少数量，否则输出0，并告知干旱区中不可能有水的城市数。
# 最后一行为干旱区
n, m = list(map(int, input().split()))
height = []
for i in range(n):
    tmp = list(map(int, input().split()))
    height.append(tmp)

max_id=[]
for i in range(m):
    if height[0][m]>height[m+1]:


dp=[[]]



