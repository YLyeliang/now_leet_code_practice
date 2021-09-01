//
// Created by yel on 2021/9/1.
//


// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//
//
//
//Example 1:
//
//Input: s = "anagram", t = "nagaram"
//Output: true
//Example 2:
//
//Input: s = "rat", t = "car"
//Output: false

// 问题：相同字母异序词。给定s和t,如果t是s的相同字母异序词，返回true, else false.

// 方法：只需要判断是否异序的话，统计所有字符出现的次数是否一致即可。或者对两者进行排序，看是否一致。

#include "string"
#include "algorithm"
#include "unordered_map"

using namespace std;

// 1. sort 时间 O(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;


    }
};

// 2.hash table
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> counts;

        for (int i = 0; i < s.length(); i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count: counts)
            if (count.second) return false;
        return true;
    }
};