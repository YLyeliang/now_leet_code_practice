//
// Created by yel on 2021/9/2.
//

// Given a string s, reverse only all the vowels in the string and return it.
//
//The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.
//
//
//
//Example 1:
//
//Input: s = "hello"
//Output: "holle"
//Example 2:
//
//Input: s = "leetcode"
//Output: "leotcede"

// 问题：给定字符串s,将所有的元音逆序表示

// 方法：双指针即可，当两个指针均遇到元音时，进行替换。这里可以使用find_first_of和find_last_of来决定双指针的位置。
// find_first_of(string,i); 其中string为字符串，为需要查找的字符集合。i为位置，表示只考虑位置i之后的子串。

#include "string"
#include "vector"

using namespace std;


class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;

    }
};