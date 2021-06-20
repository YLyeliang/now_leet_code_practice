# 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
#
# 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

# 分析：每个骰子有六个点数，即六种情况，1-6.令n表示骰子数，s表示点数和，F(n,s)表示n个骰子构成s的情况数
# 当n=1时，F(n,s), F(1,1) = F(1,2) = ... = F(1,6) = 1，因为一个骰子每个点数只有一种情况；
# n = 2时， F(2,2) = 1 = F(1, 1). F(2, 3) = F(1, 2) + F(1, 1), F(2,4) = F(1,3) +F(1,2)+F(1,1)
# 考虑n=2的情况，抛掷第n个骰子的时候，考虑抛第n-1个骰子时的点数分布情况；
# 抛第2个骰子时，要构成点数3,则抛前n-1个骰子必有 3-1 =2, 3-2=1这两种情况，即F(2,3) = F(1,2) + F(1, 1)
# 推广到n个的时候，由于抛第n个骰子只有1-6的点数，则
# F(n,s) = F(n-1,s-1) + F(n-1,s-2) + ... + F(n-1,s-6)

# 根据上述分析，使用动态规划步骤:
# 1.构建DP数组, dp[i][j]表示抛i个骰子点数为j的情况；
# 2.状态转移方程, dp[i][j] = dp[i-1][j-1] + ... + dp[i-1][j-6] if j > 6 else dp[i-1][j-k] where k = j-1
# 3.初始化状态dp[1][1-6] = 1
# n个骰子一共有6^n种情况，最大点数为6n,最小点数为n.

from typing import List


class Solution:
    def twoSum(self, n: int) -> List[float]:
        dp = [[0] * (6 * n + 1) for _ in range(n + 1)]
        for i in range(1, 7):
            dp[1][i] = 1

        for i in range(2, n + 1):
            for j in range(i, i * 6 + 1):
                for k in range(1, 7 if j > 6 else j):
                    dp[i][j] += dp[i - 1][j - k]
        res = []
        for i in range(n, 6 * n + 1):
            res += [dp[n][i] * 1.0 / 6 ** n]
        return res


sol = Solution()
res = sol.twoSum(2)
print(res)
