# A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
#
# For example, these are arithmetic sequences:
#
# 1, 3, 5, 7, 9
# 7, 7, 7, 7
# 3, -1, -5, -9
# The following sequence is not arithmetic.
#
# 1, 1, 2, 5, 7
#
# A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
#
# A slice (P, Q) of the array A is called arithmetic if the sequence:
# A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
#
# The function should return the number of arithmetic slices in the array A.
#
#
# Example:
#
# A = [1, 2, 3, 4]
#
# return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

# 问题：一个数列称为等差，如果其包含至少三个元素，并且任意两个连续的数之差相等。
# 给定 零索引的数组A，包含N个数。该数组的切片是任意整数对(P,Q)，满足 0<=P<Q<N。
# 数组A的切片(P,Q)为等差，如果A[P],A[P+1], ... , A[Q-1], A[Q] 为等差。 P+1<Q。函数需返回等差切片的数量。
# 分析：考虑DP的方式。构建dp数组，其中dp[i]表示以A[i]结尾的切片数量。如何求解状态转移方程？第三个数开始。如果A[i-2],A[i-1],A[i]构成等差数列，
# 那么dp[i]= 以dp[i-1]结尾的切片数量（因为以dp[i-1]结尾的切片数列，加上A[i]之后仍构成等差数列，数目不变）+数列(A[i-2],A[i-1],A[i])。即dp[i]=dp[i-1]+1
# 初始化dp=[0]*n
from typing import List


class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        length = len(A)
        if length < 3: return 0
        dp = [0] * length
        if A[1] - A[0] == A[2] - A[1]: dp[2] = 1
        result = dp[2]
        for i in range(3, length):
            if A[i - 1] - A[i - 2] == A[i] - A[i - 1]:
                dp[i] = dp[i - 1] + 1
            result += dp[i]
        return result
