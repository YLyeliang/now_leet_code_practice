# Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
#
# Example 1:
#
# Input: n = 12
# Output: 3
# Explanation: 12 = 4 + 4 + 4.
# Example 2:
#
# Input: n = 13
# Output: 2
# Explanation: 13 = 4 + 9.

# 问题：给定正整数n，找到和为n的完美正方形数字的最小数量。完美正方形数字(1, 4, 9, 16, ...),表示为j
# 分析：典型的动态规划问题。完美正方形数字即整数的平方，这里就是一个最优选择的问题。如果使用贪心策略，那么12第一次-9=3，最后3=1+1+1，最终结果为4，显然不是最优。
# 所以，需要使用到动态规划的解法。可以构建一个dp数组，dp[i]表示当前数字的最小数量。对于每一个数字i，其最小数量为dp[i-某一个j]+dp[j]=min(dp[i-某一个j]+1)
# 该方法需要O(nlogn)time,O(n)space.还可以继续优化

import sys

class Solution:
    def numSquares(self, n: int) -> int:
        if n<=0:return 0
        dp=[sys.maxsize for _ in range(n+1)]
        dp[0]=0
        for i in range(1,n+1):
            j=1
            while j*j<=i:
                dp[i]=min(dp[i],dp[i-j*j]+1)
                j+=1
        return dp[-1]

# static DP.从1开始，如果len(dp)<=n,则持续append数字
class Solution:
    def numSquares(self, n: int) -> int:
        if n<=0:return 0
        dp=[0]
        while len(dp)<=n:
            m=len(dp)
            cntSquares=sys.maxsize
            i=1
            while i*i<=m:
                cntSquares=min(cntSquares,dp[m-i*i]+1)
                i+=1
            dp.append(cntSquares)
        return dp[-1]

# four-number theorem


