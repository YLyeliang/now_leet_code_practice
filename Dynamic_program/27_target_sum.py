# You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -.
# For each integer, you should choose one from + and - as its new symbol.
#
# Find out how many ways to assign symbols to make sum of integers equal to target S.
#
# Example 1:
#
# Input: nums is [1, 1, 1, 1, 1], S is 3.
# Output: 5
# Explanation:
#
# -1+1+1+1+1 = 3
# +1-1+1+1+1 = 3
# +1+1-1+1+1 = 3
# +1+1+1-1+1 = 3
# +1+1+1+1-1 = 3
#
# There are 5 ways to assign symbols to make the sum of nums be target 3.
#
#
# Constraints:
#
# The length of the given array is positive and will not exceed 20.
# The sum of elements in the given array will not exceed 1000.
# Your output answer is guaranteed to be fitted in a 32-bit integer.

# 问题：给定非负整数a1-an,和target S.有两个符号+与-。对于每个整数，从+和-中选择一个作为其新符号。找出所有的符号分配方式数目，使得整数的和等于target S.

# 分析：使用DP方法的整个思考过程：
# 1.类别
# 大部分DP问题都可以划分成几个类别。当较好地划分该问题的类别之后，可以使用对应类别的框架来解决问题。
# Question:将该题划分为下面类别中的一个
# 0/1 knapsack
# Unbounded Knapsack
# shortest path
# Fibonacci Sequence
# Longest Common Substring/Subsequence
# Answer: 0/1 Knapsack
# 为什么选择0/1背包？ capacity，即需要得到的target S. item为输入子集的数字， item的weight为数字本身。因此，可以划分为0/1背包问题。
# 为什么不是unbounded knapsack，另一个原因是这里的数字只能使用一次。

# 2.状态
# 为了达到最优解，我们需要跟踪哪些变量，
# Question: 决定状态变量。 根据0/1背包的通用规则，该类问题至少需要两个状态
# Answer: index and Current Sum
# why index? index表示输入子集的索引。表示哪些是需要考虑的，哪些是不需要考虑的。通常情况下，几乎所有的DP问题里面，index是必要的一个状态， except for shortest path(row & column).
# why Current Sum? 题中问的是能否找到整数和等于target。Current Sum表示目前所有item的和，直击题意。

# 3.决策
# 动态规划的核心就是做最优决策。为了做最优决策，必须线尝试所有的决策。MIT的DP课程中称之为 guessing step.
# Question: 在每次调用时，需要做什么决策？  0/1背包通常需要2个决策
# Answer: 题目要求使用输入子集中的所有元素，因此每一步加入一个元素到背包中。且每个元素有两个状态，因此决策为：
# 1.是否加入当前元素的正值
# 2.是否加入当前元素的负值

# 4.初始状态
# 回顾问题：1. 使用所有元素 2. 所有元素之和等于S
# Question: 找出初始状态。 有两个初始状态
# Answer: 两个初始状态，一个用于当前状态合理，另一个用于当前状态不合理。
# 1. valid: index is out of bounds & current sum = S
# 2. invalid: index is out of bounds.
# 为什么index要要出边界。很简单，因为要使用所有元素，当index超出边界的时候，即使用了所有元素。
from typing import List


# 5.Coding
# 理出思路之后，开始编写代码

class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        index = len(nums) - 1
        curr_sum = 0
        return self.dp(nums, S, index, curr_sum)

    def dp(self, nums, S, index, curr_sum):
        # Base Case
        if index < 0 and curr_sum == S: return 1
        if index < 0: return 0

        # Decision
        positive = self.dp(nums, S, index - 1, curr_sum + nums[index])
        negative = self.dp(nums, S, index - 1, curr_sum - nums[index])

        return positive + negative


# 6.优化
# 上述代码还有可以优化的地方，在递归的时候，很多状态重复地计算了。可以引入memorization，使每个子问题只需要进行一次计算。
# top-down 的递归解法，与bottom-up的迭代解法在计算上是等价的，不同的地方在于空间。
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        index = len(nums) - 1
        curr_sum = 0
        self.memo = {}
        return self.dp(nums, S, index, curr_sum)

    def dp(self, nums, S, index, curr_sum):
        if (index, curr_sum) in self.memo:
            return self.memo[(index, curr_sum)]

        if index < 0 and curr_sum == S: return 1
        if index < 0: return 0

        positive = self.dp(nums, S, index-1, curr_sum + nums[index])
        negative = self.dp(nums, S, index-1, curr_sum - nums[index])
        self.memo[(index, curr_sum)] = positive + negative
        return self.memo[(index, curr_sum)]

# 思考
# 其实该问题更像一个二叉树的遍历问题
# 通过前序遍历，计算从根节点到叶节点的路径和，求等于S的路径数。