//
// Created by yel on 2021/9/14.
//

// You are given a string s, return the number of segments in the string.
//
// A segment is defined to be a contiguous sequence of non-space characters.
//
// Example 1:
//
// Input: s = "Hello, my name is John"
// Output: 5
// Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
// Example 2:
//
// Input: s = "Hello"
// Output: 1
// Example 3:
//
// Input: s = "love live! mu'sic forever"
// Output: 4
// Example 4:
//
// Input: s = ""
// Output: 0

// 问题：给一个字符串，求字符串中的所有单词的个数。 单词定义为不带空格的连续字符。

// 方法：遍历字符串。 1. 加一个判断符，判断前面的字符是否为空格即可。 2. 判断当前字符和前一个字符是否为空格即可。

#include "string"

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        bool space = true;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ' && space) {
                res += 1;
                space = false;
            }
            if (s[i] == ' ')
                space = true;

        }
        return res;

    }
};