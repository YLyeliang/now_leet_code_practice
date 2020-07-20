Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:

![](images/sum-of-root-to-leaf-binary-numbers.png)

Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.

```python
class Solution:
    def sumRootToLeaf(self, root: TreeNode,val=0) -> int:
        if not root: return 0
        val = val*2+root.val
        if not root.left and not root.right :return val
        return self.sumRootToLeaf(root.left,val)+self.sumRootToLeaf(root.right,val)
        
        
```