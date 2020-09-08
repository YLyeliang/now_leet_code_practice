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
# 分析：这个问题的本质是求能否找到一系列数字，其和等于一个特定的数。其实是一个0/1背包问题。对于每一个数字，我们可以选或者不选。假设dp[i][j]表示特定的sum j由前i个数字组成。
# 如果我们可以选择这一系列数字组成sum j， dp[i][j] is true, otherwise is false。
# 初始状态：d[0][0]=True
# 状态转移：对于每个数，当不选时，dp[i][j]=dp[i-1][j]，因为不选择num[i]，则j仍由前i-1个数组成。选择num[i]时，dp[i][j]=dp[i-1][j-num[i]]，表明j由当前的nums[i]和剩下的其他数组成。
# => dp[i][j]=dp[i-1][j] || dp[i-1][j-num[i]]


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
        sum = 0
        for num in nums:
            sum += num

        if sum & 1 == 1: return False
        sum/=2
        n =len(nums)
        dp= [[False]*(sum+1) for _ in range(n+1)]
        dp[0][0]=True
        for  i in range(n+1):
            dp[i][0]=True

        for i in range(1,n+1):
            for j in range(1,sum+1):
                if j>=nums[i-1]:
                    dp[i][j]=dp[i][j] or dp[i-1][j-nums[i-1]]

        return dp[n][sum]

class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        possible_sums = {0}
        for n in nums:
            possible_sums.update({(v + n) for v in possible_sums})
        return (sum(nums) / 2.)  in possible_sums
sol=Solution()
sol.canPartition([1,5,11,5])

# public boolean canPartition(int[] nums) {
#     int sum = 0;
#
#     for (int num : nums) {
#         sum += num;
#     }
#
#     if ((sum & 1) == 1) {
#         return false;
#     }
#     sum /= 2;
#
#     int n = nums.length;
#     boolean[][] dp = new boolean[n+1][sum+1];
#     for (int i = 0; i < dp.length; i++) {
#         Arrays.fill(dp[i], false);
#     }
#
#     dp[0][0] = true;
#
#     for (int i = 1; i < n+1; i++) {
#         dp[i][0] = true;
#     }
#     for (int j = 1; j < sum+1; j++) {
#         dp[0][j] = false;
#     }
#
#     for (int i = 1; i < n+1; i++) {
#         for (int j = 1; j < sum+1; j++) {
#             dp[i][j] = dp[i-1][j];
#             if (j >= nums[i-1]) {
#                 dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
#             }
#         }
#     }
#
#     return dp[n][sum];
# }
# But can we optimize it? It seems that we cannot optimize it in time. But we can optimize in space.
# We currently use two dimensional array to solve it, but we can only use one dimensional array.
#
# So the code becomes:
#
# public boolean canPartition(int[] nums) {
#     int sum = 0;
#
#     for (int num : nums) {
#         sum += num;
#     }
#
#     if ((sum & 1) == 1) {
#         return false;
#     }
#     sum /= 2;
#
#     int n = nums.length;
#     boolean[] dp = new boolean[sum+1];
#     Arrays.fill(dp, false);
#     dp[0] = true;
#
#     for (int num : nums) {
#         for (int i = sum; i > 0; i--) {
#             if (i >= num) {
#                 dp[i] = dp[i] || dp[i-num];
#             }
#         }
#     }
#
#     return dp[sum];
# }
