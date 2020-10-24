# You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
#
# Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in
# this fashion.
#
# Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs.
# You can select pairs in any order.
#
# Example 1:
# Input: [[1,2], [2,3], [3,4]]
# Output: 2
# Explanation: The longest chain is [1,2] -> [3,4]
# Note:
# The number of given pairs will be in the range [1, 1000].

# 问题：给定n个数字对。每对中，第一个总比第二个小。定义：数字对(c,d) & (a,b) 当且仅当b < c时,表明(c,d)可以接在(a,b)后面。
# 给定数字对集合，找到可形成链式的最大长度。可以以任意顺序选择数字对。

# 分析：使用dp方法。先对pairs根据首个数字进行排序。然后利用dp方法遍历pairs。如果当前数字对与之前任一数字对构成链路，则dp[i]=dp[j]+1。否则直接dp[i]=dp[j]


from typing import List


class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        n = len(pairs)
        if n <= 1: return 1 if n == 1 else 0
        pairs.sort(key=lambda x: x[0])

        dp = [1] * n

        for i in range(n):
            for j in range(i):
                dp[i] = max(dp[j] + 1 if pairs[i][0] > pairs[j][1] else dp[j], dp[i])
        return dp[-1]


sol = Solution()
sol.findLongestChain([[1, 2], [2, 3], [3, 4]])
