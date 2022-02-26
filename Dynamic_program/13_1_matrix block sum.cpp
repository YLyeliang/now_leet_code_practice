// created by yel on 2022/2/5
// Given a m x n matrix mat and an integer k,
// return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
//
//i - k <= r <= i + k,
//j - k <= c <= j + k, and
//(r, c) is a valid position in the matrix.
//
//Example 1:
//
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//Output: [[12,21,16],[27,45,33],[24,39,28]]
//Example 2:
//
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
//Output: [[45,45,45],[45,45,45],[45,45,45]]
//
//Constraints:
//
//m == mat.length
//n == mat[i].length
//1 <= m, n, k <= 100
//1 <= mat[i][j] <= 100

// 问题：m x n的矩阵和整数k, 返回一个矩阵格式的结果，其中ans[i,j]为 mat[r][c]的所有元素之和。其中:
// r在区间[i-k,i+k]中， c在区间[j-k,j+k]中，且(r,x)为一个合法位置。

// 方法：返回结果为一个同size的矩阵，其中每个元素为当前位置半径为k的矩阵块的元素之和。
// 1. 暴力解法：对于每个元素，计算其矩阵块的元素之和。时间复杂度O(mn)
// 2. 前缀和：
// (1维)1 2 3 4 5 6 7 8 9
// prefix sum: 1 3 6 10 15 21 28 36 45
// k = 1: 3 6 9
// 扩展到二维：
// 1 2 3
// 4 5 6
// 7 8 9
// 计算二维矩阵的前缀和，prefix[i][j] = 左上角到当前位置的前缀和
// 则矩阵块的和, ans[i,j] = prefix[i+k,j+k] - prefix[i+k,j-k-1] - prefix[i-k-1,j+k] + prefix[i-k-1,j-k-1]
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int m;
    int n;

    int extractSum(int i, int j, const vector<vector<int>> &pre) {
        if (i < 0 || j < 0) return 0;
        if (i >= m) i = m - 1;
        if (j >= n) j = n - 1;
        return pre[i][j];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
        m = mat.size(), n = mat[0].size();
        vector<vector<int>> pre(m, vector<int>(n, 0));
        // prefix sum
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                pre[i][j] = mat[i][j] + extractSum(i - 1, j, pre) + extractSum(i, j - 1, pre) -
                            extractSum(i - 1, j - 1, pre);

        // calculate result sum using prefix sum
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = extractSum(i + k, j + k, pre) - extractSum(i + k, j - k - 1, pre) -
                            extractSum(i - k - 1, j + k, pre) + extractSum(i - k - 1, j - k - 1, pre);
        return ans;
    }
};

int main(){

}