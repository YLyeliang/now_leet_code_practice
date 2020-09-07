# Given a non-empty array containing only positive integers,
# find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
#
# Note:
#
# Each of the array element will not exceed 100.
# The array size will not exceed 200.
#
#
# Example 1:
#
# Input: [1, 5, 11, 5]
#
# Output: true
#
# Explanation: The array can be partitioned as [1, 5, 5] and [11].
#
#
# Example 2:
#
# Input: [1, 2, 3, 5]
#
# Output: false
#
# Explanation: The array cannot be partitioned into equal sum subsets.
#
# 问题：给定非空数组，只包含正整数，求数组能否被分成两个子集，其两个子集的元素之和相等。
# 分析：
# This problem is essentially let us to find whether there are several numbers in a set which are able to sum to a specific value (in this problem, the value is sum/2).
#
# Actually, this is a 0/1 knapsack problem, for each number, we can pick it or not. Let us assume dp[i][j] means whether the specific sum j can be gotten from the first i numbers.
# If we can pick such a series of numbers from 0-i whose sum is j, dp[i][j] is true, otherwise it is false.
#
# Base case: dp[0][0] is true; (zero number consists of sum 0 is true)
#
# Transition function: For each number, if we don't pick it, dp[i][j] = dp[i-1][j], which means if the first i-1 elements has made it to j,
# dp[i][j] would also make it to j (we can just ignore nums[i]). If we pick nums[i]. dp[i][j] = dp[i-1][j-nums[i]],
# which represents that j is composed of the current value nums[i] and the remaining composed of other previous numbers.
# Thus, the transition function is dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:

