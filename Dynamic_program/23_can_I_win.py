# In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
#
# What if we change the game so that players cannot re-use integers?
#
# For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
#
# Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise return false. Assume both players play optimally.
#
#
#
# Example 1:
#
# Input: maxChoosableInteger = 10, desiredTotal = 11
# Output: false
# Explanation:
# No matter which integer the first player choose, the first player will lose.
# The first player can choose an integer from 1 up to 10.
# If the first player choose 1, the second player can only choose integers from 2 up to 10.
# The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
# Same with other integers chosen by the first player, the second player will always win.
# Example 2:
#
# Input: maxChoosableInteger = 10, desiredTotal = 0
# Output: true
# Example 3:
#
# Input: maxChoosableInteger = 10, desiredTotal = 1
# Output: true
#
# Constraints:
#
# 1 <= maxChoosableInteger <= 20
# 0 <= desiredTotal <= 300

# 问题：在“100游戏”中，两个玩家轮流加1-10的数。先达到或超过100的玩家赢。 现在修改规则，不能使用重复的数字。例如，从1-15选，谁先>=100，赢。
# 给定两个整数 maxChoosableInter and desiredTotal, 如果先手的人赢，返回true otherwise false. 假设两者都是最优玩法。
# 分析：这是一个DP问题，想象一下，如果先手的人要赢，那么后手的人最后一次选择的数字j必定满足 total-j in 剩下的数。
# 即 total-j in nums.其中nums = range(maxChoosableInter)。那么，dp[total]=dp[total-j] in nums

class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        nums = [for i in range(1, maxChoosableInteger + 1)]

        a = 1


sol = Solution()
sol.canIWin(10, 11)
