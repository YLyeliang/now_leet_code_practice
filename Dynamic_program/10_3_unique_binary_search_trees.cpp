// created by yel on 2021/12/29
// Given an integer n, return the number of structurally unique BST's (binary search trees)
// which has exactly n nodes of unique values from 1 to n.
//
//Example 1:
//
//Input: n = 3
//Output: 5
//    1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3

//Example 2:
//
//Input: n = 1
//Output: 1

//    1       2
//     \     /
//      2   1


// 问题：给定n，求构成1-n的BST的独立种数。

// 方法：
// n =1, s = 1
// n = 2, s = 2
// n = 3, s = 5
// n=1时，只有一个节点，为1种  dp[1] = 1
// n=2时，有两个节点。以1作为根节点，为1种。以2作为根节点，为1种 1 + 1 =2. dp[2] = 2
// n=3时。以1作为根节点，剩下2，3均在右子树。 以2为根节点，1，3分别为左子树和右子树。以3为根节点，1，2均在左子树。dp[2]*2+dp[1] = 5
// n = i时，遍历n。分别以i作为根节点。左子树为1...(i-1). 右子树为(i+1)...n
// dp[n] = dp[0]*dp[n-1] + dp[1]*dp[n-2] + dp[2]*dp[n-3] + ...dp[i]*dp[n-i-1]

#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i - j - 1];
        }
        return dp.back();

    }
};