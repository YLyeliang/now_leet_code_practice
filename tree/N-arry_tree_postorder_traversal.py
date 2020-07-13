# Given an n-ary tree, return the postorder traversal of its nodes' values.
#
# Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
#
#
#
# Follow up:
#
# Recursive solution is trivial, could you do it iteratively?
#
#
#
# Example 1:
#       1
#     / | \
#   3   2   4
#  / \
# 5   6
#
# Input: root = [1,null,3,2,4,null,5,6]
# Output: [5,6,3,2,4,1]
# Example 2:
#
#
#
# Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
# Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]

#分析：与前序遍历的操作一样，只需要更改遍历过程中取val值的顺序即可。

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

# 递归解法
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        res = []

        def dfs(root):
            if not root: return None

            if root.children:
                for node in root.children:
                    dfs(node)
            res.append(root.val)

        dfs(root)
        return res


# 迭代解法
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        res,q=[],root and [root]
        while q:
            node=q.pop()
            res.append(node.val)
            q.extend(node.children)
        return res[::-1]





