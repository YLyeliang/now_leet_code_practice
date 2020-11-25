# Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each
# step:
#
# Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
# Paste: You can paste the characters which are copied last time.
#
#
# Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted.
# Output the minimum number of steps to get n 'A'.
#
# Example 1:
#
# Input: 3
# Output: 3
# Explanation:
# Intitally, we have one character 'A'.
# In step 1, we use Copy All operation.
# In step 2, we use Paste operation to get 'AA'.
# In step 3, we use Paste operation to get 'AAA'.
#
#
# Note:
#
# The n will be in the range [1, 1000].

# 问题：开始时只有字符'A',每一步可以采取两个操作之一：
# 1.copy all: 复制现有的所有的字符；2. Paste: 粘贴最后复制的字符。给定数字n. 要得到n个'A',求最小步骤。

# 分析：这个问题就是开始时只有一个字符，每一步可以复制当前的字符，问多少步能达到n个字符。
# 利用DP方法。1.考虑到复制的字符可以粘贴多次，且多个字符可以由少个字符的倍数组成。因此，可以使用dp[i]表示有i个字符时的最小步骤。
# 2.状态转移方程：考虑当前遍历到的字符数为j，如果i%j==0,即i能被j整除，那么dp[i]=dp[j]+i/j;如果不能被整除，那么dp[i]=i;
# 3.初始状态：dp[1]=0,dp[2]=2(复制，粘贴）

class Solution:
    def minStep(self, n: int) -> int:
        dp = [0] * (n + 1)

        for i in range(2, n + 1):
            dp[i] = i
            for j in range(i - 1, 1, -1):
                if i % j == 0:
                    dp[i] = dp[j] + (i / j)
                    break

        return dp[n]

# 上述代码耗时约563ms，仍有可优化的地方。为O(n^2)
# 考虑到要判断整除的时，j的遍历范围从[i-1,1]时仍有大量数字重复迭代，修改为 [i//2,1]能节省更多时间。为O(NlogN)

# 更进一步：
# 考虑除数d，当n被d整除时，d个拷贝可以构成n（d * n/d).迭代的对n进行整除
class Solution:
    def minStep(self, n: int) -> int:
        s = 0
        for i in range(2, n + 1):
            while n % i == 0:
                s += i
                n /= i
        return s
