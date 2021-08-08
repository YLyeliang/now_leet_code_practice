//
// Created by yel on 2021/8/8.
//

// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
//
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// 问题：给定行索引，返回该索引下的pascal三角形的值

// 方法：与I类似，这里由于只返回对应行的值，可以只用一个数组进行迭代。
// 每次迭代更新时，从右端到左边进行更新，A[i] += A[i-1]

#include "vector"

using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 0);
        result[0] = 1;
        for (int i = 1; i < rowIndex + 1; ++i) {
            for (int j = i; j >= 1; --j)
                result[j] += result[j - 1];
        }
        return result;

    }
};