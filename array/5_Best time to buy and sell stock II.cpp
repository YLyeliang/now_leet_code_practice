//
// Created by yel on 2021/8/9.
//

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
//
//Find the maximum profit you can achieve. You may complete as many transactions as you like
// (i.e., buy one and sell one share of the stock multiple times).
//
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

// 问题： 买卖股票的最佳时间II： 给定一个价格数组prices, prices[i]表示第i天的价格，求最大利润。
// 可以买卖多次（在再次购买时须卖掉之前的股票）

// 方法：股票交易问题总结见Dynamic_program/股票交易问题总结.md
// T[i,k,0] = max(T[i-1,k,0],T[i-1,k,1]+price)
// T[i,k,1] = max(T[i-1,k,1],T[i-1,k,0]-price)

#include "vector"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int T_ik0 = 0, T_ik1 = INT_MIN;
        for (auto price:prices) {
            int T_ik0_old = T_ik0;  // old 前一天 i-1
            T_ik0 = max(T_ik0, T_ik1 + price);
            T_ik1 = max(T_ik1, T_ik0_old - price);
        }
        return T_ik0;

    }
};
