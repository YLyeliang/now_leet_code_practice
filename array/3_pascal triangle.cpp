//
// Created by yel on 2021/8/8.
//

// Given an integer numRows, return the first numRows of Pascal's triangle.
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
//
// Example 1:
//
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]


// 问题：给定一个整数numRows, 返回pascal三角形的首numRows行。
// Pascal triangle: 每个数字等于该数字位置上方两个数之和。第一行数字为1.

// 方法：可以看出来，三角形中从第三行开始，中间的元素(从索引i=1开始），等于上一行的当前索引-1+当前索引的元素之和。



#include "vector"

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) return {{}};
        vector<vector<int>> result{{1}};
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp(i + 1, 1);
            if (i > 1) {
                for (int j = 1; j < i; j++) {
                    tmp[j] = result[i - 1][j - 1] + result[i - 1][j];
                }
            }
            result.push_back(tmp);
        }
        return result;
    }
};

int main() {
    vector<vector<int>> result{{1},
                               {1, 1}};
    return 0;
}