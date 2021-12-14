# leetcode力扣刷题训练
持续更新中：

本仓库为作者平时刷leetcode时练习的一些题目，先易后难，目前大部分题目均为leetcode easy problems.后续会慢慢更新刷过的medium and hard problems.
目前主要包括以下两个部分：
1. 树相关的题目（主要是围绕二叉树和二叉搜索树的问题，解法方面主要涵盖了DFS、BFS、递归、迭代的解法）
2. 动态规划的题目（leetcode上面的easy to medium，正在更新中）
3. 其它题目（其它一些高star的仓库的练习题目，like python-100-days、剑指offer、fucking_algorithms、以及之前秋招时遇到的一些公司笔试题目）

# 刷题心得
tree部分，目前总的来说，easy题部分主要就是针对bt和bst的问题。对于bst，利用好其‘左小右大’的性质，其中序遍历可以得到有序数组，结合DFS和BFS基本可以解决大部分问题。
对于bt，就是dfs和bfs的套路了，前序中序后序等等。
有一个万能递归框架(DFS，前序中序后序)
```python
class Solution:
    def traverse(self,root):
        if not root:return None
        # 在这里操作结点即前序
        self.traverse(root.left)
        # 在这里操作结点即中序
        self.traverse(root.right)
        # 在这里操作结点即后序
```

