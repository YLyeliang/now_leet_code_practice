# We partition a row of numbers nums into at most k adjacent (non-empty) groups, then our score is the sum of the
# average of each group. What is the largest score we can achieve?
#
# Note that our partition must use every number in nums, and that scores are not necessarily integers.
#
# Example:
# Input:
# nums = [9,1,2,3,9]
# k = 3
# Output: 20
# Explanation:
# The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
# We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
# That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
#
#
# Note:
#
# 1 <= nums.length <= 100.
# 1 <= nums[i] <= 10000.
# 1 <= k <= nums.length.
# Answers within 10-6 of the correct answer will be accepted as correct.

# 问题：将一行数字划分成至多k个相邻非空数组，分数为每个组的平均值相加后的和，求最大分数。


# 分析： 均值= sum(x_i)/len(x_i)
# 该题类体于切割钢筋求最大价格。不同之处在于此处是分成至多k个，可以是1-k内的最优值。
# DP： 使用 top-down with memoization方法，其中memo[n,k]表示长为n的数组分成至多k个时的最大价格
# memo[n,k] = max(memo[n,k], memo[n-1,k-1] + cur / 1, memo[n-2,k-1] + cur /2, memo[n-i,k-1] + cur / i)
# 即，长为n分成至多k的最大价格 = max(长为n-i分成至多k-1个的价格)+ price(i)
# 其中, cur /float(n-i)表示
from typing import List


class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        memo = {}

        def search(n, k):
            if (n, k) in memo: return memo[n, k]
            if n < k: return 0
            if k == 1:
                memo[n, k] = sum(nums[:n]) / float(n)
                return memo[n, k]
            cur, memo[n, k] = 0, 0
            for i in range(n - 1, 0, -1):  # cur += nums[i] memo[n,k] = max(memo[n,k], search(i,k-1) + cur/ float(n-i))
                cur += nums[i]
                memo[n, k] = max(memo[n, k], search(i, k - 1) + cur / float(n - i))
            return memo[n, k]

        return search(len(nums), k)
