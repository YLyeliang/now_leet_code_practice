# Given a set of distinct positive integers,
# find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
#
# Si % Sj = 0 or Sj % Si = 0.
#
# If there are multiple solutions, return any subset is fine.
#
# Example 1:
#
# Input: [1,2,3]
# Output: [1,2] (of course, [1,3] will also be ok)
# Example 2:
#
# Input: [1,2,4,8]
# Output: [1,2,4,8]

# 问题：给定一个不同正数的集合，找到最大子集，其子集中的每一个正数对(Si,Sj) 均满足 Si%Sj=0 or Sj%Si=0
# 分析：利用DP的方法。构建数组count,该数组用于存储当前索引下的最大子集长度，数组pre用于保存当前索引下的前一个最大子集长度的索引。
# 这里需要先对数组升序排序，这样后面的数组较大，之前的数字除以后面的数字取余均等于0，可以减少条件。在知道当前索引下的最大子集长度之后，如何判断加上下一个索引下的最大子集长度，即动态转移方程。
# 这里需要以当前索引i为基础，对之前所有数取余，如果对j位置的数取余等于0，则count[i]=1+count[j] if 1+count[j]>count[i]。同时保存索引i上一个最大子集的索引pre[i]=j。
# 遍历整个数组得到最大长度和对应的索引，以及每个索引的上一个最大子集的索引。由于这里只要求返回子集，因此只需要迭代取pre索引下的数字即可得到最大自己。

from typing import List


class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:

        n = len(nums)
        count = [1 for _ in range(n)]
        pre = [-1 for _ in range(n)]
        nums.sort()
        max, index = 0, -1
        for i in range(n):
            for j in range(i - 1, -1, -1):
                if nums[i] % nums[j] == 0:
                    if 1 + count[j] > count[i]:
                        count[i] = 1 + count[j]
                        pre[i] = j
            if count[i] > max:
                max = count[i]
                index = i

        res = []
        while index != -1:
            res.append(nums[index])
            index = pre[index]
        return res
