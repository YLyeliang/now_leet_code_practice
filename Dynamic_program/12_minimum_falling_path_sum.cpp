// created by yel on 2022/1/6

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
//
//A falling path starts at any element in the first row and chooses the element in the next row
// that is either directly below or diagonally left/right. Specifically,
// the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
//
//Example 1:
//
//Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
//Output: 13
//Explanation: There are two falling paths with a minimum sum as shown.
//Example 2:
//
//Input: matrix = [[-19,57],[-40,-5]]
//Output: -59
//Explanation: The falling path with a minimum sum is shown.
//
//Constraints:
//n == matrix.length == matrix[i].length
//1 <= n <= 100
//-100 <= matrix[i][j] <= 100

// 问题：给定n*n的矩阵，返回下落路径的最小和。其中，下落路径起始于第一行的任意位置，并且只能往下落到相邻范围内。

// 方法：以例1为例，到达底部后m[2,0]的和为s[1,0]+m[2,0] or s[1,1]+m[2,0].其最小和为min(s[1,0],s[1,1])+m[2,0]
// 可知，当前行的路径最小和取决于上一行的相邻路径最小和。即s[i,j] = min(s[i-1,j],s[i-1,j-1],s[i-1,j+1])+m[i,j]

// 建立一个长为n的dp数组，用于存储当前行的截止到每一个元素的最小和。

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        vector<int> dp(matrix[0].size(), 0);
        for (int i = 0; i < matrix[0].size(); i++) {
            dp[i] = matrix[0][i];
        }
        for (int i = 1; i < matrix.size(); i++) {
            vector<int> tmp(dp.size());
            for (int j = 0; j < matrix[0].size(); j++) {
                if (j == 0)
                    tmp[j] = min(dp[j], dp[j + 1]) + matrix[i][j];
                else if (j == matrix[0].size() - 1)
                    tmp[j] = min(dp[j], dp[j - 1])+ matrix[i][j];
                else
                    tmp[j] = min(dp[j - 1], min(dp[j], dp[j + 1]))+ matrix[i][j];
            }
            dp = tmp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// 优化版本：使用O(1)space
int minFallingPathSum(vector<vector<int>>& A) {
    for (auto i = 1; i < A.size(); ++i)
        for (auto j = 0; j < A.size(); ++j)
            A[i][j] += min({ A[i-1][j], A[i-1][max(0,j-1)], A[i-1][min((int)A.size()-1,j+1)] });
    return *min_element(begin(A[A.size() - 1]), end(A[A.size() - 1]));
}