// created by yel on 2022/3/31

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
// This matrix has the following properties:
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//
//Example 1:
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//Output: true
//
// Example 2:
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//Output: false
//
//Constraints:
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 100
//-104 <= matrix[i][j], target <= 104

// 问题：给定一个mxn的矩阵，搜索target. 矩阵的特性如下：
// - 每一行为升序
// - 每一行的起始数字大于上一行的末尾数字

// 方法：
// 乍一看像是二分搜索. 先纵向二分搜索定位行，然后横向二分搜索定位列即可
// 遇到的问题： 由于使用二分搜索定位的时候不一定能找到对应的值，有可能导致l!=r的情况发生
// 这里需要根据每一行的首数字最小的规则，来确定二分搜索迭代终止条件 1  10 23    13     13 < 23, r--, 13> 10 l = mid
//


// 2. 直接将矩阵看成一个排序好的数组. 按照行进行展开即可。
// m*n 矩阵转数组 -> matrix[x][y] = a[x*n +y]
// 数组转矩阵 -> a[x] -> matrix[x/n][x%n]



#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        int row = 0, col = 0;
        while (row < m) {
            int mid = (m + row) / 2 + 1;
            if (target < matrix[mid][0]) {
                m = mid - 1;
            } else
                row = mid;
        }
        while (col < n) {
            int mid = (n + col) / 2;
            if (matrix[row][mid] < target)
                col = mid + 1;
            else
                n = mid;
        }
        return matrix[row][col] == target;
    }
};


class Solution2 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r) {
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / n][mid % n] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return matrix[r / n][l % n] == target;
    }

};


int main() {
    Solution sol;
    vector<vector<int>> a = {{1,  3,  5,  7},
                             {10, 11, 16, 20},
                             {23, 30, 34, 60}};
    sol.searchMatrix(a, 3);
}