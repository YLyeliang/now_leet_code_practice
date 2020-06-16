# 输入一棵二叉树的根节点，求该树的深度。
# 从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

# 树的遍历方式总分为两类：深度优先搜索（DFS）、广度优先搜素（BFS）
# 常见DFS：前序、中序、后序遍历
# 常见BFS：层序遍历

# 一、 DFS
# 后序遍历/DFS一般采用递归或栈来实现。
# 采用递归的方式进行。 树的深度由左右子树决定，其深度等于左右子树中最深的+1.
# 则可得到递归公式max(left,right)+1
# time: O(N) space:O(N)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root) -> int:
        if not root: return 0
        return max(self.maxDepth(root.left),self.maxDepth(root.right))+1


# 二、 BFS
# 树的层序遍历 / 广度优先搜索往往利用 队列 实现。
# 关键点： 每遍历一层，则计数器 +1 ，直到遍历完成，则可得到树的深度。
# 步骤：
# 特例处理： 当 root​ 为空，直接返回 深度 0。
# 初始化： 队列 queue （加入根节点 root ），计数器 res = 0。
# 循环遍历： 当 queue 为空时跳出。
# 初始化一个空列表 tmp ，用于临时存储下一层节点；
# 遍历队列： 遍历 queue 中的各节点 node ，并将其左子节点和右子节点加入 tmp；
# 更新队列： 执行 queue = tmp ，将下一层节点赋值给 queue；
# 统计层数： 执行 res += 1 ，代表层数加 11；
# 返回值： 返回 res 即可。
class Solution:
    def maxDepth(self, root) -> int:
        if not root: return 0
        queue=[root]
        res=0
        while queue:
            tmp=[]
            for node in queue:
                if node.left:
                    tmp.append(node.left)
                if node.right:
                    tmp.append(node.right)
            res+=1
            queue=tmp
        return res
