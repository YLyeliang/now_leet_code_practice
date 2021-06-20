# You have d dice and each die has f faces numbered 1, 2, ..., f.
#
# Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face-up
# numbers equals target.
#
#
#
# Example 1:
#
# Input: d = 1, f = 6, target = 3
# Output: 1
# Explanation:
# You throw one die with 6 faces.  There is only one way to get a sum of 3.
# Example 2:
#
# Input: d = 2, f = 6, target = 7
# Output: 6
# Explanation:
# You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
# 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
# Example 3:
#
# Input: d = 2, f = 5, target = 10
# Output: 1
# Explanation:
# You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.
# Example 4:
#
# Input: d = 1, f = 2, target = 3
# Output: 0
# Explanation:
# You throw one die with 2 faces.  There is no way to get a sum of 3.
# Example 5:
#
# Input: d = 30, f = 30, target = 500
# Output: 222616187
# Explanation:
# The answer must be returned modulo 10^9 + 7.
#
#
# Constraints:
#
# 1 <= d, f <= 30
# 1 <= target <= 1000

# 问题：有一个骰子，骰子有f个面，数字从1-f,投掷d次，求得到和为s时投掷的所有可能情况。

# 分析：与46类似，不同之处在于这里骰子的面数由f决定，并且只考虑骰子的点数情况；
# 整个分析过程与46一致:
# 1. 构建dp数组，令dp[i][j]表示投掷i次时和为j的情况；
# 2.状态转移方程：dp[i][j] = dp[i-1][j-k], where k = 1 to f if f < j, else k = 1 to j
# 3.初始化状态dp[1][1:f+1] 1

class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        if target > d * f: return 0
        dp = [[0] * (d * f + 1) for _ in range(d + 1)]
        for i in range(f):
            dp[1][i + 1] = 1
        for i in range(2, d + 1):
            for j in range(i, i * f + 1):
                for k in range(1, f + 1 if f < j else j):
                    dp[i][j] += dp[i - 1][j - k]

        return dp[-1][target] % (10 ** 9 + 7)


sol = Solution()

res = sol.numRollsToTarget(30, 30, 500)
print(res)
