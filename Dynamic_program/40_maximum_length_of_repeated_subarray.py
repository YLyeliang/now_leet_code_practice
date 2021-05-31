# Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
#
#
#
# Example 1:
#
# Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
# Output: 3
# Explanation: The repeated subarray with maximum length is [3,2,1].
# Example 2:
#
# Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
# Output: 5
#
#
# Constraints:
#
# 1 <= nums1.length, nums2.length <= 1000
# 0 <= nums1[i], nums2[i] <= 100

# 问题: 给两个整型数组，返回同时出现在两个数组中的子数组的最大长度

# 方案: 1. 遍历nums1, if nums1[i] == nums2[j], 则 i+=1, j+=1, tmp+=1 max_length=(tmp,max_length)
# 不可行，因为存在多个数字相同时需要从j的下一位开始重新遍历nums2.导致算法时间大幅度增加
# 2.　DP方法：(1) 构建DP数组，dp[i][j]表示以nums1[i]和nums2[j]结尾的最长公共子数组；
# (2) dp[0][0] = 0, dp[0][...j] = 0, dp[...i][0] = 0.  If A[i-1] = B[j-1], dp[i][j] = 1 + dp[i-1][j-1]
# 如果某一对数相等，则以他们结尾的数字的前一对数字+1则为当前数字结尾的最长公共子数组。

from typing import List


class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        m = len(nums1)
        n = len(nums2)
        max_num = 0
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if nums1[i - 1] == nums2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                    max_num = max(max_num, dp[i][j])
        return max_num


nums1 = [0, 0, 0, 0, 0, 0, 1, 0, 0, 0]
nums2 = [0, 0, 0, 0, 0, 0, 0, 1, 0, 0]

solution = Solution()
res= solution.findLength(nums1, nums2)
print(res)
