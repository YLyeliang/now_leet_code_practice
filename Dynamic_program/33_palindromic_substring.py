# Given a string, your task is to count how many palindromic substrings in this string.
#
# The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
#
# Example 1:
#
# Input: "abc"
# Output: 3
# Explanation: Three palindromic strings: "a", "b", "c".
#
#
# Example 2:
#
# Input: "aaa"
# Output: 6
# Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
#
#
# Note:
#
# The input string length won't exceed 1000.

# 问题：给定字符串s，求字符串中的回文子串的数目。相同子串，不同起始点算作不同子串。
# 分析；DP方法。考虑回文子串的索引序列 i, i+1, ..., j-1, j.如果s[i]==s[j]且s[i+1:j-1]为回文，那么这一段则为回文。
# 如果回文子串的长度小于3，只需要判断s[i]==s[j]即可。
# 根据上述表述。遍历字符串s.构建二维dp数组，dp[i][j]表示索引段是否为回文。则遍历时如果是回文，result+=1.

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]

        res = 0
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                dp[i][j] = s[i] == s[j] and ((j - i + 1) < 3 or dp[i + 1][j - 1])
                res += dp[i][j]
        return res
