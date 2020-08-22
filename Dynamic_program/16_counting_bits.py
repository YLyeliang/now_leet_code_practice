# Given a non negative integer number num.
# For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
#
# Example 1:
#
# Input: 2
# Output: [0,1,1]
# Example 2:
#
# Input: 5
# Output: [0,1,1,2,1,2]
# Follow up:
#
# It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
# Space complexity should be O(n).
# Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

# 问题：给定非负整数num，对于0<=i<=num,计算每一个i的二进制表示的1的数目
# 分析：该问题用到了常见的移位知识。我们知道，一个数左移一位=乘以2，右移一位=除以2。那么，构建数组dp,dp[i]表示i的二进制表示中1的数量。
# 则dp[i] = dp[i/2] + 1 if i%2!=0 else dp[i/2]。因为一个数*2时表示左移，即右端添0，所以1的数量不会变；而如果当前数字不能被2整除时，则会+1.

from typing import List


class Solution:
    def countBits(self, num: int) -> List[int]:
        dp = [0]
        for i in range(1, num + 1):
            dp.append(dp[i >> 1] + (i & 1))
        return dp


sol = Solution()
sol.countBits(2)
