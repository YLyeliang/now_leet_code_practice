# Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
#
# Example 1:
# Input:
#
# "bbbab"
# Output:
# 4
# One possible longest palindromic subsequence is "bbbb".
#
#
# Example 2:
# Input:
#
# "cbbd"
# Output:
# 2
# One possible longest palindromic subsequence is "bb".
#
#
# Constraints:
#
# 1 <= s.length <= 1000
# s consists only of lowercase English letters.

# 问题：给定字符串s, 找最长回文子序列的长度。s最大长度不超过1000.
# 分析：由于是序列，可以对字符串s中的元素进行删减，来得到最长回文子串。
# 使用DP思路。回文子串的特征是逆序之后等于原字符串。用双指针的方法来判断。使用i,j两个指针/索引表示字符串的起始地址。
# i,j外扩的时候，i-1, j+1对应的字符如果相等，即在序列两端新增了两个相等的元素，则仍构成回文串，同时长度增加2.
# 状态变量：dp[i][j]表示字符串s[i:j]的最大回文长度。i,j表示索引位置
# 状态转移：dp[i][j]=dp[i+1][j-1]+2 if s[i]==s[j], else dp[i][j]=max(dp[i+1][j],dp[i][j-1]
# 初始状态：dp[i][i]=1

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])
        return dp[0][n - 1]
