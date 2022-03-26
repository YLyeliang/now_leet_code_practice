// created by yel on 2022/3/20

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
//
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.
//
//Example 1:
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [[7,4,1],[8,5,2],[9,6,3]]
//
// Example 2:
//Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
//Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
//
//Constraints:
//n == matrix.length == matrix[i].length
//1 <= n <= 20
//-1000 <= matrix[i][j] <= 1000

// 问题：给定n x n的2D矩阵，顺时针旋转90度。要求in-place.

// 方法：1. 上下反转->转置
// 上下反转可以直接调用reverse,转置即 m[i][j] = m[j][i]

// 逆时针的话，则是 左右反转->转置


#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        std::reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i; j < matrix[0].size(); j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
    }
};