# A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
#
# The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
#
# Now consider if some obstacles are added to the grids. How many unique paths would there be?
#
#
#
# An obstacle and empty space is marked as 1 and 0 respectively in the grid.
#
# Note: m and n will be at most 100.
#
# Example 1:
#
# Input:
# [
#   [0,0,0],
#   [0,1,0],
#   [0,0,0]
# ]
# Output: 2
# Explanation:
# There is one obstacle in the middle of the 3x3 grid above.
# There are two ways to reach the bottom-right corner:
# 1. Right -> Right -> Down -> Down
# 2. Down -> Down -> Right -> Right

# 分析：给定m x n矩阵，初始点在左上角，一次只能往右或往下移动一格，要到达右下角。在I的基础上，在网格中增加障碍物，问有多少条独立路径？
#
# 解法：与I的解法一样，构建dp矩阵，其中dp[i][j]表示当前位置的独立路径数目，则dp[i][j]=dp[i-1][j]+dp[i][j-1]。但是与I不同的是，这里
# 需要添加一个条件，就是当网格中g[i][j]中存在障碍（即值等于1时），dp[i][j]=0。
# 初始状态与I一样，同样地需要考虑前边所提出的条件。尤其是第一行和第一列的初始化，当前面有障碍物时，障碍物之后的一排或一列均应该为0.

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid) -> int:
        dp=[[1]*len(obstacleGrid[0]) for _ in range(len(obstacleGrid))]
        row=len(obstacleGrid)
        col=len(obstacleGrid[0])
        if row ==col==1:return 1 if obstacleGrid[0][0]==0 else 0

        for m in range(row):
            if obstacleGrid[m][0]==1:
                for i in range(m,row):
                    dp[i][0]=0
                break
        for n in range(col):
            if obstacleGrid[0][n]==1:
                for i in range(n,col):
                    dp[0][i]=0
                break

        for i in range(1,row):
            for j in range(1,col):
                dp[i][j]=dp[i-1][j]+dp[i][j-1] if obstacleGrid[i][j]==0 else 0
        return dp[-1][-1]
