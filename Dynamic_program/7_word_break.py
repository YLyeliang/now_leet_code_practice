# Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
#
# Note:
#
# The same word in the dictionary may be reused multiple times in the segmentation.
# You may assume the dictionary does not contain duplicate words.
# Example 1:
#
# Input: s = "leetcode", wordDict = ["leet", "code"]
# Output: true
# Explanation: Return true because "leetcode" can be segmented as "leet code".
# Example 2:
#
# Input: s = "applepenapple", wordDict = ["apple", "pen"]
# Output: true
# Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
#              Note that you are allowed to reuse a dictionary word.
# Example 3:
#
# Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
# Output: false

# 分析：给定非空字符串s和字典wordDict，包含非空单词list，判断s能不能被分割成一个或多个字典单词。
# 依然使用dp的方法，构建dp数组。考虑一下，如果结果为true，那么从左往右进行匹配的话，s的最后一个字符肯定是在字典中的。那么，可以对dp进行定义，dp[i]表示索引为i的字符是以字典中的单词结尾的。
# 比如 leetcode, dp[3]=true,因为s[:4] in wordDict. dp[7]=true,因为s[4:] in wordDict。这样，迭代的比较子串是否在字典中，并对索引i下的dp赋值，如果dp[-1]为True,则表明能够完全分割。
from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp=[False]* len(s)
        for i in range(len(s)):
            for w in wordDict:
                if  w == s[i-len(w)+1:i+1] and (dp[i-len(w)]==True or i -len(w) == -1):
                    dp[i]=True
        return dp[-1]

sol=Solution()
print(sol.wordBreak('leetcode',['leet','code']))
b='leetcode'
c=b[-2:1]
print(c)


