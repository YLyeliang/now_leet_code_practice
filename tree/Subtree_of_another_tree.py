# Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
#
# Example 1:
# Given tree s:
#
#      3
#     / \
#    4   5
#   / \
#  1   2
# Given tree t:
#    4
#   / \
#  1   2
# Return true, because t has the same structure and node values with a subtree of s.
#
#
# Example 2:
# Given tree s:
#
#      3
#     / \
#    4   5
#   / \
#  1   2
#     /
#    0
# Given tree t:
#    4
#   / \
#  1   2
# Return false.

# 解法一：遍历整个二叉树s,对于每个节点，判断其子树是否与二叉树t相同，如果相同，则返回true,else false. 该方法仍然利用递归方式，
# 判断两棵树是否相同，可以使用遍历的方式，明前当前节点的任务：如果两个节点同时为空，则两者相同，如果两个有一个非空，则不相同。然后剩下的交给递归去执行。
# 时间复杂度来说比较复杂， 因为每个具有相同值的节点均需进行依次判断，需要O(s*t)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:

        def isMatch(s, t):
            if s is None and t is None: return True
            if s is None or t is None: return False

            if s.val == t.val:
                if isMatch(s.left, t.left) and isMatch(s.right, t.right):
                    return True
                else:
                    return False

        if isMatch(s, t):
            return True
        if s is None:
            return False

        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
