# Given a list of non-negative numbers and a target integer k, write a function to check if the array has a
# continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an
# integer.
#
#
#
# Example 1:
#
# Input: [23, 2, 4, 6, 7],  k=6
# Output: True
# Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
# Example 2:
#
# Input: [23, 2, 6, 4, 7],  k=6
# Output: True
# Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
#
#
# Constraints:
#
# The length of the array won't exceed 10,000.
# You may assume the sum of all the numbers is in the range of a signed 32-bit integer.

# 问题：给定非负数组和target k，检查数组是否有一个连续的子数组，其尺寸至少为2，其和等于k的倍数。
# 分析： 使用DP方法。
# 数学原理：
# In short, start with mod =0, then we always do mod = (mod+nums[i])%k, if mod repeats, that means between these two mod = x occurences the sum is multiple of k.
# Math: c = a % k, c = b % k, so we have a % k = b % k.
# Where a is the mod at i and b is the mod at j and a <= b, i < j, because all nums are non-negative. And c is the mod that repeats.
# Suppose b-a=d, then we have b % k = ((a+d) % k)%k = (a%k + d%k)%k
# In order to make the equation valid: a % k = (a%k + d%k)%k
# d%k has to be 0, so d, the different between b and a, is a multiple of k
# Example:
# [23, 2, 1, 6, 7] k=9
# mod = 5, 7, 8, 5 <-- at here we found it
from typing import List


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        if k == 0:
            return any(nums[i] == 0 and nums[i + 1] == 0 for i in range(len(nums) - 1))
        mods, cum_sum_mod_k = {0: -1}, 0
        for i, n in enumerate(nums):
            cum_sum_mod_k = (cum_sum_mod_k + n) % k
            if cum_sum_mod_k in mods and i - mods[cum_sum_mod_k] > 1:  # ensure length of subarray greater than 2.
                return True
            if cum_sum_mod_k not in mods:
                mods[cum_sum_mod_k] = i
        return False
