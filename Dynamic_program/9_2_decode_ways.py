# A message containing letters from A-Z is being encoded to numbers using the following mapping:
#
# 'A' -> 1
# 'B' -> 2
# ...
# 'Z' -> 26
# Given a non-empty string containing only digits, determine the total number of ways to decode it.
#
# Example 1:
#
# Input: "12"
# Output: 2
# Explanation: It could be decoded as "AB" (1 2) or "L" (12).
# Example 2:
#
# Input: "226"
# Output: 3
# Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

# 分析：这里也可以构建DP数组，先构建dp,dp[i]表示当前位置下的最大解码方式数。现在考虑以下当前位置下的解码数与前一个位置的解码数之间的关系。
# 该问题和斐波那契数列本质上相同。在第i个字符的时候，如果当前字符>1,则dp[i]+=dp[i-1]，如果当前字符与前一个字符组成了[10,26]之内的字符，则dp[i]+=dp[i-2]
# 从例2可以看出，位置为1的时候为1种，位置为2的时候有{2 2}，{22}两种，而位置为3时，6在[1.9]内，可以构成独立数字，dp[2]=dp[1];又因为26在[10,26]内，其结果又加上dp[0],结果等于dp[2]=dp[1]+dp[0]。
# 则可以得到转移方程：dp[i]=dp[i-1]+dp[i-2] if s[i]>0 and s[i-1]s[i] in [10,26], 如果只满足一种条件，则加上相应的值。
# note:在考虑转移方程时，这里必须保证当前字符>0,且当前字符与前一个字符组成的字符>=10。比如例“01”,dp[0]=0,dp[1]时应该判断，s[1]>=1,s[0]s[1]>=10
# 初始化dp[0]=1


# to be continued
class Solution:
    def numDecodings(self, s: str) -> int:
        num = [i for i in range(1, 27)]
        if s == '': return 0
        length = len(s)
        dp = [1]
        dp += [1] if int(s[0]) in num else [0]
        for i in range(2, length + 1):
            dp += [0]
            if int(s[i - 1]) in num:
                dp[i] += dp[i - 1]
            if int(s[i - 2] + s[i - 1]) >= 10 and int(s[i - 2] + s[i - 1]) <= 26:
                dp[i] += dp[i - 2]
            if s[i - 2] == 0 and s[i - 1] == 0: return 0
        return dp[-1]


sol = Solution()
print(sol.numDecodings('12'))
