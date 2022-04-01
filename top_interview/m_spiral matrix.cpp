// created by yel on 2022/3/31
// Given an m x n matrix, return all elements of the matrix in spiral order.
//
//Example 1:
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,3,6,9,8,7,4,5]
//
// Example 2:
//Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//
//Constraints:
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 10
//-100 <= matrix[i][j] <= 100

// 问题： 给定 m x n矩阵，顺时针打印矩阵

// 方法： 需要设置四个标志位，l,r,t,b分别表示左右上下的边界.每次循环以走完一个顺时针为准.然后更新边界.
// 由于每次循环时，边界应该是向内缩的,所以对应边界++ --即可。

#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int l = 0, t = 0;
        int r = matrix[0].size() - 1, b = matrix.size() - 1;
        vector<int> res;
        while (true) {
            // left-right
            for (int i = l; i <= r; i++) res.push_back(matrix[t][i]);
            if (++t > b) break;
            // top-down
            for (int i = t; i <= b; i++) res.push_back(matrix[i][r]);
            if (--r < l) break;
            // right-left
            for (int i = r; i >= l; i--) res.push_back(matrix[b][i]);
            if (--b < t) break;
            // bottom-up
            for (int i = b; i >= t; i--) res.push_back(matrix[i][l]);
            if (++l > r) break;
        }
        return res;
    }
};