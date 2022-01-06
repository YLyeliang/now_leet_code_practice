// created by yel on 2021/12/28

// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
//
//Given an integer n, return the nth ugly number.
//
//
//
//Example 1:
//
//Input: n = 10
//Output: 12
//Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
//Example 2:
//
//Input: n = 1
//Output: 1
//Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
//
//
//Constraints:
//
//1 <= n <= 1690

// 问题：丑数，只包含质因子2、3和5的数。
// 给定整数n，返回第n个丑数

// 方法：2，3，5. 给定一个数 n,  n % 2, n % 3, n % 5. 14 % 2 = 0, 14 / 2 = 7,
// 构建一个dp数组，其中dp[i]表示第i个数是否为丑数。
// 则，以14为例， 14 被2整除，其商为7,则判断7是否为丑数，如果其不为丑数，则14不为丑数.
// 20， 20/5 = 4, 4为丑数，则20为丑数

// 2. 考虑到第一个数为1,且丑数其素因数为 2，3，5.则下一个数为min(1*2,1*3,1*5)
// 推广到一般式：k[1] = min(k[0]*2,k[0]*3,k[0]*5) = 2
// k[2] = min(k[1]*2,k[0]*3,k[0]*5) = 3
// k[3] = min(k[1]*2,k[1]*3,k[0]*5) = 4
// k[4] = min(k[2]*2,k[1]*3,k[0]*5) = 5
// k[5] = min(k[2]*2,k[1]*3,k[1]*5) = 6
// 则k[i]表示第i个丑数，状态转移方程为：k[i] = min(k[j]*2,k[l]*3,k[m]*5), if k[i] == any(k[j,l,m]) any(j,l,m)++
// O(n) time, O(n) space.
// 可以通过建立三个变量来进一步缩减空间

#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<int> dp(n);
        int t2 = 0, t3 = 0, t5 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[t2] * 2, min(dp[t3] * 3, dp[t5] * 5));
            if (dp[i] == dp[t2] * 2) t2++;
            if (dp[i] == dp[t3] * 3) t3++;
            if (dp[i] == dp[t5] * 5) t5++;
        }
        return dp.back();


    }
};