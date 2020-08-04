# Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
#
# Example 1:
#
# Input: "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
# Example 2:
#
# Input: "cbbd"
# Output: "bb"

# 分析：找到最长的回文子串。回文：即顺序和倒序的字符串相同的则为回文。
# 动态规划的思想：动态规划的思想在于构建dp数组，这里的话，需要构建dp矩阵。考虑到一个字符串的子串为回文时，其两头的字符是相等的，比如“aba",其中左端a=右端a。
# 因此，可以构建dp[n][n]，其中dp[i][j]表示字符串s[i:j+1]为回文串。使用两个for循环，逐个对比子串两头的值s[i]s[j]是否相等，如果相等，并且这两头中间的字符串为回文串，即dp[i+1][j-1]为True,则将dp[i][j]设为True,
# 初始状态：dp[i][i]为True,因为单个字符就是回文。dp[i][j]为True if s[i]==s[i+1]，两个相等的字符也是回文，对应aa,bb。

class Solution:
    def longestPalindrome(self, s: str) -> str:
        res=''
        max_len=0
        n=len(s)
        dp=[[0]*n for _ in range(n)]
        for i in range(n):
            dp[i][i]=True
            max_len=1
            res=s[i]
        for i in range(n-1):
            if s[i]==s[i+1]:
                dp[i][i+1]=True
                res=s[i:i+2]
                max_len=2
        for j in range(n):
            for i in range(0,j-1):
                if s[i]==s[j] and dp[i+1][j-1]:
                    dp[i][j]=True
                    if max_len<j-i+1:
                        res=s[i:j+1]
                        max_len=j-i+1
        return res


sol=Solution()
test="babad"
out=sol.longestPalindrome(test)
print(out)

# 方法2：中心扩展
# 分析：该方法就是先找到回文串的中心符号，然后从中心向两端扩展。回文串的中心有两种情况，一种是奇数（bab),中心为单个字符；另一种是偶数（abba)，中心为双字符。
# 这里，遍历整个字符串，对每个字符，以中心扩展的方法向两端推进，往左为l，往右为r,如果s[l]==s[r],则l-=1,r+=1，最后返回s[l+1:r]。然后将结果保存，并与每次保存的字符串比较长度，保留最长的字符串。

class Solution:
    def longestPalindrome(self, s):
        res = ""
        for i in range(len(s)):
            # odd case, like "aba"
            tmp = self.helper(s, i, i)
            if len(tmp) > len(res):
                res = tmp
            # even case, like "abba"
            tmp = self.helper(s, i, i+1)
            if len(tmp) > len(res):
                res = tmp
        return res

    # get the longest palindrome, l, r are the middle indexes
    # from inner to outer
    def helper(self, s, l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1; r += 1
        return s[l+1:r]