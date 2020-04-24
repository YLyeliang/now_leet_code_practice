# 给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。
# 示例:
# 给定有序数组: [-10,-3,0,5,9],
#
# 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
#
#           0
#          / \
#        -3   9
#        /   /
#      -10  5

# 二叉搜索树（BST）的定义：
# 对于树中的所有子树都有，左子树上的值都小于根节点的值，右子树上的值都大于根节点上的值。
# 总结一下就是，树的中序遍历可以得到一个升序序列。
# 解法：根据BST的定义，可以知道，根节点一定取数组的中止，并根据中止，左侧的为左子树，
# 右侧的为右子树，然后递归求解，即可得到最小高度的BST。

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def sortedArrayToBST(self, nums):
        def dfs(nums,L,R):
            if L>R: return None
            mid=(L+R)//2
            ptr=TreeNode(nums[mid])
            ptr.left = dfs(nums,L,mid-1)
            ptr.right=dfs(nums,mid+1,R)
            return ptr
        return dfs(nums,0,len(nums)-1)

test=Solution()
a=test.sortedArrayToBST([-10,-3,0,5,9])
print(a)

