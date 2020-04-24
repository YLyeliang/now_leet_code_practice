# 给定一个无序的整数数组，找到其中最长上升子序列的长度。
#
# 示例:
#
# 输入: [10,9,2,5,3,7,101,18]
# 输出: 4
# 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
# 说明:
#
# 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
# 你算法的时间复杂度应该为 O(n2) 。
# 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

# 动态规划：
# 一、定义动态规划数组dp,由于是最长上升子序列，定义dp[i]为以i结尾的数组的最长上升子序列。
# 二、定义状态转移方程：由于有多种上升子序列，因此每一次决定dp[i]时需要遍历之前所有的数字，找到最长序列；
# 即必须保证nums[i]>nums[j], j<i. 则方程为： dp[i]=max(dp[j])+1
# 三、定义初始状态：dp[0]=1
class Solution(object):
    def lengthOfLIS(self,nums):
        if not nums:
            return 0
        dp =[]
        for i in range(len(nums)):
            dp.append(0)
            for j in range(i):
                if nums[i]>nums[j]:
                    dp[i]=max(dp[i],dp[j]+1)

        return max(dp)

# 贪心+二分查找：
# 如果要使得上升子序列尽可能的长，则需要让序列上升得尽可能慢，则每次序列中新增的数应该是最小的。
# 考虑一个数组d[i],表示长度为len(d)的上升子序列的末尾元素最小值，开始时len=1,d[1]=nums[0]
# 一次遍历nums中的数字，并更新d的值，如果nums[i]>d[len],那么直接将数新增到d中，并len+=1
# 如果nums[i]<=d[len],则找到d[i-1]<nums[j]<d[i]的下标i，并将其替换：d[i]=nums[j]。
# 这样，每次迭代时，保证序列d[]至当前长度时的上升序列中元素尽可能的小。

# 以输入序列 [0, 8, 4, 12, 2][0,8,4,12,2] 为例：
# 第一步插入 00，d = [0]d=[0]；
# 第二步插入 88，d = [0, 8]d=[0,8]；
# 第三步插入 44，d = [0, 4]d=[0,4]；
# 第四步插入 1212，d = [0, 4, 12]d=[0,4,12]；
# 第五步插入 22，d = [0, 2, 12]d=[0,2,12]。

class Solution(object):
    def lengthOfLIS(self,nums):
        d=[]
        for n in nums:
            if not d or d[-1]<n:
                d.append(n)
            else:
                l,r =0, len(d)-1
                loc=r
                while l<=r:
                    mid = (l+r)//2
                    if d[mid]>=n:
                        loc=mid
                        r=mid-1
                    else:
                        l=mid+1
                d[loc]=n
        return len(d)


solver=Solution()
arr=[10,9,2,5,3,7,101,18]
num=solver.lengthOfLIS(arr)
print(num)

