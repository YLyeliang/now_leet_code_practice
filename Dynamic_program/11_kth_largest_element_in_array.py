# Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
#
# Example 1:
#
# Input: [3,2,1,5,6,4] and k = 2
# Output: 5
# Example 2:
#
# Input: [3,2,3,1,2,4,5,5,6] and k = 4
# Output: 4
# Note:
# You may assume k is always valid, 1 ≤ k ≤ array's length.

# 问题：找到无序数组中的第k个最大数。
# 暴力解法：排序之后索引第k个即可。但这不是本题的意义。Time O（nlogn)
# 分析：需要找到一个O(n)的解法。由于是找到第k个最大的数字，因此可以构建一个长度为k的有序dp数组，在遍历时，
# 每找到一个比dp中最小值更大的数字，就将dp中最小的数字进行替换。dp中最小的即为第k个最大数。

# class Solution:
#     def findKthLargest(self,nums,k)-> int:
#         dp=[]
#         for i in nums:
#             if len(dp)<k:
#                 dp.append(i)
#             elif len(dp)>=k:
#                 m=min(dp)
#                 if i>m:
#                     dp.remove(m)
#                     dp.append(i)
#         return min(dp)

class Solution:
    def findKthLargest(self,nums,k)-> int:
        nums.sort()
        return nums[-k]

a=[3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6]
print(len(a))
sol=Solution()
sol.findKthLargest(a,20)