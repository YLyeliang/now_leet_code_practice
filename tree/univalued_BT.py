# A binary tree is univalued if every node in the tree has the same value.
#
# Return true if and only if the given tree is univalued.
#
# Example 1:
#
# Input: [1,1,1,1,1,null,1]
# Output: true
# Example 2:
#
#
# Input: [2,2,2,5,2]
# Output: false
# Note:
#
# The number of nodes in the given tree will be in the range [1, 100].
# Each node's value will be an integer in the range [0, 99].

# 问题:给定一棵二叉树，判断所有结点是否为单一值。
# 直接遍历判断两个结点的值是否相同即可.



class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root:return True
        if root.left and root.left.val!=root.val:return False
        if root.right and root.right.val!=root.val:return False
        left=self.isUnivalTree(root.left)
        right=self.isUnivalTree(root.right)
        return left and right
