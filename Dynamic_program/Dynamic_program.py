# 给定一个包含非负整数的 m x n 网格，
# 请找出一条从左上角到右下角的路径，
# 使得路径上的数字总和为最小。（机器人只能向下或向右走）
class walking(object):
    def __init__(self,arr):
        self.arr=arr
        self.m=len(arr)
        self.n=len(arr[0])

    def run(self):
        arr=self.arr
        m=self.m
        n=self.n
        if m <= 0 or n <= 0:
            return False
        dp=[[0]*n for _ in range(m)]
        dp[0][0]=arr[0][0]
        # initialize the left column
        for i in range(1,m):
            dp[i][0]=dp[i-1][0]+arr[i][0]
        # initialize the top row
        for i in range(1,n):
            dp[0][i]=dp[0][i-1]+arr[0][i]
        # inference the dp m-1 n-1
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+arr[i][j]
        return dp[m-1][n-1]
solver=walking([[1,3,1],[1,5,1],[4,2,1]])
print(solver.run())

# 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
# 条件：数组不变，多次调用
# O（1）解法，动态规划，sum(i,j)=sum(j)-sum(i-1)
class NumArray:

    def __init__(self, nums):
        self.dp = [0]   # 保存至当前索引的数字之和
        for i in range(len(nums)):
            self.dp.append(nums[i] + self.dp[i])

    def sumRange(self, i: int, j: int) -> int:
        return self.dp[j + 1] - self.dp[i]
# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
obj= NumArray([-2,0,3,-5,2,-1])
print(obj.sumRange(0,2))

# 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
# 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
# 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
# （例如，"ace"是"abcde"的一个子序列，而"aec"不是）。示例 1: s = "abc", t = "ahbgdc" 返回 true.
# 解题步骤：
# 一、双指针
# s和t各一个指针，遍历t并与s的当前位置的字符进行比较，出现相同字符时，s+1，遍历结束后，
# 当s的长度等于字符串长度时则说明是子序列。 速度较慢，
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i,j=0,0
        while i<len(s) and j<len(t):
            if s[i]==t[j]:
                i+=1
                j+=1
            else:
                j+=1
        return True if i==len(s) else False

# 二：动态地规划起始位置，遍历s中的字符，并给定位置索引loc,遍历t中字符，当出现相同字符时，令loc为当前位置+1.并遍历下一个s中的字符，
# 若s的每一个字符都能在t中找到，则是子字符串。
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        loc=-1
        length=len(t)
        for i in s:
            tag=0
            for j in range(loc+1,length):
                if i==t[j]:
                    loc=j
                    tag=1
                    break
            if tag==0:
                return False
        return True










