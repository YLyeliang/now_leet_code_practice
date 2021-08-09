# Say you have an array for which the ith element is the price of a given stock on day i.
#
# Design an algorithm to find the maximum profit. You may complete as many transactions as you like
# (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
#
# You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
# After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
# Example:
#
# Input: [1,2,3,0,2]
# Output: 3
# Explanation: transactions = [buy, sell, cooldown, buy, sell]

# 问题：给定一个数组，第i个元素是第i天的股票价格，求买卖的最大利润。可以买卖多次，但是在卖出去后的第二天不能购买。
# 分析：对于股票交易问题，其利润通常由如下公式决定，在第i天时交易k次后手持0个股票的利润和手持1个股票的利润
# 一般来说，
# T[i,k,0] = max(T[i-1,k,0],T[i-1,k,1]+prices[i])
# T[i,k,1] = max(T[i-1,k,1],T[i-1,k,0]-prices[i])
# 对于该问题，由于在卖出去后的第二天不能购买，则第二个公式需要做一些修改
# T[i,k,1] = max(T[i-1,k,1],T[i-2,k,0]-prices[i])
import sys
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        T_ik0_pre, T_ik0, T_ik1 = 0, 0, -sys.maxsize
        for price in prices:
            T_ik0_old = T_ik0
            T_ik0 = max(T_ik0_old, T_ik1 + price)
            T_ik1 = max(T_ik1, T_ik0_pre - price)
            T_ik0_pre = T_ik0_old
        return T_ik0
