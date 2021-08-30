//
// Created by yel on 2021/8/30.
//

// Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.
//
//A word is a maximal substring consisting of non-space characters only.
//
//
//
//Example 1:
//
//Input: s = "Hello World"
//Output: 5
//Explanation: The last word is "World" with length 5.
//Example 2:
//
//Input: s = "   fly me   to   the moon  "
//Output: 4
//Explanation: The last word is "moon" with length 4.
//Example 3:
//
//Input: s = "luffy is still joyboy"
//Output: 6
//Explanation: The last word is "joyboy" with length 6.

// 问题：一个字符串由多个单词表示，每个单词由空格分开。求最后一个单词的长度

// 方法：python一行即可. return len(s.rstrip(" ").split(" ")[-1])
// 遍历字符串，遇到一个字符时长度计数+1，设置一个变量next，遇到空格时置为true,遇到字符时置为false,并将当前的长度计数重置

// 或者逆序遍历字符串，先跳过前面所有的空格，然后计算长度

#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        bool next = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ')
                next = true;
            else if (next) {
                res = 1;
                next = false;
            } else
                res++;
        }
        return res;
    }
};