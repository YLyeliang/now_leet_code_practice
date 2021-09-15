//
// Created by yel on 2021/9/15.
//

// Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
//
//
//
//Example 1:
//
//Input: s = "abab"
//Output: true
//Explanation: It is the substring "ab" twice.
//Example 2:
//
//Input: s = "aba"
//Output: false
//Example 3:
//
//Input: s = "abcabcabcabc"
//Output: true
//Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
//
//
//Constraints:
//
//1 <= s.length <= 104
//s consists of lowercase English letters.

// 问题：给定一个字符串s,求其能否由其中的一个子串通过多次拷贝构成。

// 方法:如果一个字符串能由一个子串多次拷贝构成，则将该字符串再拷贝一次，并删除其首尾两个字符，其仍然包含未拷贝前的字符串。
//

#include "string"

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2 * s.size() - 2).find(s) != -1;
    }
};