# Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
#
# Example:
# Given a binary tree
#           1
#          / \
#         2   3
#        / \
#       4   5
# Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
#
# Note: The length of path between two nodes is represented by the number of edges between them.

# 分析：这个题目要求的是找到任意两个节点的最长路径。
# 先分析一下，对于每一个节点，它的最长路径=左子树最长路径+右子树最长路径，比如，值为2的节点，其最长路径为4-2-5，左右子树长度均为1.其最长为=1+1
# 比如值为1的节点，长度=2+1=3。
# 这样，就可以在遍历的时候，依次计算每个节点的长度，并取最大值得到最终的结果。


class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 0

        def depth(p):
            if not p: return 0
            left, right = depth(p.left), depth(p.right)
            self.ans = max(self.ans, left + right)
            return 1 + max(left, right)

        depth(root)
        return self.ans


