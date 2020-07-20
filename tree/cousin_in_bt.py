class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

import collections

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        if not root: return False
        stack = collections.deque([root])
        while stack:
            flag_x = False
            flag_y = False
            for i in range(len(stack)):
                node = stack.popleft()
                if node.val == x: flag_x = True
                if node.val == y: flag_y = True
                if node.left and node.right:
                    if node.left.val == x and node.right.val == y: return False
                    if node.left.val == y and node.right.val == x: return False
                if node.left: stack.append(node.left)
                if node.right: stack.append(node.right)
            if flag_x and flag_y: return True

        return False

