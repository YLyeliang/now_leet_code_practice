// created by yel on 2021/12/30

// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
//
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
//
//Example 1:
//
//Input: rowIndex = 3
//Output: [1,3,3,1]
//Example 2:
//
//Input: rowIndex = 0
//Output: [1]
//Example 3:
//
//Input: rowIndex = 1
//Output: [1,1]
//
//Constraints:
//
//0 <= rowIndex <= 33
//
//Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

// 问题：给定行索引r,返回第r行的三角形数组。 要求，只使用O(r) space

// 方法：与I返回整个三角形不同的是，这里只返回某一行的数组。这样的话，可以只维持一个数组变量的更新即可。
// 创建一个vector，用于存储当前行的三角形数组。然后迭代更新即可。
// 优化：创建一个长为r+1的vector,初始化元素为0。头部为1，遍历迭代更新。考虑到从头部开始更新的话，
// res[j] = res[j] + res[j-1]会因为前面数字的更新而错误计算。这里从尾部开始更新。

#include "iostream"
#include "vector"

using namespace std;

// 原始版，不满足O(r)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res{1};
        for (int i = 1; i < rowIndex + 1; i++) {
            if (i > 1) {
                int tmp = res[0];
                for (int j = 1; j < i; j++) {
                    int new_ = res[j];
                    res[j] = tmp + res[j];
                    tmp = new_;
                }
                res.push_back(1);
            } else
                res.push_back(1);
        }
        return res;

    }
};

// 优化版
class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        for (int i = 1; i < rowIndex + 1; i++) {
            for (int j = i; j > 0; j--)
                res[j] = res[j] + res[j - 1];
        }
        return res;
    }
};
