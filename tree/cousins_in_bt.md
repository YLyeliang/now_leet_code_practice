In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:

![avatar](images/q1248-01.png)

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

![avatar](images/q1248-02.png)

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

![avatar](images/q1248-03.png)

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 
Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.

问题：对于二叉树，根节点的深度为0，对于深度为k的任一结点，其子节点深度为k+1,若两个结点有相同深度不同的父节点，则为余弦结构。
给定两个结点，判断是否为余弦结构。

分析：可以使用层序遍历来遍历二叉树，

```python
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        
```