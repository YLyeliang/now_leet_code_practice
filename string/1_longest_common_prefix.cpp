//
// Created by yel on 2021/8/30.
//

// Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//
//
//Example 1:
//
//Input: strs = ["flower","flow","flight"]
//Output: "fl"
//Example 2:
//
//Input: strs = ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.


// 问题：求字符串的最长公共前缀

// 方法：
// 1. 对字符串数组进行排序。这样数组的第一个字符串和最后一个字符串是差距最大的。只需要比较这两个字符串的公共前缀即可
// 2. 取第一个字符串为res,从第二个字符串开始遍历数组，比较res和字符串的公共前缀，求得最长前缀结尾的索引，并根据索引取res子串。

#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        if (n == 0) return "";

        sort(begin(strs), end(strs));
        string a = strs[0];
        string b = strs[n - 1];
        string res = "";

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i])
                res = res + a[i];
            else
                break;
        }
        return res;

    }
};

class Solution2 {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            for (j = 0; j < strs[i].size(); j++) {
                if (res[j] != strs[i][j])
                    break;
            }
            res = res.substr(0, j);
            if (res=="")
                return res;
        }
        return res;

    }
};