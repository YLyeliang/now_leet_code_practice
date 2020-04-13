# 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
#
# 示例 1:
# 输入: n = 12
# 输出: 3
# 解释: 12 = 4 + 4 + 4.
# 示例 2:
#
# 输入: n = 13
# 输出: 2
# 解释: 13 = 4 + 9.

# 暴力方法：num(n)=num(n-k)+1，枚举出所有的k的组合，该方法要重复地计算中间值n-k的解
# 十分耗时，很容易造成堆栈溢出。
#
import math
class Solution(object):
    def numSquares(self, n):
        square_nums = [i**2 for i in range(1, int(math.sqrt(n))+1)]

        def minNumSquares(k):
            """ recursive solution """
            # bottom cases: find a square number
            if k in square_nums:
                return 1
            min_num = float('inf')

            # Find the minimal value among all possible solutions
            for square in square_nums:
                if k < square:
                    break
                new_num = minNumSquares(k-square) + 1
                min_num = min(min_num, new_num)
            return min_num

        return minNumSquares(n)

# 二、动态规划方法：
# 仍然是num(n)=num(n-k)+1，与斐波那契数列类似，k的数量上升了（多个平方数，斐波那契中只有1和2）
# 定义动态规划的数组dp[n]，表示取值为n时组成的最少个数。比如dp[1]=1,dp[4]=1,dp[9]=1,dp[12]=2
# 寻找状态转移方程，组成n的数量由n-k决定，k为平方数，则dp[n]=min(dp[n-k)+1),比如，dp[12]=min(dp[12-1]+1,dp[12-4]+1,dp[12-9]+1)
# 定义初始状态：dp[0]=0,dp[1]=1
class Solution(object):
    def numSquares(self,n):
        dp=[i for i in range(n+1)]
        squares=[i**2 for i in range(int(math.sqrt(n)+1))]

        for i in range(1,n+1):
            num=[]
            for k in squares:
                if i<k:
                    break
                num.append(dp[i-k]+1)
            dp[i]=min(min(num),dp[i])
        return dp[-1]

# 贪心枚举
# 暴力法中的递归方法简介，但是大量的重复计算中间值导致了堆栈了溢出。因此，引入贪心方法来解决这一问题。
# 令count从1开始递增地迭代，假设数字n可以被count个数组合，则找到了最小的count组合。
# 问题的关键转移到了如何判断n是否能被count个数整除。定义is_divided_by(n, count)，当n能被count个数组合时，返回true else false.
# 则numSquare(n)=argmin(is_divided_by(n,count))
# 在递归的过程中，最底层的情况是count==1,只需要判断此时的n是否是平方数即可。
class Solution(object):
    def numSquare(self,n):
        def is_divideb_by(n,count):
            """
            return: true if 'n' can be composed into "count" number of perfect square numbers.
            e.g n=12, count=3: true
            e.g n=12, count=2: false
            """
            if count==1:
                return n in square

            for k in square:
                if is_divideb_by(n-k,count-1):
                    return True
            return False

        square=[i**2 for i in range(1,int(n**0.5)+1)]

        for i in range(1,5):
            if is_divideb_by(n,i):
                return i
solve=Solution()
num=solve.numSquares(13)
print(num)