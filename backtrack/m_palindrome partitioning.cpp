// created by yel on 2022/3/15

// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.
//A palindrome string is a string that reads the same backward as forward.
//
//Example 1:
//Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
//
// Example 2:
//Input: s = "a"
//Output: [["a"]]
//
//Constraints:
//1 <= s.length <= 16
//s contains only lowercase English letters.

// 问题：给定字符串s,切分字符串，使其每个子串均为回文。返回所有的切分字符串数组。
// aabaa

// 方法：回溯法
// 构建递归函数。 递归函数的遍历过程为，判断截止到当前位置的字符串是否为回文，如果是回文，将当前字符加入到tmp,
// 并回溯剩下的字符。



#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        backtrack(res, tmp, s, 0);
        return res;
    }

    void backtrack(vector<vector<string>> &res, vector<string> &tmp, string &s, int start) {
        if (s.length() == start)
            res.push_back(tmp);
        else
            for (int i = start; i < s.length(); i++) {
                if (isPalindrome(s, start, i)) {
                    tmp.push_back(s.substr(start, i - start + 1));
                    backtrack(res, tmp, s, i + 1);
                    tmp.pop_back();

                }
            }
    }

    bool isPalindrome(string s, int low, int high) {
        while (low < high)
            if (s[low++] != s[high--]) return false;
        return true;
    }
};