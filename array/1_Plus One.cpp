//
// Created by yel on 2021/8/8.
//

// Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
//
//The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
//
//You may assume the integer does not contain any leading zero, except the number 0 itself.

// 问题：给一个十进制非空数组表示非负整数，对整数进行+1操作。
// 即整数由数组中每个元素按照从高位到地位进行表示。

// 方法：1. 首先对数组最后一位进行+1，并将结果除10取余，得到最后一位的结果。
// 2. 建立一个变量plus表示是否进位，其初始值根据最后一位结果而定，如果为0，则表示需要进位。
// 3. 然后逆序遍历整个数组，如果Plus为真，则高位+1并模10，并根据高位是否等于0决定plus.
// note:对于数组的首字符高位+1时，需要在数组头部插入一个1

// 简化：对于除10取余的操作，可以用 判断数字是否为9为替代。并且可以取消plus的变量，在遍历过程中遇到非9的数字，则表示不可能再进位，直接返回结果即可。


// 例：
// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.

#include "vector"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9)
                digits[i] = 0;
            else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;

    }
};