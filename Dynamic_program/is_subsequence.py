# Given a string s and a string t, check if s is subsequence of t.
#
# A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
#
# Follow up:
# If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
#
# Credits:
# Special thanks to @pbrother for adding this problem and creating all test cases.
#
#
#
# Example 1:
#
# Input: s = "abc", t = "ahbgdc"
# Output: true
# Example 2:
#
# Input: s = "axc", t = "ahbgdc"
# Output: false
#
#
# Constraints:
#
# 0 <= s.length <= 100
# 0 <= t.length <= 10^4
# Both strings consists only of lowercase characters.

# 分析：给定字符串s & t，问s是不是t的子序列。子序列是从中抽掉某些元素后可以得到的序列。
# 方法；一：可以遍历字符串t，同时设置一个指针指向s，按顺序比较s的字符，若指针长度等于s的长度，则表明为子序列。

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:return True
        n=0
        for cha in t:
            if cha ==s[n]:n+=1
            if n==len(s):return True
        return False





