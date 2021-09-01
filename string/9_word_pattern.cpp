//
// Created by yel on 2021/9/1.
//

// Given a pattern and a string s, find if s follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
//
//
//
//Example 1:
//
//Input: pattern = "abba", s = "dog cat cat dog"
//Output: true
//Example 2:
//
//Input: pattern = "abba", s = "dog cat cat fish"
//Output: false
//Example 3:
//
//Input: pattern = "aaaa", s = "dog cat cat dog"
//Output: false
//Example 4:
//
//Input: pattern = "abba", s = "dog dog dog dog"
//Output: false

// 问题：给定Pattern和s,判断s是否遵循该模式

// 方法：构建两个maps,分别映射pattern的和s的字符/字符串最后一次出现的索引，使用istringstream将字符串按空格切分成单词。
// 然后遍历字符串。判断当前pattern和word的最后出现位置是否一致。不一致则返回false

#include "string"
#include "map"
#include "sstream"

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, int> p_index;
        map<string, int> w_index;
        istringstream in(s);
        int i = 0, n = pattern.size();
        for (string word; in >> word; i++) {
            if (i == n || p_index[pattern[i]] != w_index[word])
                return false;
            p_index[pattern[i]] = w_index[word] = i + 1;
        }
        return i == n;
    }
};