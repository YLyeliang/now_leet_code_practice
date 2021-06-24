# A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator
# such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.
#
# Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained
# with exact n rolls.
#
# Two sequences are considered different if at least one element differs from each other. Since the answer may be too
# large, return it modulo 10^9 + 7.
#
#
#
# Example 1:
#
# Input: n = 2, rollMax = [1,1,2,2,2,3]
# Output: 34
# Explanation: There will be 2 rolls of die, if there are no
# constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array,
# the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur,
# so the final answer is 36-2 = 34.
# Example 2:
#
# Input: n = 2, rollMax = [1,1,1,1,1,1]
# Output: 30
# Example 3:
#
# Input: n = 3, rollMax = [1,1,1,2,2,3]
# Output: 181
#
# Constraints:
#
# 1 <= n <= 5000
# rollMax.length == 6
# 1 <= rollMax[i] <= 15

# 问题：有一个骰子模拟器会每次投掷的时候生成一个 1 到 6 的随机数。
# 不过我们在使用它时有个约束，就是使得投掷骰子时，连续掷出数字i的次数不能超过 rollMax[i]（i 从 1 开始编号）。
# 给定rollMax和n,返回用n次投掷得到的不同点数序列的数目；
# 假如两个序列中至少存在一个元素不同，就认为这两个序列是不同的。


# 分析：以n=3为例，扔第一次时，i=1,6种情况.假设dp[i][j]为扔i次时以j结尾时的情况
# i=2, 由于rollMax[0,1,2]为1，则不能出现11,22,33的情况，而对于以1结尾的情况为y1,y为非1的数，共5种情况。 对于以4结尾的，则有x4,共6种。
# 则可以得到dp[2][1,2,3]=5, dp[2][4,5,6]=6, dp[2][7] = sum(dp[2]) = 33
# i=3,对于以1结尾的，则有xy1,x为1-6，y为非1数。考虑到dp[2]有33种分布，而在i=2时，以1结尾的情况dp[2][1]有5种，则dp[3][1]=dp[2]-dp[2][1]
# dp[3][1] = dp[3-1] - dp[3-1][1]
# 以另一个例子, i=5, rollMax[5] = 3,以5结尾的情况有如下几种：
# xxxy5
# xxy55
# xy555
# 这几种情况分别对应 而dp[4]的所有情况包含了上述三种情况，现在只要减去不满足上面的情况即可。dp[5][5] = dp[4] - dp[4][5] +dp[3] - dp[3][5] + ...
# 其中dp[4]包含了xxxx的情况，dp[4] - dp[4][5]即 减去xxx5，也就是xxx55的情况，

from typing import List


class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        faces = len(rollMax)
        # [n + 1][faces + 1] dimensional dp array
        dp = [[0 for i in range(faces + 1)] for j in range(n + 1)]

        # initialization
        # roll 0 times, the total combination is 1
        dp[0][faces] = 1
        # roll 1 times, the combinations that end at face j is 1
        for j in range(faces):
            dp[1][j] = 1
        # roll 1 times, the total combination is faces = 6
        dp[1][faces] = faces

        # then roll dices from 2 times, until n times
        for i in range(2, n + 1):
            # iterate through each column (face)
            for j in range(faces):
                # at each [i, j], trying to go up (decrease i) and collect all the sum of previous state
                for k in range(1, rollMax[j] + 1):
                    if i - k < 0:
                        break
                    dp[i][j] += dp[i - k][faces] - dp[i - k][j]
            # update total sum of this row
            dp[i][faces] = sum(dp[i])

        return dp[n][faces] % 1000000007
