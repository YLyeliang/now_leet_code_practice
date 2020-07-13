# Given a n-ary tree, find its maximum depth.
#
# The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
#
# Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
#
#
#
# Example 1:
#          1
#        / | \
#      3   2   4
#     / \
#    5   6
# Input: root = [1,null,3,2,4,null,5,6]
# Output: 3

# 分析：给出的是一个N叉树，依然可以使用DFS和BFS的方法对其遍历，并定义一个depth，在遍历时每寻找到一个children，便depth+1
# DFS：直接使用递归的方式对每跳路径进行搜索，比较每个路径的长度。
# BFS：与DFS一样，这里采用迭代的方式，构建双端队列，按照层序遍历的方式依次将节点加入到队列中。


# DFS
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root: return 0
        depth = 0;
        for child in root.children:
            depth = max(depth, self.maxDepth(child))
        return 1 + depth


# BFS
import collections
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root: return 0
        depth=0
        queue=collections.deque([root])
        while queue:
            depth+=1
            for i in range(len(queue)):
                node=queue.popleft()
                for child in node.children:
                    if child is not None:
                        queue.append(child)
        return depth


