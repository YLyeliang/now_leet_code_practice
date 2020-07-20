# Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.
#
# Example 1:
# Input:
#     1
#    / \
#   0   2
#
#   L = 1
#   R = 2
#
# Output:
#     1
#       \
#        2
# Example 2:
# Input:
#     3
#    / \
#   0   4
#    \
#     2
#    /
#   1
#
#   L = 1
#   R = 3
#
# Output:
#       3
#      /
#    2
#   /
#  1

# 分析： 对于一颗BST，记住其左小右大的性质。对于给定的区间[L,R]。如果需要对其进行修剪，可以考虑当前结点的值与区间的对比。如果当前结点值大于区间右值R，则右子树可以全部抛弃,返回左子树；同理，如果节点值小于区间L，则左子树可以全部抛弃。
# 使用递归的方式，递归的取树的左子树和右子树，可以得到最终的结果。
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:
        if not root:return None

        if root.val>R: return self.trimBST(root.left,L,R)
        if root.val<L: return self.trimBST(root.right,L,R)

        root.left=self.trimBST(root.left,L,R)
        root.right=self.trimBST(root.right,L,R)

        return root
