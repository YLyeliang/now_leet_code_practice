# You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee
# representing a transaction fee.
#
# Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the
# transaction fee for each transaction.
#
# Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
#
#
#
# Example 1:
#
# Input: prices = [1,3,2,8,4,9], fee = 2
# Output: 8
# Explanation: The maximum profit can be achieved by:
# - Buying at prices[0] = 1
# - Selling at prices[3] = 8
# - Buying at prices[4] = 4
# - Selling at prices[5] = 9
# The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
# Example 2:
#
# Input: prices = [1,3,7,5,10,3], fee = 3
# Output: 6

# 问题： prices[i]为第i天股票价格，一次买卖手续费为fee(int)，可以交易多次，求最大利润。Note:买之前必须卖掉之前的

# 方案；典型的股票买卖问题，股票买卖的核心思路在于第i天交易k次时手持0个股票的利润T[i][k][0]和手持1个股票的利润T[i][k][1]
# 在不限次数的条件下，其利润计算公式如下：
# T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
# T[i][k][1] = max(T[i-1][k][1], T[i-1][k][0] - prices[i])
# 加入交易手续费的约束后，有两种计算方式：1.买的时候计算交易费用; 2.卖的时候计算交易费用
# T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
# T[i][k][1] = max(T[i-1][k][1], T[i-1][k][0] - prices[i] - fee)
#
# or
#
# T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i] - fee)
# T[i][k][1] = max(T[i-1][k][1], T[i-1][k][0] - prices[i])

from typing import List


class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        T_ik0, T_ik1 = 0, 0
        for price in prices:
            T_ik0_old = T_ik0
            T_ik0 = max(T_ik0_old, T_ik1 + price)
            T_ik1 = max(T_ik1, T_ik0_old - price - fee)
        return T_ik0
