# Given a binary tree, return the tilt of the whole tree.
#
# The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
#
#
# The tilt of the whole tree is defined as the sum of all nodes' tilt.
#
# Example:
# Input:
#          1
#        /   \
#       2     3
# Output: 1
# Explanation:
# Tilt of node 2 : 0
# Tilt of node 3 : 0
# Tilt of node 1 : |2-3| = 1
# Tilt of binary tree : 0 + 0 + 1 = 1
# Note:
#
# The sum of node values in any subtree won't exceed the range of 32-bit integer.
# All the tilt values won't exceed the range of 32-bit integer.

# 题目解释：给定一颗二叉树，返回树的坡度。单个节点的坡度定义为：左子树的所有节点值之和与右子树的所有节点值之和的差值绝对值。null节点可以视为0。
# 整棵树的坡度为，所有节点的坡度之和。

# 方法：考虑递归的方法，当前节点的坡度为左子树之和与右子树之和的差值，通过递归的方式得到各个节点的坡度，并将结果存入数组中，最后求和处理(或者逐个将节点的坡度相加）。

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        self.ans=0

        def _sum(node):
            if not node: return 0
            left, right= _sum(node.left),_sum(node.right)
            self.ans+=abs(left-right)
            return node.val+left+right

        _sum(root)

        return self.ans