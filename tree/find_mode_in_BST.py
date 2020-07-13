# Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
#
# Assume a BST is defined as follows:
#
# The left subtree of a node contains only nodes with keys less than or equal to the node's key.
# The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
# Both the left and right subtrees must also be binary search trees.
#
#
# For example:
# Given BST [1,null,2,2],
#
#    1
#     \
#      2
#     /
#    2
#
#
# return [2].

# 解决方法：考虑到对于一颗BST，其中序遍历得到的即为升序的结果，因此，只要在中序遍历的过程中，判断当前节点与前一个节点是否相同。如果相同，可以计数+1，如果不相同，则判断当前节点的计数与最大计数
# 的大小，如果计数一致，则将该节点的值加入到result中，如果计数大于max_count，则将result更新为当前节点的值，然后交给递归遍历。

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    prev = None
    max_count = 0
    current_count = 0
    result = []

    def findMode(self, root: TreeNode) -> List[int]:
        self.dfs(root)
        return self.result

    def dfs(self, node):
        if not node: return None

        self.dfs(node.left)
        self.current_count = 1 if node.val != self.prev else self.current_count + 1
        if self.current_count == self.max_count:
            self.result.append(node.val)
        elif self.current_count > self.max_count:
            self.result = [node.val]
            self.max_count = self.current_count
        self.prev = node.val
        self.dfs(node.right)
