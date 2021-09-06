//
// Created by yel on 2021/9/6.
//

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
//
//
//
//Example 1:
//
//Input: s = "leetcode"
//Output: 0
//Example 2:
//
//Input: s = "loveleetcode"
//Output: 2
//Example 3:
//
//Input: s = "aabb"
//Output: -1
//
//
//Constraints:
//
//1 <= s.length <= 10^5
//s consists of only lowercase English letters.

// 问题：给定字符串s，找到第一个不重复的字符，返回其索引，没有则返回-1.只包含小写字母

// 分析：构建一个数组来存储字符出现的索引，数组初始化为-1，遍历s,如果首次出现则将索引赋值到对应位置，第二次出现时将-2赋值到对应位置
// 然后遍历该数组，找到最小的正数，即为所求。

#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26, -1);
        for (int i = 0; i < s.size(); i++) {
            if (arr[s[i] - 'a'] == -1)
                arr[s[i] - 'a'] = i;
            else
                arr[s[i] - 'a'] = -2;
        }
        int res = s.size();
        for (int i:arr) {
            if (i >= 0)
                res = min(res, i);
        }
        return res == s.size() ? -1 : res;

    }
};