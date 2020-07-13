# Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
#
# You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
#
# Example 1:
#
# Input:
# 	Tree 1                     Tree 2
#           1                         2
#          / \                       / \
#         3   2                     1   3
#        /                           \   \
#       5                             4   7
# Output:
# Merged tree:
# 	     3
# 	    / \
# 	   4   5
# 	  / \   \
# 	 5   4   7
#
#
# Note: The merging process must start from the root nodes of both trees.

# 分析：将两棵二叉树叠加在一块，其中一棵树会覆盖另一棵。其中会有重叠的结点，这些结点的合并规则为相加。未重叠的结点则使用新的结点。
# 这里的话，需要同时遍历两棵二叉树，为了减少空间复杂度，直接在其中一棵树进行合并操作。
# 具体细节：当两个结点均为空时，返回None。当有一个结点为空时，使用另一个结点的值，若两个都不为空，则使用相加的值
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if t1 and t2:
            t1.val+=t2.val
            t1.left=self.mergeTrees(t1.left,t2.left)
            t1.right=self.mergeTrees(t1.right,t2.right)
            return t1
        else:
            return t1 or t2



