//
// Created by 叶亮 on 2021/12/19.
//

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
//
//On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
//
//Find and return the maximum profit you can achieve.
//
//
//
//Example 1:
//
//Input: prices = [7,1,5,3,6,4]
//Output: 7
//Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
//Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
//Total profit is 4 + 3 = 7.
// Example 2:
//
//Input: prices = [1,2,3,4,5]
//Output: 4
//Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//Total profit is 4.
//Example 3:
//
//Input: prices = [7,6,4,3,1]
//Output: 0
//Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

// 问题：股票买卖II类，可以买卖多次。

// 方法：最大利益为所有子利益之和。那么，sub-profit = prices[j] - prices[i]

// 假设两个dp数组，T_ik0表示第i天交易k次后手持1个股票的最大收益。则有T_i0和T_i1
// T[i][0] = max(T[i-1][1] + prices[i], T[i-1][0])
// T[i][1] = max(T[i-1][0] - prices[i], T[i-1][1])
#include "vector"

using namespace std;


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int T_i0 = 0, T_i1 = -prices[0], prev = 0;
        for (int i = 1; i < prices.size(); i++) {
            T_i0 = max(T_i1 + prices[i], T_i0);
            T_i1 = max(prev - prices[i], T_i1);
            prev = T_i0;
        }
        return T_i0;

    }
};

