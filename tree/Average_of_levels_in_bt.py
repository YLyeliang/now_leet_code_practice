# Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
# Example 1:
# Input:
#     3
#    / \
#   9  20
#     /  \
#    15   7
# Output: [3, 14.5, 11]
# Explanation:
# The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
# Note:
# The range of node's value is in the range of 32-bit signed integer.

# 分析：这里需要的是返回每一个层级的平均值。因此，解决方法就是使用层序遍历一棵二叉树，然后对每个层级的二叉树取平均值。
# 细节问题：可以创建一个双端队列，保存当前层级的所有结点，并使用len获取当前层级的结点个数，然后依次遍历完各个层级的结点，再继续下一个层级的结点。



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        que=[root]
        res=[]
        while que:
            n=len(que)
            sum=0
            for i in range(n):
                node=que.pop(0)
                sum+=node.val
                if node.left: que.append(node.left)
                if node.right: que.append(node.right)
            res.append(sum/n)
        return res


# 第二种方法：使用DFS的方法，建立一个二维矩阵，每一行[x,y]分别保存每个层级的和值与结点数目，最后做平均处理即可。

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        mat=[]
        def dfs(node,depth=0):
            if node:
                if len(mat) <=depth:
                    mat.append([0,0])
                mat[depth][0]+=node.val # sums up all values when traverse each node
                mat[depth][1]+=1    # every time traverse a node the number+1.
                dfs(node.left,depth+1)
                dfs(node.right,depth+1)
        dfs(root)
        return [s/n for s,n in mat]