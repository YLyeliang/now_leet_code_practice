// created by yel on 2022/3/5
// DP 递归 回溯
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
// Example 1:
//Input: n = 3
//Output: ["((()))","(()())","(())()","()(())","()()()"]
//
// Example 2:
//Input: n = 1
//Output: ["()"]
//
//Constraints:
//1 <= n <= 8

// 问题：给定n对括号，求合法的所有括号组合。

// 方法：
// 1. simple recursive method.
// 用n, m表示剩下的( )数量. 构建一个递归函数，函数每次调用时if m > 0,增加) if n >0, 增加(
// why?

// 1. DP方法
// n对括号。生成一对括号（）之后，剩下的方式有在()里面添加0对，在这之后添加n-1对。
// 在()添加1对，在这之后添加n-2对。
// 使用dp[i]表示i对括号的解。则i=1, dp[i] = ["()"]
// i=2, ["()()", "(())"]
// i=3,()()为例，添加0对，之后添加n-2=1, ()()(), 添加1对，之后添加0，(())() ()(()) ...
// 则每次状态转移时，需要遍历之前的dp数组，对每个结果，根据上述规则进行添加.
// dp[i] = (dp[j])+dp[i-j-1]

// 2. 回溯法
//

#include "iostream"
#include "vector"

using namespace std;


// Recursive
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }

    void addingpar(vector<string> &v, string str, int n, int m) {
        if (n == 0 && m == 0)
            v.push_back(str);

        if (m > 0) addingpar(v, str + ")", n, m - 1);
        if (n > 0) addingpar(v, str + "(", n - 1, m + 1);
    }

};

// DP
class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");    // initialize
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                //
                for (auto y: dp[i - j - 1]) {
                    for (auto x: dp[j]) {
                        dp[i].push_back('(' + x + ')' + y);
                    }

                }

            }
        }
        return dp[n];

    }

};