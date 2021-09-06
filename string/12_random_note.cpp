//
// Created by yel on 2021/9/2.
//

// Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.
//
//Each letter in magazine can only be used once in ransomNote.
//
//
//
//Example 1:
//
//Input: ransomNote = "a", magazine = "b"
//Output: false
//Example 2:
//
//Input: ransomNote = "aa", magazine = "ab"
//Output: false
//Example 3:
//
//Input: ransomNote = "aa", magazine = "aab"
//Output: true

// 只有小写字符
// 问题：给定两个字符串 ransomNote & magazine, 如果能用magazine的字符构建出ransomNote，则返回true else false
// magazine里的每个字符只能使用一次。

// 分析：
// 1. 遍历ransom,对每个字符在magazine里查找并删除，遍历结束时返回true,否则返回false.  O(n^2),时间较高
// 2. 将两个字符串的字符进行遍历和统计。首先将magazine的结果存在一个数组中，进行+1统计，然后遍历ransom，进行-1统计，如果<0，则false


#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (char s:ransomNote) {
            bool flag = true;
            for (int i = 0; i < magazine.size(); i++) {
                if (s == magazine[i]) {
                    flag = false;
                    magazine.erase(i, 1);
                    break;
                }
            }
            if (flag)
                return false;
        }
        return true;
    }
};

class Solution2 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> arr(26, 0);
        for (char c: magazine)
            arr[c - 'a'] += 1;
        for (char c:ransomNote)
            if (--arr[c - 'a'] < 0)
                return false;
        return true;

    }
};

int main() {
    Solution sol;
    sol.canConstruct("aa", "aabv");
}