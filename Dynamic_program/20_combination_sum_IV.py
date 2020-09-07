# Given an integer array with all positive numbers and no duplicates,
# find the number of possible combinations that add up to a positive integer target.
#
# Example:
#
# nums = [1, 2, 3]
# target = 4
#
# The possible combination ways are:
# (1, 1, 1, 1)
# (1, 1, 2)
# (1, 2, 1)
# (1, 3)
# (2, 1, 1)
# (2, 2)
# (3, 1)
#
# Note that different sequences are counted as different combinations.
#
# Therefore the output is 7.
#
#
# Follow up:
# What if negative numbers are allowed in the given array?
# How does it change the problem?
# What limitation we need to add to the question to allow negative numbers?
#
# Credits:
# Special thanks to @pbrother for adding this problem and creating all test cases.

# 问题：给定不重复正整数数组，求和为target的组合的数量。(每个数可用多次，不用顺序的组合为不同组合）
# 分析：
# 考虑DP解法，构建DP数组，其中dp[target]表示target的组合数量。怎么求状态转移方程呢？假设，我们只差一个数字就可以组合成target，那么可以得到dp[target-nums[i]]。
# 则dp[target]= sum(dp[target-nums[i]]), where  0<=i<len(nums), and target>=nums[i]。这样，就得到了状态转移方程。
# 初始化：target=0时候，只有一种方法，即使用0，dp[0]=1。
from typing import List


class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0 for _ in range(target + 1)]
        dp[0] = 1
        for i in range(1, target + 1):
            for j in range(len(nums)):
                if i - nums[j] >= 0:
                    dp[i] += dp[i - nums[j]]

        return dp[target]


sol=Solution()
sol.combinationSum4([1,2,3],4)