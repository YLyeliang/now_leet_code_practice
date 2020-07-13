# You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
#
# The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.
#
# Example 1:
# Input: Binary tree: [1,2,3,4]
#        1
#      /   \
#     2     3
#    /
#   4
#
# Output: "1(2(4))(3)"
#
# Explanation: Originallay it needs to be "1(2(4)())(3()())",
# but you need to omit all the unnecessary empty parenthesis pairs.
# And it will be "1(2(4))(3)".
# Example 2:
# Input: Binary tree: [1,2,3,null,4]
#        1
#      /   \
#     2     3
#      \
#       4
#
# Output: "1(2()(4))(3)"
#
# Explanation: Almost the same as the first example,
# except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.


# 分析：该问题是将一颗二叉树转换成带括号的字符串表示形式。其形式为'root(left)(right)',其中left和right又可以再次划分。
# 其中的细节问题，当left为空时，需要以()表示，当right为空时则可以省略这个括号。
# 经过上述分析，只需要定义当前节点该做的事情，通过判断其左右子节点是否存在，来给出不同的括号的值，最后通过递归，交给框架完成操作即可。

class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if not t: return ''
        left="({})".format(self.tree2str(t.left)) if (t.left or t.right) else ''
        right="({})".format(self.tree2str(t.right)) if t.right else ''
        return "{}{}{}".format(t.val,left,right)

class Solution:
    def tree2str(self,t):
        if not t: return ''
        res=str(t.val)
        if t.left:
            res+='('+self.tree2str(t.left)+')'
            if t.right:
                res+='('+self.tree2str(t.right)+')'
        elif t.right:
            res+='()('+self.tree2str(t.right)+')'
        return res


