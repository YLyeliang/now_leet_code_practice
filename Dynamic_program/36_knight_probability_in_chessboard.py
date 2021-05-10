# On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The
# rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
#
# A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal
# direction, then one square in an orthogonal direction.

# Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece
# would go off the chessboard) and moves there.
#
# The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the
# probability that the knight remains on the board after it has stopped moving.

# Example
#
# Input: 3, 2, 0, 0
# Output: 0.0625
# Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
# From each of those positions, there are also two moves that will keep the knight on the board.
# The total probability the knight stays on the board is 0.0625.

# @ # #
# # # #   ->
# # # #
# 第一次可移动两次留在棋盘上，2/8; 第二次也有两次机会, 2/8, 1/4 * 1/4 = 1/16 = 0.0625

# Note:
#
# N will be between 1 and 25.
# K will be between 0 and 100.
# The knight always initially starts on the board.

# 问题：给定NxN的圆盘，骑士初始位置为r行c列，移动规则和中国象棋中的马一致，每次随机移动一个方向，直到移动K次或者移出棋盘，
# 返回停止移动后保留在棋盘内的概率。
#

# 方案：创建一个NxN的数组Arr,f[r][c][steps]表示移动steps次时落在r行c列的概率。
# 对于r,c位置的概率，即状态转移方程，可以由上一位置的概率推算得到： f[r][c][steps]= \sum_{dr,dc}{f[r+dr][c+dc][steps-1]/8}.
# 其中dr,dc为{1,-1}和{2,-2}的组合。
# 则可以使用两个dp数组来进行表示，dp表示前一步时的概率，dp2[][]表示当前步时的概率。
# 初始化状态dp[r][c] = 1


class Solution:
    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        dp = [[0] * N for _ in range(N)]
        dp[r][c] = 1  # 初始化概率
        directions = ((1, 2), (1, -2), (2, 1), (2, -1), (-1, 2), (-1, -2), (-2, 1), (-2, -1))
        for i in range(K):
            dp2 = [[0] * N for _ in range(N)]
            for r, rows in enumerate(dp):
                for c, val in enumerate(rows):
                    for dr, dc in directions:
                        if 0 < r + dr < N and 0 < c + dc < N and dp[r + dr][c + dc] > 0:
                            dp2[r][c] += dp[r + dr][c + dc] / 8
            dp = dp2

        return sum(map(sum, dp))


# 深度优先搜索：
# 在r行c列时走K-k步后留在棋盘上的概率为：dfs(k,r,c,p)
def knightProbability(N, K, r, c):
    """
    :type N: int
    :type K: int
    :type r: int
    :type c: int
    :rtype: float
    """
    moves = ((-1, -2), (-2, -1), (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2))
    mem = {}

    def dfs(k, x, y, P):
        p = 0
        if 0 <= x < N and 0 <= y < N:
            if k < K:
                for dx, dy in moves:
                    x_next = x + dx
                    y_next = y + dy
                    if (x_next, y_next, k + 1) not in mem:
                        mem[(x_next, y_next, k + 1)] = dfs(k + 1, x_next, y_next, P / len(moves))
                    p += mem[(x_next, y_next, k + 1)]
            else:
                p = P

        return p

    return dfs(0, r, c, 1.0)


knightProbability(3, 2, 0, 0)
