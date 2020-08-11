# You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
# That means the first house is the neighbor of the last one.
# Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

# Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

# Example 1:

# Input: [2,3,2]
# Output: 3
# Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
#             because they are adjacent houses.
# Example 2:

# Input: [1,2,3,1]
# Output: 4
# Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
#             Total amount you can rob = 1 + 3 = 4.

# 分析：这里就是给定一个数组，其首尾相接构成环，不能同时取相邻数字，求从头到尾取到的数字的最大值。
# 跟I一样，也是利用dp数组来求取。dp[i]表示索引为i时的最大数字和，动态转移方程依然是dp[i]=max(dp[i-1],dp[i-2]+s[i]).
# 但是要考虑到环的问题，有环的情况下，由于首尾相接，不同同时取0和n-1的值。因此，这里可以分解为两个dp问题。其中一个是
# 解决0~n-2、另外一个是解决1~n-1。这样取他们的最大值即可。

class Solution:
    def rob(self,nums) -> int:
        if len(nums)<2: return nums[0] if len(nums)==1 else 0
        return max(self.robb(nums,0,len(nums)-1),self.robb(nums,1,len(nums)))

    def robb(self,nums,l,r):
        pre,cur=0,0
        for i in range(l,r):
            tmp=max(pre+nums[i],cur)
            pre=cur
            cur=tmp
        return cur+

