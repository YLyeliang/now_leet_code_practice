# Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
#
# For example, given the following triangle
#
# [
#      [2],
#     [3,4],
#    [6,5,7],
#   [4,1,8,3]
# ]
# The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
#
# Note:
#
# Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
#
# 给定三角形，找到自顶向下的最小路径和。每一次可以移动到下一行相邻的数字。
# 分析：很典型的动态规划问题，这里可以建立一个shape等于三角形的dp数组，其中dp[i]表示第i行时的路径和，当i>=2时，由于i=1有两个值，i=2时会有一个重叠值，这里重叠的值可以取最小。最后返回最后一行的min即可。

class Solution:
    def minimumTotal(self, triangle) -> int:
        dp=[[triangle[0][0]]]
        for i in range(1,len(triangle)):
            for j in range(len(triangle[i])):
                if j==0:
                    dp.append([dp[i-1][0]+triangle[i][0]])
                elif j==len(triangle[i])-1:
                    dp[i].append(dp[i-1][-1]+triangle[i][-1])
                else:
                    dp[i].append(min(dp[i-1][j-1]+triangle[i][j],dp[i-1][j]+triangle[i][j]))
        return min(dp[-1])

# 这里是构建了DP数组，需要额外的O(n) space。考虑到每次计算时只利用上一行的值，可以不额外构建dp数组，直接在原有数组上进行计算来释放空间。
class Solution:
    def minimumTotal(self, triangle) -> int:
        for i in range(1,len(triangle)):
            triangle[i][0]+=triangle[i-1][0]
            triangle[i][-1]+=triangle[i-1][-1]
            for j in range(1,len(triangle[i])-1):
                triangle[i][j]=min(triangle[i-1][j-1]+triangle[i][j],triangle[i-1][j]+triangle[i][j])
        return min(triangle[-1])


sol=Solution()
num=[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
print(sol.minimumTotal(num))


