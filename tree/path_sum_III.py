# You are given a binary tree in which each node contains an integer value.
#
# Find the number of paths that sum to a given value.
#
# The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
#
# The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

# 一、暴力解法
# 1. Brute Force: O(nlogn) ~ O(n^2)
# 1.1 High level walk-through:
# (Define return) Define a global var: self.numOfPaths in the main function.
# (1st layer DFS) Use recursive traverse to go through each node (can be any order: pre, in, post all fine).
# (2nd layer DFS) For each node, walk all paths. If a path sum equals to the target: self.numOfPaths += 1
# Return result: return self.numOfPaths
# 1.2 Complexity analysis
# 1.2.1 Space
# Space complexity is O(1), due to there is no extra cache. However, for any recursive question, we need to think about stack overflow, namely the recursion should not go too deep.
# Assume we have n TreeNodes in total, the tree height will vary from O(n) (single sided tree) to O(logn)(balanced tree).
# The two DFS will go as deep as the tree height.
# 1.2.2 Time
# Time complexity depends on the two DFS.
# 1st layer DFS will always take O(n), due to here we will take each node out, there are in total n TreeNodes
# 2nd layer DFS will take range from O(n) (single sided tree) to O(logn)(balanced tree). This is due to here we are get all the paths from a given node. The length of path is proportional to the tree height.
# Therefore, the total time complexity is O(nlogn) to O(n^2).


class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        # define global return var
        self.numOfPaths = 0
        # 1st layer DFS to go through each node
        self.dfs(root, sum)
        # return result
        return self.numOfPaths

    def dfs(self, node, sum):
        if not node: return None
        self.test(node, sum)
        self.dfs(node.left, sum)
        self.dfs(node.right, sum)

    def test(self, node, sum):
        if not node: return None
        if node.val == sum:
            self.numOfPaths += 1
        self.test(node.left, sum - node.val)
        self.test(node.right, sum - node.val)

# 二、路径和记忆：O(n)
# when move to a different branch, the currPathSum is no longer available, hence remove one.
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        # define global result and path
        self.result = 0
        cache = {0: 1}

        # recursive to get result
        self.dfs(root, sum, 0, cache)
        # return result
        return self.result

    def dfs(self, node, sum, currPathSum, cache):
        if not node: return None
        # calculate currPathSum and required oldPathSum
        currPathSum += node.val
        oldPathSum = currPathSum - sum
        # update result and cache
        self.result += cache.get(oldPathSum, 0)
        cache[currPathSum] = cache.get(currPathSum, 0) + 1

        # dfs break down
        self.dfs(node.left, sum, currPathSum, cache)
        self.dfs(node.right, sum, currPathSum, cache)

        cache[currPathSum] -= 1
