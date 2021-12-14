//
// Created by 叶亮 on 2021/12/11.
//

// Given a string s, reverse the order of characters in each word
// within a sentence while still preserving whitespace and initial word order.
//
//
//
//Example 1:
//
//Input: s = "Let's take LeetCode contest"
//Output: "s'teL ekat edoCteeL tsetnoc"
//Example 2:
//
//Input: s = "God Ding"
//Output: "doG gniD"

// 问题：给定字符串s,翻转每个单词的字符，保持空格和单词顺序

// 方法：python: split所有单词，然后每个单词逆序
// c++: O(n)。添加变量start表示单词的起点，遍历字符串，遇到空格 or 尾部，则reverse start到当前字符串的位置。


#include "iostream"
#include "string"

using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        size_t start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.length() == i + 1 || s[i] == ' ') {
                reverse(&s[start],&s[i]);
                start= i+1;
            }
        }
        return s;
    }
};