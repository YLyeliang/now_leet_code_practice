# Given an unsorted array of integers, find the length of longest increasing subsequence.
#
# Example:
#
# Input: [10,9,2,5,3,7,101,18]
# Output: 4
# Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
# Note:
#
# There may be more than one LIS combination, it is only necessary for you to return the length.
# Your algorithm should run in O(n2) complexity.
# Follow up: Could you improve it to O(n log n) time complexity?

# 问题:给定无序整数数组，返回最长的增长子序列的长度。
# 分析：使用动态规划的方法。首先，定义dp数组，这里定义dp[i]定义为以当前数字结尾的最大递增子序列的长度。
# 状态转移方程:对于输入nums中的每一个数字，索引i表示当前遍历下的数字，索引j表示从0开始到小于i的数字，对于每一个nums[i]，
# 将其与之前的所有nums[j]进行比较。如果nums[j]<nums[i]，则dp[i]=dp[j]+1,因为dp[j]表示以nums[j]结尾的最大长度，即nums[j]是子序列中最大的数字，那么nums[j]小于nums[i]时，
# 就相当于整个子序列append了nums[i]，即size+1。
# 初始状态:从第一个数字开始，初始化dp数组全为1.


# Runtime:1500ms
class Solution:
    def lengthOfLIS(self,nums):
        if len(nums)==1:return 1
        dp=[1]*len(nums)
        for i in range(1,len(nums)):
            j=0
            while j<i:
                if nums[j]<nums[i]:
                    dp[i]=max(dp[i],dp[j]+1)
                j+=1
        return dp[-1]

# 二分搜索解法：elegant
# Runtime:40ms (amazing!!!!!!!!!)
class Solution:
    def lengthOfLIS(self, nums):
        tails = [0] * len(nums)
        size = 0
        for x in nums:
            i, j = 0, size
            while i != j:
                m = (i + j) // 2
                if tails[m] < x:
                    i = m + 1
                else:
                    j = m
            tails[i] = x
            size = max(i + 1, size)
        return size

a=[10,9,2,5,3,7,101,18]

sol=Solution()
sol.lengthOfLIS(a)