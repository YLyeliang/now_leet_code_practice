# Given an integer array nums, return the number of longest increasing subsequences.
#
# Notice that the sequence has to be strictly increasing.
#
#
#
# Example 1:
#
# Input: nums = [1,3,5,4,7]
# Output: 2
# Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
# Example 2:
#
# Input: nums = [2,2,2,2,2]
# Output: 5
# Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
#
#
#
# Constraints:
#
# 1 <= nums.length <= 2000
# -106 <= nums[i] <= 106

# 问题： 给定整型数组nums, 返回最长递增子序列的数目。 note:需严格递增（不能>=)
# 分析：首先需要求得最长递增子序列，使用DP解法。
# 根据题目，需要想到两个dp数组，len[i] & cnt[i]分别表示以nums[i]结尾的最大子序列的长度和对应的数目。
# 结果就是当对应的len[i]为最大长度时，cnt[i]。


class Solution:
    def findNumberOfLIS(self, nums):
        n = len(nums)
        length = [1] * n
        cnt = [1] * n
        res = 0
        max_length = 0
        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    if length[i] == length[j] + 1: cnt[i] += cnt[j]  # 当i比j大时，以j结尾的所有子序列+i均构成最长子序列
                    if length[i] < length[j] + 1:
                        length[i] = length[j] + 1
                        cnt[i] = cnt[j]

            if max_length == length[i]: res += cnt[i]
            if max_length < length[i]:
                max_length = length[i]
                res = cnt[i]

        return res
