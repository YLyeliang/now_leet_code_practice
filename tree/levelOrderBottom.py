# Binary Tree Level Order Traversal II
# Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root)



# 深度优先搜索进行递归的方式
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
        def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
            res=[]
            self.dfs(root,0,res)
            return res
    
    def dfs(self,root,level,res):
            if root:
            if len(res) < level+1:
                res.insert(0,[])
            res[-(level+1)].append(root.val)
            self.dfs(root.left,level+1,res)
            self.dfs(root.right,level+1,res)
# time:O(N),即遍历每一个点
# space: O(N)，存储N个节点的值


# DFS+stack迭代的方式
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
        def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        queue,res=collections.deque([(root,0)]),[]
        while queue:
            node, level=queue.popleft()
            if node:
                if level==len(res):
                    res.append([])
                res[level].append(node.val)
                queue.append((node.left,level+1))
                queue.append((node.right,level+1))
        return res[::-1]


# BFS+queue

