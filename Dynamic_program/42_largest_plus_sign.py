# In a 2D grid from (0, 0) to (n-1, n-1), every cell contains a 1, except those cells in the given list mines which are 0.
# What is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. If there is none, return 0.
#
# An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1 going
# up, down, left, and right, and made of 1s. This is demonstrated in the diagrams below.
# Note that there could be 0s or 1s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s.
#
# Examples of Axis-Aligned Plus Signs of Order k:
#
# Order 1:
# 000
# 010
# 000
#
# Order 2:
# 00000
# 00100
# 01110
# 00100
# 00000
#
# Order 3:
# 0000000
# 0001000
# 0001000
# 0111110
# 0001000
# 0001000
# 0000000
# Example 1:
#
# Input: n = 5, mines = [[4, 2]]
# Output: 2
# Explanation:
# 11111
# 11111
# 11111
# 11111
# 11011
# In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.
# Example 2:
#
# Input: n = 2, mines = []
# Output: 1
# Explanation:
# There is no plus sign of order 2, but there is of order 1.
# Example 3:
#
# Input: n = 1, mines = [[0, 0]]
# Output: 0
# Explanation:
# There is no plus sign, so return 0.
# Note:
#
# n will be an integer in the range [1, 500].
# mines will have length at most 5000.
# mines[i] will be length 2 and consist of integers in the range [0, n-1].
# (Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)

# 问题：给定大小为nxn的二维数组，以及坐标list mines,除mines里的坐标对应的数组元素为0外，其余元素均为1.
# 求largest axis-aligned plus sign of order k. 即坐标对齐的数为1的"十"字的长度。

# 分析：给定n的情况下，由于结果的特性，最长的k不会超过ceil(n/2),
# 考虑生成一个grid矩阵，其中值grid[i][j]当前位置的最大长度k,所有值初始化为N，且对mines中的坐标元素置0。
# 对每个位置(i,j)，计算四个方向上的1的最大长度。并将grid[i][j]置为其四个方向上的最小值。具体做法为：
# for i in range(N),对每一个i，分别从两端计算最大长度j,k；使用四个变量l,r,u,d表示四个方向，每个方向的初始值为0.grid[i][j],grid[i][k]表示第i行的两端；
# grid[j][i],grid[j][k]表示第i列的上下两端，每次迭代时若grid当前值不等于0，则四个方向+=1，否则该方向变量重新置0，如此迭代即可。
# 取grid的最大值为最终结果。
from typing import List


class Solution:
    def orderOfLargestPlusSign(self, N, mines):
        """
        :type N: int
        :type mines: List[List[int]]
        :rtype: int
        """
        # 生成 N x N 矩阵，大小为N
        grid = [[N] * N for i in range(N)]

        # 对Mines list里的坐标上的值置0
        for m in mines:
            grid[m[0]][m[1]] = 0

        for i in range(N):
            # 四个方向
            l, r, u, d = 0, 0, 0, 0

            for j, k in zip(range(N), reversed(range(N))):
                l = l + 1 if grid[i][j] != 0 else 0
                if l < grid[i][j]:
                    grid[i][j] = l

                r = r + 1 if grid[i][k] != 0 else 0
                if r < grid[i][k]:
                    grid[i][k] = r

                u = u + 1 if grid[j][i] != 0 else 0
                if u < grid[j][i]:
                    grid[j][i] = u

                d = d + 1 if grid[k][i] != 0 else 0
                if d < grid[k][i]:
                    grid[k][i] = d

        res = 0

        for i in range(N):
            for j in range(N):
                if res < grid[i][j]:
                    res = grid[i][j]

        return res


if __name__ == '__main__':

    n = 5
    mines = [[4, 2]]
    solution = Solution()
    solution.orderOfLargestPlusSign(n, mines)
