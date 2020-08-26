# Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
#
# ![](images/range_sum_query_2d.png)
#
# The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
#
# Example:
# Given matrix = [
#   [3, 0, 1, 4, 2],
#   [5, 6, 3, 2, 1],
#   [1, 2, 0, 1, 5],
#   [4, 1, 0, 1, 7],
#   [1, 0, 3, 0, 5]
# ]
#
# sumRegion(2, 1, 4, 3) -> 8
# sumRegion(1, 1, 2, 2) -> 11
# sumRegion(1, 2, 2, 4) -> 12

# 问题:二维矩阵，给定左上角和右下角的坐标，求整个矩形的元素之和。
# 分析：这里其实要解决的就是重复调用的情况下，如果减少重新搜索的时间。有点类似一维数组下的求和函数实现。
from typing import List

class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.matrix=matrix
        rows=len(matrix)
        cols =len(matrix[0]) if len(matrix)>0 else 0
        self.sums=[[0]*(cols+1) for _ in range(rows+1)]
        for i in range(1,rows+1):
            for j in range(1,cols+1):
                self.sums[i][j]=matrix[i-1][j-1]+self.sums[i-1][j]+self.sums[i][j-1]-self.sums[i-1][j-1]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.sums[row2+1][col2+1]-self.sums[row2+1][col1]-self.sums[row1][col2+1]+self.sums[row1][col1]



# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)

# Construct a 2D array sums[row+1][col+1]
#
# (notice: we add additional blank row sums[0][col+1]={0} and blank column sums[row+1][0]={0} to remove the edge case checking), so, we can have the following definition
#
# sums[i+1][j+1] represents the sum of area from matrix[0][0] to matrix[i][j]
#
# To calculate sums, the ideas as below
#
# +-----+-+-------+     +--------+-----+     +-----+---------+     +-----+--------+
# |     | |       |     |        |     |     |     |         |     |     |        |
# |     | |       |     |        |     |     |     |         |     |     |        |
# +-----+-+       |     +--------+     |     |     |         |     +-----+        |
# |     | |       |  =  |              |  +  |     |         |  -  |              |
# +-----+-+       |     |              |     +-----+         |     |              |
# |               |     |              |     |               |     |              |
# |               |     |              |     |               |     |              |
# +---------------+     +--------------+     +---------------+     +--------------+
#
#    sums[i][j]      =    sums[i-1][j]    +     sums[i][j-1]    -   sums[i-1][j-1]   +
#
#                         matrix[i-1][j-1]
# So, we use the same idea to find the specific area's sum.
#
# +---------------+   +--------------+   +---------------+   +--------------+   +--------------+
# |               |   |         |    |   |   |           |   |         |    |   |   |          |
# |   (r1,c1)     |   |         |    |   |   |           |   |         |    |   |   |          |
# |   +------+    |   |         |    |   |   |           |   +---------+    |   +---+          |
# |   |      |    | = |         |    | - |   |           | - |      (r1,c2) | + |   (r1,c1)    |
# |   |      |    |   |         |    |   |   |           |   |              |   |              |
# |   +------+    |   +---------+    |   +---+           |   |              |   |              |
# |        (r2,c2)|   |       (r2,c2)|   |   (r2,c1)     |   |              |   |              |
# +---------------+   +--------------+   +---------------+   +--------------+   +--------------+
# And we can have the following code
# 贴一个大佬的解法， 就是说先构建一个MXN的sums矩阵，每个位置保存以左上角为起点，当前位置为终点的矩形的和。
# 计算这个sums矩阵的方式如上面第一幅图，sums[i][j]的值=当前位置的矩阵的值+左边矩形的和+上边矩形的和-左上角矩形的和（重复相加部分）
# 图2为相应的计算题中矩形和的方式： 即矩形的和=sums[r2][c2]-矩形左边部分-矩形上边部分+左上角部分（重复减去的部分）
