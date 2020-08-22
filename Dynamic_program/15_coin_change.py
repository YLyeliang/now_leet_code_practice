# You are given coins of different denominations and a total amount of money amount.
# Write a function to compute the fewest number of coins that you need to make up that amount.
# If that amount of money cannot be made up by any combination of the coins, return -1.
#
# Example 1:
#
# Input: coins = [1, 2, 5], amount = 11
# Output: 3
# Explanation: 11 = 5 + 5 + 1
# Example 2:
#
# Input: coins = [2], amount = 3
# Output: -1
# Note:
# You may assume that you have an infinite number of each kind of coin.
#
# 问题：给定不同面额的硬币和一定总量的金钱数量，计算组成该金钱的最小硬币数目。如果不能，返回-1.
# 分析：typical dp problem. 构建一个DP数组，其中dp[i]表示数字为i时的最小组成数目。那么可以知道，dp[amount]=min(dp[amount-coin]+1) if dp[amount-coin]!=-1
# 初始化dp[0]=0
from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount<1: return 0
        dp = [0 for _ in range(amount+1)]
        for sum in range(1,amount+1):
            mi=-1
            for coin in coins:
                if sum>=coin and dp[sum-coin]!=-1:
                    temp = dp[sum-coin]+1
                    mi=temp if mi<0 else min(mi,temp)
            dp[sum]=mi
        return dp[amount]


