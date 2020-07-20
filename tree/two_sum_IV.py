# Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
#
# Example 1:
#
# Input:
#     5
#    / \
#   3   6
#  / \   \
# 2   4   7
#
# Target = 9
#
# Output: True
#
#
# Example 2:
#
# Input:
#     5
#    / \
#   3   6
#  / \   \
# 2   4   7
#
# Target = 28
#
# Output: False

# [2,3,4,5,6,7]
# 分析：普通解法，考虑到BST的性质为左小右大，且中序遍历为有序数组。可以先中序遍历得到有序数组，然后考虑数组中是否右匹配的两个元素。
# time:O(n) space:O(n)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:

        num = []

        def inorder(root):
            if not root: return None
            inorder(root.left)
            num.append(root.val)
            inorder(root.right)

        inorder(root)
        i, j = 0, len(num) - 1
        while i < j:
            if num[i] + num[j] == k:
                return True
            elif num[i] + num[j] > k:
                j -= 1
            else:
                i += 1
        return False

# 第二种：利用BST的性质，对于每个结点，检查k-node.val是否存在于这个BST中。
# time:O(nlogn) space:O(logn)

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:

        def dfs(root,cur,k):
            if not cur: return False
            return search(root,cur,k-cur.val) or dfs(root,cur.left,k) or dfs(root,cur.right,k)

        def search(root,cur,val):
            if not root:return False
            if root.val==val and root!=cur:
                return True
            elif root.val <val:
                return search(root.right,cur,val)
            elif root.val>val:
                return search(root.left,cur,val)

        return dfs(root,root,k)



