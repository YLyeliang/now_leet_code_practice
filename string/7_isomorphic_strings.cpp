//
// Created by yel on 2021/9/1.
//

// Given two strings s and t, determine if they are isomorphic.
//
//Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters.
// No two characters may map to the same character, but a character may map to itself.
//
//
//
//Example 1:
//
//Input: s = "egg", t = "add"
//Output: true
//Example 2:
//
//Input: s = "foo", t = "bar"
//Output: false
//Example 3:
//
//Input: s = "paper", t = "title"
//Output: true

// 问题：给定两个字符串s和t, 判断是否是isomorphic(同构).同构：字符串s中的字符经过替换能得到t.其中每个字符替换时保持原顺序，两个相同的字符不能
// 呗同一个字符替换，但是一个字符可以映射到其本身。相同字符只能映射到一个字符上。

// 方法：判断是否能替换，可以构建两个hash表。存储字符和出现的次数。如果字符是同构的，则遍历整个字符串时，s中当前字符和t中当前字符最后出现的位置应该是一致的。

#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> m_s;
        unordered_map<char, int> m_t;
        for (int i = 0; i < s.size(); i++) {
            if (!m_s.count(s[i])) m_s[s[i]] = 0;
            if (!m_t.count(t[i])) m_t[t[i]] = 0;
            if (m_s[s[i]] != m_t[t[i]]) return false;
            m_t[t[i]] = i + 1;
            m_s[s[i]] = i + 1;
        }
        return true;
    }
};
