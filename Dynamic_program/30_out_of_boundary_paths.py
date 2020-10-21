# There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to
# adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move
# N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large,
# return it after mod 109 + 7.
#
#
#
# Example 1:
#
# Input: m = 2, n = 2, N = 2, i = 0, j = 0
# Output: 6
# Explanation:
#
# Example 2:
#
# Input: m = 1, n = 3, N = 3, i = 0, j = 1
# Output: 12
# Explanation:
#
#
#
# Note:
#
# Once you move the ball out of boundary, you cannot move it back.
# The length and height of the grid is in range [1,50].
# N is in range [0,50].

# 问题：有个mxn的网格和一个球。给定球初始点(i,j)，可以向四个方向移动球或越过网格边界，至多移动N次。找到使球移出边界的所有路径数。
# 结果可能很大，因此返回 val mod 10e9 +7.

# 分析：考虑DP方法。使用DP[i][j][k]表示在第i步时有多少种路径可以走到(j,k).由于DP[i][j][k]仅仅依赖于DP[i-1][j][k]，因此可以将三维数组压缩至二维。


class Solution:
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        mod = 1000000007
        if N <= 0: return 0
        count = [[0] * n for _ in range(m)]
        count[i][j] = 1
        result = 0
        # four directions
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        for step in range(N):
            temp = [[0] * n for _ in range(m)]
            for r in range(m):
                for c in range(n):
                    for dir in dirs:
                        nr = r + dir[0]
                        nc = c + dir[1]
                        if nr < 0 or nc < 0 or nr >= m or nc >= n:
                            result = (result + count[r][c]) % mod
                        else:
                            temp[nr][nc] = (temp[nr][nc] + count[r][c]) % mod
            count=temp
        return result
