# Given an n-ary tree, return the preorder traversal of its nodes' values.
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
#   3   2   4
#  / \
# 5   6
#
#
# Input: root = [1,null,3,2,4,null,5,6]
# Output: [1,3,5,6,2,4]
# Example 2:
#
#
#
# Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
# Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]

# 解析：该问题就是针对N叉树的一个前序遍历。N叉树的前序遍历，即是先根节点，然后依次对子树按照从左至右的顺序进行遍历。
# 这里按照二叉树的方式进行遍历即可，只不过对于left & right结点，是以数组的方式进行。


"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


# 递归解法
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        res = []

        def dfs(root):
            if not root: return None
            res.append(root.val)
            if root.children:
                for node in root.children:
                    dfs(node)

        dfs(root)
        return res

# 迭代解法：使用数组构建队列，该方法只需要建议一个队列，不需要将函数压入栈中，所以严格上来讲空间复杂度要更低。时间复杂度与递归一致，均为O(n)。
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        res,q=[],root and [root]
        while q:
            node=q.pop()
            res.append(node.val)
            q+=[child for child in node.children[::-1] if child]
        return res
