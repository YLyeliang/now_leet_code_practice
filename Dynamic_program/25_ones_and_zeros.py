# Given an array, strs, with strings consisting of only 0s and 1s. Also two integers m and n.
#
# Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can
# be used at most once.
#
# Example 1:
#
# Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
# Output: 4
# Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are "10","0001","1","0".
# Example 2:
#
# Input: strs = ["10","0","1"], m = 1, n = 1
# Output: 2
# Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
#
#
# Constraints:
#
# 1 <= strs.length <= 600
# 1 <= strs[i].length <= 100
# strs[i] consists only of digits '0' and '1'.
# 1 <= m, n <= 100


# 问题：给定list(str)，只包含0 and 1, 以及两个整数m and n。任务：给定 m 0 and n 1, 求能用这些字符组成列表中的字符串的最大数目。每个0 and 1 只能用一次
# 分析：第一反应是构建长度等于strs的dp数组，dp[i]表示截止当前索引下组成字符串的最大数目。对于单个字符串，统计strs[i]的0和1的个数，然后m-=0个数,n-=1个数。(不对）
# 状态转移方程：
# 先考虑O(n^2)解，遍历strs,对于每个索引，遍历索引之前的str,每个str计算其01组成数目， 。计算当前索引下组成字符串的最大数目。
from typing import List


# TODO: Figure out the 0-1knapsack problem.
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for str in strs:
            zeros = str.count('0')
            ones = str.count('1')

            for i in range(m,zeros-1,-1):
                for j in range(n,ones-1,-1):
                    dp[i][j]=max(dp[i][j],dp[i-zeros][j-ones]+1)
        return dp[m][n]