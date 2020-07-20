# Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.
#
# For example,
#
# Given the tree:
#         4
#        / \
#       2   7
#      / \
#     1   3
#
# And the value to search: 2
# You should return this subtree:
#
#       2
#      / \
#     1   3
# In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.
#
# Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.

# 分析：该问题就是给定一个值，在BST中找到等于这个值的结点，返回以这个结点为根结点的子树。
# 利用BST的性质，找到对应的结点，返回结点即可。


class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:return None

        if root.val==val: return root
        if root.val>val: return self.searchBST(root.left,val)
        if root.val<val:return self.searchBST(root.right,val)
