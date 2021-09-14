//
// Created by yel on 2021/9/14.
//

// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
//
// You must solve the problem without using any built-in library for handling large integers (such as BigInteger).
// You must also not convert the inputs to integers directly.
//
//
//
//Example 1:
//
//Input: num1 = "11", num2 = "123"
//Output: "134"
//Example 2:
//
//Input: num1 = "456", num2 = "77"
//Output: "533"
//Example 3:
//
//Input: num1 = "0", num2 = "0"
//Output: "0"

// 问题：给定两个非负整数，num1和num2,均用字符串表示，求和并返回字符串。要求：不能转int，不能使用内置函数库，不能直接将输入转换成整数。

// 方法：逆序遍历字符串，从数字低位到高位依次求和，设置进位符号，

#include "string"

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string res = "";
        int carry;
        while (i >= 0 || j >= 0 || carry) {
            long sum = 0;
            if (i >= 0) {
                sum += (num1[i] - '0');
                --i;
            }
            if (j >= 0) {
                sum += (num2[i] - '0');
                --j;
            }
            sum += carry;
            carry = sum / 10; // 进位
            sum %= 10; // 低位
            res += to_string(sum);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

