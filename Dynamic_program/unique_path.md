A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

![](images/robot_maze.png)

Above is a 7 x 3 grid. How many possible unique paths are there?
 
Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.

分析：一个mxn的矩阵，人在左上角，只能往右或往下移一格每次。 要到达右下角，一共有多少可能的独立路径。
考虑逆向思维，到达右下角之前，只有两条路，上方或左方。即dp[i][j]=dp[i][j-1]+dp[i-1][j].
可以构建dp矩阵，其中dp[i][j]表示第i行j列位置的独立路径数。第一行和第一列的数字均为1，因为只有一条路。
初始状态：dp[0][0]=1 dp[0][1]=1,dp[1][0]=1,则退出dp[1][1]=dp[0][1]+dp[1][0]=1+1=2

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m<1 or n<1:return 0
        if m==1 or n==1:return 1
        dp = [[1] * n for _ in range(m)]
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j]=dp[i-1][j]+dp[i][j-1]
        return dp[-1][-1]
```