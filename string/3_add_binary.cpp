//
// Created by yel on 2021/8/30.
//

// Given two binary strings a and b, return their sum as a binary string.
//
//
//
//Example 1:
//
//Input: a = "11", b = "1"
//Output: "100"
//Example 2:
//
//Input: a = "1010", b = "1011"
//Output: "10101"

// 问题：给定字符串a和b，表示二进制数，返回他们的和并用二进制表示

// 方法：逆序遍历两个字符串，依次对每个字符转化为数字求和，高位进1.

#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || c >= 1) {
            c += i >= 0 ? a[i--] - '0' : 0; // 转数字
            c += j >= 0 ? b[j--] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2; // 如果是2，即高位进一 c/2 = 1,如果是1，则表示不需要高位进1，c/2=0,当所有数遍历完时可退出循环
        }
        return s;

    }
};