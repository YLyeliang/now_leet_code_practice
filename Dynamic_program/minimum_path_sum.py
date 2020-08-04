# Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
#
# Note: You can only move either down or right at any point in time.
#
# Example:
#
# Input:
# [
#   [1,3,1],
#   [1,5,1],
#   [4,2,1]
# ]
# Output: 7
# Explanation: Because the path 1→3→1→1→1 minimizes the sum.

# 分析：给定 m x n矩阵，均为非负数，找到一个从左上往右下的路径，满足路径和的值最小。
# 该问题与unique_path类似，可以采用相同的思想。令路径矩阵为s,构建dp矩阵，其中dp[i][j]表示当前位置的最小路径和。考虑到当前位置只能从上方或左方到达。
# 那么动态转移方程可以是dp[i][j]=min(dp[i][j-1]+s[i][j],dp[i-1][j]+s[i][j])。
# 得到动态转移矩阵之后，初始化dp的状态。

class Solution:
    def minPathSum(self, grid) -> int:
        m,n=len(grid),len(grid[0])
        dp=[[0]*n for _ in range(m)]
        dp[0][0]=grid[0][0]
        if m==n==1:return dp[0][0]
        for j in range(1,n):
            dp[0][j] = dp[0][j - 1]+grid[0][j]
        for i in range(1,m):
            dp[i][0]=dp[i-1][0]+grid[i][0]
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=min(dp[i][j-1]+grid[i][j],dp[i-1][j]+grid[i][j])

        return dp[-1][-1]


