# Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty
# subsets whose sums are all equal.
#
#
#
# Example 1:
#
# Input: nums = [4,3,2,3,5,2,1], k = 4
# Output: true
# Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
# Example 2:
#
# Input: nums = [1,2,3,4], k = 3
# Output: false
#
#
# Constraints:
#
# 1 <= k <= nums.length <= 16
# 0 <= nums[i] <= 104

# 问题：给定整形数组nums和整数k，如果能将数组分成K个非空的子集，其每个子集的和相等，则返回true.

# 方案: k个子集的和相等，可知targetSubsetSum为sum/k,且每个元素只能使用一次；
# 比较curSubsetSum和targetSubsetSum可知当前子集是否合理；
# 可使用回溯法，为每个元素添加一个位置tag,表示该元素是否使用。遍历数组，构建子集，当子集和==target，重新遍历数组，从剩下的元数中构建k-1个子集，
# 判断是否合理，当全部使用完时若k==0，则表明可构建数组；
# 回溯法时间复杂度较高，不推荐使用，Leetcode通不过；

from typing import List

class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        sum_val = sum(nums)
        max_val = max(nums)
        if sum_val % k != 0 or max_val > sum_val / k:
            return False
        visited = [False] * len(nums)
        return self.canPartitionKSubsetsFrom(nums, k, visited, sum_val / k, 0, 0)

    def canPartitionKSubsetsFrom(self, nums, k, visited, targetSubsetSum, curSubsetSum, nextIndexToCheck):
        if k == 0:
            return True
        if curSubsetSum == targetSubsetSum:
            return self.canPartitionKSubsetsFrom(nums, k-1, visited, targetSubsetSum, 0, 0)

        for i in range(nextIndexToCheck, len(nums), 1):
            if not visited[i] and curSubsetSum + nums[i] <= targetSubsetSum:
                visited[i] = True
                if self.canPartitionKSubsetsFrom(nums, k, visited, targetSubsetSum, curSubsetSum + nums[i], i + 1):
                    return True
                visited[i] = False
        return False
