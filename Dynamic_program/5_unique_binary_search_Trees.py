# Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
#
# Example:
#
# Input: 3
# Output: 5
# Explanation:
# Given n = 3, there are a total of 5 unique BST's:
#
#    1         3     3      2      1
#     \       /     /      / \      \
#      3     2     1      1   3      2
#     /     /       \                 \
#    2     1         2                 3
#
#
# Constraints:
#
# 1 <= n <= 19


# 分析: 这里是给定一个值n，问有多少课结构独立的BST，所有节点包含1...n。
# n=1时，为1种。即 1
#n=2时，为2种；
# 1         2
#  \       /
#   2     1
#n=3时，为5种，

class Solution:
    def numTrees(self,n:int)->int:
        dp = [0] *(n+1)
        dp[0]=1
        for i in range(1,n+1):
            for j in range(i):
                dp[i]+=dp[j]*dp[i-j-1]
        return dp[-1]

