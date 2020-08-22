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

# 问题：给定一个数组，第i个元素是第i天的股票价格，求买卖的最大利润。可以买卖多次（在再次购买时须卖掉之前的股票，且出售后不能购买下一天的股票
# 分析：