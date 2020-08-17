# Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
#
# Example:
#
# Input:
#
# 1 0 1 0 0
# 1 0 1 1 1
# 1 1 1 1 1
# 1 0 0 1 0
#
# Output: 4

# 问题:给定二维二进制矩阵，找到只包含1的最大正方形并返回其面积。
# 分析：这里需要计算的是正方形的面积，因此只要知道边长即可。可以构建dp矩阵，其中dp[i][j]表示对应矩阵位置索引下的最大边长。
# 如何确定这个边长呢？当我们每遇到"1"的时候，可以向左，向上，向左上索引，判断这三个位置的数字是否为1，如果为1，则当前位置等于min(top-left,top,left)+1.表示当前位置的边长+1。
# 例子:  1 1          1 1
# 例子:  1 1 ,则dp为  1 2  ，左上的任意一个位置为0的则，由于当前位置是1，其至少是一个1x1的正方形，所以其边长为1。经过不断迭代，可以得到最终的面积。
from typing import List

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if matrix is None or len(matrix)<1:return 0

        rows =len(matrix)
        cols=len(matrix[0])

        dp=[[0]*(cols+1) for _ in range(rows+1)]
        max_side=0

        for r in range(rows):
            for c in range(cols):
                if matrix[r][c]=="1":
                    dp[r+1][c+1]=min(dp[r][c],dp[r+1][c],dp[r][c+1])+1
                    max_side=max(max_side,dp[r+1][c+1])
        return max_side**2

