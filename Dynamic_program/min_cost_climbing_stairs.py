# On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
#
# Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
#
# Example 1:
# Input: cost = [10, 15, 20]
# Output: 15
# Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
# Example 2:
# Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
# Output: 6
# Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
# Note:
# cost will have a length in the range [2, 1000].
# Every cost[i] will be an integer in the range [0, 999].

# 分析：在阶梯中，第i个阶梯有一个非负的消耗cost[i]. 一旦你进行了消耗，可以选择走1步or2步。求到顶部的最小消耗。可以选择从index 0 or index 1 开始。
# 经典的动态规划题目，定义个dp[n]，其中dp[i]表示走到当前阶梯时的最小消耗。由于一次可以走1or2步，则当前阶梯的最小消耗可以是 2步前or1步前的最小消耗加上当前的消耗。
# 可知，动态转移矩阵为，dp[i]=min(dp[i-1]+cost[i],dp[i-2]+cost[i])

class Solution:
    def minCostClimbingStairs(self, cost) -> int:
        if len(cost)<=2:return min(cost)
        dp=cost[:2]
        for i in range(2,len(cost)):
            dp.append(min(dp[i-1]+cost[i],dp[i-2]+cost[i]))
        return min(dp[-2:])
cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
# cost=[0,1,1,0]

sol=Solution()
sol.minCostClimbingStairs(cost)

