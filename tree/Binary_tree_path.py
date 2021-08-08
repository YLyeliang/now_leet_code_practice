# Given a binary tree, return all root-to-leaf paths.
import collections


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# dfs+ stack, iterative.
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if not root: return []
        result = []
        stack = [(root, "")]
        while stack:
            node, ls = stack.pop()
            if not node.left and not node.right:
                result.append(ls + f'{node.val}')
            if node.right:
                stack.append((node.right, ls + f'{node.val}->'))
            if node.left:
                stack.append((node.left, ls + f'{node.val}->'))
        return result


# bfs + queue
def binaryTreePaths2(self, root):
    if not root:
        return []
    res, queue = [], collections.deque([(root, "")])
    while queue:
        node, ls = queue.popleft()
        if not node.left and not node.right:
            res.append(ls + str(node.val))
        if node.left:
            queue.append((node.left, ls + str(node.val) + "->"))
        if node.right:
            queue.append((node.right, ls + str(node.val) + "->"))
    return res


# dfs recursively
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if not root: return []
        res = []
        self.dfs(root, "", res)
        return res

    def dfs(self, root, ls, res):
        if not root.left and not root.right:
            res.append(ls + f'{root.val}')
        if root.right:
            self.dfs(root.right, ls + f'{root.val}->', res)
        if root.left:
            self.dfs(root.left, ls + f'{root.val}->', res)
