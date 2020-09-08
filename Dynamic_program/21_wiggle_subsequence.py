# A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate
# between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence
# with fewer than two elements is trivially a wiggle sequence.
#
# For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and
# negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two
# differences are positive and the second because its last difference is zero.
#
# Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence
# is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the
# remaining elements in their original order.
#
# Example 1:
#
# Input: [1,7,4,9,2,5]
# Output: 6
# Explanation: The entire sequence is a wiggle sequence.
# Example 2:
#
# Input: [1,17,5,10,13,15,10,5,16,8]
# Output: 7
# Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
# Example 3:
#
# Input: [1,2,3,4,5,6,7,8,9]
# Output: 2
# Follow up:
# Can you do it in O(n) time?

# 问题：一个数字序列，如果这个序列，后一个数减前一个数构成的差值序列，其数字是交替正负的，那么称这个数字序列为wiggle sequence。摇摆序列
# 给定数字序列，返回最长摇摆子序列的长度。子序列通过删除某些元素得到，其剩下部分保持其原来的顺序。少于两个数的序列为摇摆序列。
# 分析：对于序列中任意位置的数字，有三种状态。向上摇摆（up)，即num[i]>num[i-1];向下摇摆(down),num[i]<num[i-1];相等,num[i]==num[i-1],
# 因此，可以用up和down两个数组来记录这些状态，来得到索引i下的最大摇摆序列。
# if num[i]>num[i-1],up[i[=down[i-1]+1; if num[i]<num[i-1], down[i]=up[i-1]+1; if num[i]==num[i-1], down[i] & up[i]保持不变
#
from typing import List


class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        up = [1]
        down = [1]

        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                up.append(down[i - 1] + 1)
                down.append(down[i - 1])
            elif nums[i] < nums[i - 1]:
                down.append(up[i - 1] + 1)
                up.append(up[i - 1])
            else:
                down += [down[i - 1]]
                up += [up[i - 1]]

        return max(up[-1],down[-1])
