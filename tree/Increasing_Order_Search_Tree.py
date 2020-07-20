# Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.
#
# Example 1:
# Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
#
#        5
#       / \
#     3    6
#    / \    \
#   2   4    8
#  /        / \
# 1        7   9
#
# Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
#
#  1
#   \
#    2
#     \
#      3
#       \
#        4
#         \
#          5
#           \
#            6
#             \
#              7
#               \
#                8
#                 \
#                  9

# 分析：该问题给定一颗BST，需要按照中序遍历的顺序对其重新排列，排列后的二叉树以最左侧（最小）的结点为根节点，并且每个结点只有一个右节点。
# 可以直接使用中序遍历遍历整颗BST，并建立一个新树，然后按照中序遍历的顺序为这颗新树添加结点，最后返回这颗树即可。但是建立新树需要spaceO(n)
# 优化：不建立一棵新树，直接使用中序遍历的方式建立单向链表即可。对于每个结点，其结果res的根节点为左结点，即root.left+root+root.right.

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    res=TreeNode()
    def increasingBST(self, root: TreeNode) -> TreeNode:
        node=self.res
        def dfs(root):
            if not root:return None
            dfs(root.left)
            self.res.right=TreeNode(root.val)
            self.res=self.res.right
            dfs(root.right)
        dfs(root)
        return node.right


class Solution:
    def increasingBST(self, root: TreeNode,tail=None) -> TreeNode:
        if not root:return tail
        res=self.increasingBST(root.left,root)
        root.left=None
        root.right=self.increasingBST(root.right,tail)
        return res

