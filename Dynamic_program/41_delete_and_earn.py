# Given an array nums of integers, you can perform operations on the array.
#
# In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element
# equal to nums[i] - 1 or nums[i] + 1.
#
# You start with 0 points. Return the maximum number of points you can earn by applying such operations.
#
#
#
# Example 1:
#
# Input: nums = [3,4,2]
# Output: 6
# Explanation: Delete 4 to earn 4 points, consequently 3 is also deleted.
# Then, delete 2 to earn 2 points.
# 6 total points are earned.
# Example 2:
#
# Input: nums = [2,2,3,3,3,4]
# Output: 9
# Explanation: Delete 3 to earn 3 points, deleting both 2's and the 4.
# Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
# 9 total points are earned.

# Constraints:
#
# 1 <= nums.length <= 2 * 10^4
# 1 <= nums[i] <= 10^4


# 问题：给定整型数组nums,每一次删除一个nums[i],可以得到值为nums[i]的分数，同时，将nums中所有等于nums[i]-1或nums[i]+1的元素删除，求最大分数。

# 方案：分析例子2，因为每次选择一个数，需要删除+1 -1大小的相邻数字，而同一个数字可以无限选择，那么nums=[2,2,3,3,3,4]等价于[2*2,3*3,4] [4, 9, 4]
# 则可以首先对整个数组进行排序，然后类似于house robber，间隔取数，组成最大数字。或者使用dp来存储从0到2 * 10^4的数字。
# 通过更新两个变量 skip_i和take_i来迭代求取子问题的解:当...第i个值时，以i截止时的最大和是多少。
# 则DP公式：
# take[i] = skip[i-1] + nums[i]
# skip[i] = max(take[i-1], skip[i-1])


from typing import List


class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        n = 10001
        dp = [0] * n
        for num in nums:
            dp[num] += num
        take, skip = 0, 0
        for i in range(n):
            takei = skip + dp[i]
            skipi = max(take, skip)
            take = takei
            skip = skipi
        return max(take, skip)


# 上述使用list存储整个数组，并for循环消耗空间、时间过长，可以使用dict来进行缩减
# TODO:未写完
def deleteAndEarn(self, nums: List[int]) -> int:
    dp = {}
    for num in nums:
        if num not in dp.keys():
            dp[num] = num
            el
        dp[num] += num

    take, skip = 0, 0
    for key, val in dp.items():
        if not key - 1 in dp.keys():
            take = skip
            skip += dp[key]

        else:
            skipi = max(skip + dp[key], take)
            take = skip
            skip = skipi
    return skip


a = [3, 4, 2]
deleteAndEarn(0, a)
