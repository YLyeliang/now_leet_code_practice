# Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz",
# so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
#
# Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s.
# In particular, your input is the string p and you need to output the number of different non-empty substrings of p
# in the string s.
#
# Note: p consists of only lowercase English letters and the size of p might be over 10000.
#
# Example 1:
# Input: "a"
# Output: 1
#
# Explanation: Only the substring "a" of string "a" is in the string s.
# Example 2:
# Input: "cac"
# Output: 2
# Explanation: There are two substrings "a", "c" of string "cac" in the string s.
# Example 3:
# Input: "zab"
# Output: 6
# Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.

# 问题：环绕字符串中的唯一子串。考虑一个无限环绕的字符串s:a-z, 现在有另一个字符串p. 找出有多少个独立非空的p的子串能在s中表示.
# 分析：利用动态规划进行分析。构建长度为26的DP数组（a-z)，考虑dp[i]表示以第i个字符结尾的最大子串个数。构建a-z的字符串s。
# 遍历p,计算maxlengthCur+=1 if s[i]-s[i-1] ==1 (即两个字符串相邻) or s[i-1]-s[i]==25 (两个字符串首尾相接),否则令maxlengthCur=1。
# 然后计算p[i]距字符a的距离 s[p[i]]-s['a'],表示字符p[i]在26个字母中的索引dp[p[i]].dp[p[i]]=max(dp[p[i]],maxlengthCur)
# 为什么maxlengthCur+=1? 以zab为例，以z结尾的子串为1，计算za首尾相接，那么a之前的所有子串加上a依然为子串，同时出现了新的子串a。


# 暴力：不一定全部解出
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        a = 'abcdefghijklmnopqrstuvwxyz' * 10
        if len(p) <= 1: return len(p)
        nums = len(set(p))
        for i in range(2, len(p) + 1):
            for j in range(0, len(p) - i + 1):
                if p[j:j + i] in a: nums += 1
        return nums


class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        # count[i] 表示以ith letter结尾的最大子串个数
        count = [0 for _ in range(26)]
        hash = {val: i for i, val in enumerate('abcdefghijklmnopqrstuvwxyz')}
        maxlengthCur = 0

        for i in range(len(p)):
            if i > 0 and (hash[p[i]] - hash[p[i - 1]] == 1 or hash[p[i - 1]] - hash[p[i]] == 25):
                maxlengthCur += 1
            else:
                maxlengthCur = 1
            index = hash[p[i]] - hash['a']
            count[index] = max(count[index], maxlengthCur)

        res = sum(count)
        return res


sol = Solution()
sol.findSubstringInWraproundString('zab')
