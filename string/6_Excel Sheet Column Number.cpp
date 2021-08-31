//
// Created by yel on 2021/8/31.
//

// Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.
//
//For example:
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//
//
//Example 1:
//
//Input: columnTitle = "A"
//Output: 1
//Example 2:
//
//Input: columnTitle = "AB"
//Output: 28
//Example 3:
//
//Input: columnTitle = "ZY"
//Output: 701
//Example 4:
//
//Input: columnTitle = "FXSHRXW"
//Output: 2147483647

// 问题：与题5类似，这里是反过来，给定字母求数字。

// 方法：遍历字符串，从左至右分别为高位到地位。高位的值为26^(n-i-1)*当前字母

#include "string"

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size() - 1;
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            res += pow(26, (n - i - 1)) * (columnTitle[i] - 64);
        }
        return res;
    }
};

// 优化后

class Solution2 {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); result = result * 26 + (s.at(i) - 'A' + 1), i++);
        return result;
    }
};