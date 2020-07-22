# Say you have an array for which the ith element is the price of a given stock on day i.
#
# If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
#
# Note that you cannot sell a stock before you buy one.
#
# Example 1:
#
# Input: [7,1,5,3,6,4]
# Output: 5
# Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
#              Not 7-1 = 6, as selling price needs to be larger than buying price.
# Example 2:
#
# Input: [7,6,4,3,1]
# Output: 0
# Explanation: In this case, no transaction is done, i.e. max profit = 0.

# 分析：典型的股票买卖问题，低买高卖，给出最佳的结果
# 这里暴力解法就是O(N^2)，遍历数组时，每次遍历之前的数字，获得一个最佳收益，最后通过max获得最大收益
# 优化解法就是通过遍历数组，记录最小价格同时计算出当前的最大收益。

class Solution:
    def maxProfit(self,prices:list[int]) -> int:
        minprice=float('inf')
        maxprofit=0
        for price in prices:
            if price < minprice:
                minprice=price
            elif price - minprice>maxprofit:
                maxprofit=price-minprice
        return maxprofit

# Kadane算法：该方法就是通过累加不同数值之间的差值，得到当前的最大收益，对于收益为负的，取0。

def maxProfit(prices):
    maxCur,maxSoFar=0,0
    for i in range(1,len(prices)):
        maxCur=max(0,maxCur+prices[i]-prices[i-1])
        maxSoFar=max(maxSoFar,maxCur)
    return maxSoFar