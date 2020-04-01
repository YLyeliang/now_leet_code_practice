# 给定一个包含非负整数的 m x n 网格，
# 请找出一条从左上角到右下角的路径，
# 使得路径上的数字总和为最小。（机器人只能向下或向右走）
class walking(object):
    def __init__(self,arr):
        self.arr=arr
        self.m=len(arr)
        self.n=len(arr[0])

    def run(self):
        arr=self.arr
        m=self.m
        n=self.n
        if m <= 0 or n <= 0:
            return False
        dp=[[0]*n for _ in range(m)]
        dp[0][0]=arr[0][0]
        # initialize the left column
        for i in range(1,m):
            dp[i][0]=dp[i-1][0]+arr[i][0]
        # initialize the top row
        for i in range(1,n):
            dp[0][i]=dp[0][i-1]+arr[0][i]
        # inference the dp m-1 n-1
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+arr[i][j]
        return dp[m-1][n-1]

solver=walking([[1,3,1],[1,5,1],[4,2,1]])
print(solver.run())





