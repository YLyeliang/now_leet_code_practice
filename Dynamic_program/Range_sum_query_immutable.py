# Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
#
# Example:
# Given nums = [-2, 0, 3, -5, 2, -1]
#
# sumRange(0, 2) -> 1
# sumRange(2, 5) -> -1
# sumRange(0, 5) -> -3
# Note:
# You may assume that the array does not change.
# There are many calls to sumRange function.

# 分析：给定整数数组，计算指定索引之间的数的和值，i<=j。
# 1.最简单的方法就是每次调用时搜索这几个下标的数字进行求和，但是在重复调用时耗时非常大，若一次调用O(N)时间，调用m次则有O(m*n)，容易超出限定时间。
# 2.改进的方法，可以创建另一个数组，保存从0到当前下标的和值，即sum=[-2,-2,1,-6,-5,-6]。则如果要计算sumrange(i,j)，只需要计算sum[j]-sum[i]即可。
# 该方法只需要第一次构建sum数组时花费O(n)时间，之后每次调用均为O(1)时间，space为O(n).


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
class NumArray:

    def __init__(self, nums: List[int]):
        self.nums=nums
        self.sum=[0]
        for i,num in enumerate(nums):
            self.sum.append(num+self.sum[i])

    def sumRange(self, i: int, j: int) -> int:
        return self.sum[j+1]-self.sum[i]

