# Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
#   找出任意两个节点之间的最小绝对差值
# Example:
#
# Input:
#
#    1
#     \
#      3
#     /
#    2
#
# Output:
# 1
#
# Explanation:
# The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
#
#
# Note:
#
# There are at least two nodes in this BST.
# This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/


# 解法：利用BST的性质，其中序遍历为升序数组，遍历整个数组，对比当前节点与之前节点的绝对差值，取最小的即可。
class Solution:
    prev=None
    min_diff=sys.maxsize
    def getMinimumDifference(self, root: TreeNode) -> int:
        def dfs(node):
            if node is None:return
            dfs(node.left)
            if self.prev is not None:
                self.min_diff=min(self.min_diff,abs(node.val-self.prev))
            self.prev=node.val
            dfs(node.right)
        dfs(root)
        return self.min_diff
