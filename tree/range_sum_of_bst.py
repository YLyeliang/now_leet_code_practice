# 给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。
#
# 二叉搜索树保证具有唯一的值。
#
#  
#
# 示例 1：
#
# 输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
# 输出：32
# 示例 2：
#
# 输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
# 输出：23

# 递归方法：// 2. 根据BST的左小右大的性质进行求解
#



# 迭代方法，利用栈或者队列
class Solution(object):
    def rangeSumBST(self, root, L, R):
        ans = 0
        stack = [root]
        while stack:
            node = stack.pop()
            if node:
                if L <= node.val <= R:
                    ans += node.val
                if L < node.val:
                    stack.append(node.left)
                if node.val < R:
                    stack.append(node.right)
        return ans