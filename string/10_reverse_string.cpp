//
// Created by yel on 2021/9/2.
//

// 问题：给定字符数组，求逆序，要求in-place

// 方法：直接双指针即可

#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    void reverseString(vector<char> s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
            swap(s[i++], s[j--]);
    }
};