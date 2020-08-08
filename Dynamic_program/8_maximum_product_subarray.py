# Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
#
# Example 1:
#
# Input: [2,3,-2,4]
# Output: 6
# Explanation: [2,3] has the largest product 6.
# Example 2:
#
# Input: [-2,0,-1]
# Output: 0
# Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

# 分析：给定整数数组，找到相邻的子数组，其包含最大乘积。
# 依然是DP解法，这里题干比较明显。这里可以通过保存当前的最大值（正数）和最小值（负数），迭代的求取当前的最大值。若当前数字小于0，可以交换最大、最小值，因为乘以当前数字后会反转。
# 然后每次保留最大的值作为最后的返回值。

from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        r=nums[0]
        imax=r
        imin=r
        for i in range(1,len(nums)):
            if nums[i]<0:
                imax,imin=imin,imax
            imax = max(imax,imax*nums[i])
            imin = min(imin,imin*nums[i])

            r= max(r,imax)


sol=Solution()
print(sol.maxProduct([2,3,-2,4]))