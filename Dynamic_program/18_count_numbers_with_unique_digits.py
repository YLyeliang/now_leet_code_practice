# Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10^n.
#
# Example:
#
# Input: 2
# Output: 91
# Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100,
#              excluding 11,22,33,44,55,66,77,88,99
#
#
# Constraints:
#
# 0 <= n <= 8

# 问题：给定非负整数n，求所有由不重复数组成的数字数量, 其中 0<=x< 10^n
# 分析：令f(n)表示数量，显然可以得到f(1)=10，range(0,10) f(2)时，对于两位数，可由ij组成，其中i为 1-9,j是从0-9种选9个数，组成9*9=81，f(2)=81+10=91
# f(3)时，9*9*8,8是从0-9中选8个数，f(3)=91+648=739;以此类推，可以得到剩下的数字。

class Solution:
    def countNumbersWithUniqueDigits(self, n):
        choices = [9, 9, 8, 7, 6, 5, 4, 3, 2, 1]
        ans, product = 1, 1

        for i in range(n if n <= 10 else 10):
            product *= choices[i]
            ans += product
        return ans
