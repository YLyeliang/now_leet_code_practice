# Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.
#
# Example 1:
# Input: s1 = "sea", s2 = "eat"
# Output: 231
# Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
# Deleting "t" from "eat" adds 116 to the sum.
# At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
# Example 2:
# Input: s1 = "delete", s2 = "leet"
# Output: 403
# Explanation: Deleting "dee" from "delete" to turn the string into "let",
# adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
# At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
# If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
# Note:
#
# 0 < s1.length, s2.length <= 1000.
# All elements of each string will have an ASCII value in [97, 122].

# 问题： 给定两个字符串s1,s2.求使两个字符串相等时需删除的字符的最小ASCII码之和

# 方案：每个字符有对应的ascii码大小。使用dp方法求解的话，需要注意怎么定义dp数组.
# 使用dp[i][j]表示 the cost for s1.substr(0,i) and s2.substr(0,j).即，要使s1[0:i]与s2[0:j]相等时需要删除的字符最小ASCII码之和,
# 以delete 和 leet为例。字符串与空字符串要相等时，则需要删除整个字符串，dp[i][0], dp[0][0]=0,dp[1][0]=s1[1-1]+dp[0][0], dp[2][0]=s1[2-1]+dp[1][0] ...
# dp[3][1] = min(dp[3-1][1]+s[3-1],dp[3][1-1]+s2[1-1])
# 则，状态转移方程：if s1[i] = s2[j], dp[i][j] = dp [i-1][j-1]; else dp[i][j] = min(dp[i-1][j]+s1[i],dp[i][j-1]+s2[j-1])
# 初始状态： dp[i][0] = s1[i-1]+dp[i-1][0] i>=1  dp[0][j] = s2[j-1]+dp[0][j-1] j>=1

class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, n + 1):
            dp[0][i] = dp[0][i - 1] + ord(s2[i - 1])
        for i in range(1, m + 1):
            dp[i][0] = dp[i - 1][0] + ord(s1[i - 1])
            for j in range(1, n + 1):
                if s1[i-1] == s2[j-1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j] + ord(s1[i - 1]), dp[i][j - 1] + ord(s2[j - 1]))
        return dp[m][n]
