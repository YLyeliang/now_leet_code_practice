// created by yel on 2022/3/5

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
//

#include "iostream"
#include "vector"

using namespace std;

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