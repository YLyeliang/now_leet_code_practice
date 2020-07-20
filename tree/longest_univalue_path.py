# Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
# The length of path between two nodes is represented by the number of edges between them.

# 分析:该问题返回一个具有相同值的最长节点路径值。采用DFS的方法遍历一颗BT，对于每个节点，可以设置其最长路径为左子树的最长路径+右子树的最长路径，并建立一个max_len用于保存最长路径值。



class Solution:
    def longestUnivaluePath(self,root: TreeNode) ->int:
        
        def dfs(node,max_len):
            if not node:return 0,max_len
            left,max_len=dfs(node.left,max_len)
            right,max_len=dfs(node.right,max_len)
            curr_left,curr_right=0,0
            if node.left and node.left.val==node.val:
                curr_left=left+1
            if node.right and node.right.val==node.val:
                curr_right=right+1
            max_len=max(max_len,curr_left+curr_right)
            return max(curr_right,curr_left),max_len

        _,max_len=dfs(node,0)
        return max_len
        
