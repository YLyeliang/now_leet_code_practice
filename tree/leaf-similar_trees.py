# Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.
#
#           3
#        5     1
#      6  2   9 8
#        7 4
# For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
#
# Two binary trees are considered leaf-similar if their leaf value sequence is the same.
#
# Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
#
#
#
# Constraints:
#
# Both of the given trees will have between 1 and 200 nodes.
# Both of the given trees will have values between 0 and 200

# 分析：这个问题需要解决的是给定两个二叉树，每个二叉树从左到右的叶节点构成一个数组。问两个二叉树的数组是否一致。
# 最直接的解决方法就是利用DFS遍历两棵树，并将叶节点的值保存到两个数组中，对比两个数组是否一致，该方法需要完全遍历两棵树，需要O(2N)time,O(2k)space，k为叶结点数。
# 优化：在遍历过程中，如果有任意一个有序的结点值不相等，则返回false.且可以不使用数组进行保存。考虑到两颗二叉树的叶节点位置不一定相同，找到叶节点需要迭代的次数也不一致。

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        res1=[]
        res2=[]
        def dfs(root,res):
            if not root:return None
            if not root.left and not root.right:res.append(root.val)
            dfs(root.left,res)
            dfs(root.right,res)

        dfs(root1,res1)
        dfs(root2,res2)
        return True if res1==res2 else False


# 优化，time:最坏情况下O(2n); space:O(1)
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:

        def dfs(root):
            if not root:return []
            if not (root.left or root.right):return [root.val]
            return dfs(root.left)+dfs(root.right)

        return dfs(root1)==dfs(root2)
