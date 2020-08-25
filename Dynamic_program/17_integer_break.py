# Given a positive integer n,
# break it into the sum of at least two positive integers and maximize the product of those integers.
# Return the maximum product you can get.
#
# Example 1:
#
# Input: 2
# Output: 1
# Explanation: 2 = 1 + 1, 1 × 1 = 1.
# Example 2:
#
# Input: 10
# Output: 36
# Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
# Note: You may assume that n is not less than 2 and not larger than 58.

# 问题：给定正整数n,将其分成至少两个正整数的和，并最大化这些数的积，返回最大的积。 Assume:2<n<=58.
# 分析：考虑一下，当将一个数N分成两个数时，怎样得到其最大积？可以用公式 f = x (N - x)表示，对其求导，得到f'=N - 2x=0 =>x=N/2
# 即 (N/2)*(N/2).由于必须是整数。所以，当N是偶数时，可以用上述公式，当N是奇数时，可以是(N-1)/2*(N+1)/2.
# 得到 (N/2)*(N/2)>=N, => N=4;    (N-1)/2*(N+1)/2>=N  => N=5
# 又因为， 3 *3 =9 > 2 * 2 * 2=8；因此，尽量先用3进行分解，最后用2.

class Solution:
    def integerBreak(self,n):
        if n==2: return 1
        if n==3: return 2
        product=1
        while n>4:
            product*=3
            n-=3
        product*=n
        return product