# You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
# the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
#
# Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
#
#
#
# Example 1:
#
# Input: nums = [1,2,3,1]
# Output: 4
# Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
#              Total amount you can rob = 1 + 3 = 4.
# Example 2:
#
# Input: nums = [2,7,9,3,1]
# Output: 12
# Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
#              Total amount you can rob = 2 + 9 + 1 = 12.
#
#
# Constraints:
#
# 0 <= nums.length <= 100
# 0 <= nums[i] <= 400

# 分析:该问题的本质就是给定一个list，从中取数字并求和，不能取相邻的数字，求能得到的最大值。
# 利用dp方法，构建dp数组，其中dp[i]表示道第i家时的最大收益，状态转移方程为：dp[i]=max(dp[i-2]+nums[i],dp[i-1])，即当前的数字加上前两个的最大收益并与前一个的最大收益进行比较，保留最大值。

# This particular problem and most of others can be approached using the following sequence:
#
# 1. Find recursive relation
# 2. Recursive (top-down)
# 3. Recursive + memo (top-down)
# 4. Iterative + memo (bottom-up)
# 5. Iterative + N variables (bottom-up)


class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)<=2:return max(nums)
        dp=[0,nums[0]]
        for i in range(2,len(nums)):
            dp[i]=max(dp[i-2]+nums[i-1],dp[i-1])
        return max(dp[-2:])


class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)<1:return 0
        prev1=0
        prev2=0
        for num in nums:
            prev1,prev2=max(num+prev2,prev1),prev1
        return prev1
