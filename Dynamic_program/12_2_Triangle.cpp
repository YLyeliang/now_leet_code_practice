// created by yel on 2022/1/7
// Given a triangle array, return the minimum path sum from top to bottom.
//
//For each step, you may move to an adjacent number of the row below. More formally,
// if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
//
//Example 1:
//
//Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
//Output: 11
//Explanation: The triangle looks like:
//   2
//  3 4
// 6 5 7
//4 1 8 3
//The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
//Example 2:
//
//Input: triangle = [[-10]]
//Output: -10
//
//Constraints:
//
//1 <= triangle.length <= 200
//triangle[0].length == 1
//triangle[i].length == triangle[i - 1].length + 1
//-104 <= triangle[i][j] <= 104
//
//Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

// 问题：给定三角形，求从上到下的最小路径和。每次只能走相邻的路径

// 方法：要求O(n) extra space. 从上到下累加最小路径的和，返回最后一行的最小值即可。其中，0 -1只与上一行的一个数有关。
// 中间的数则与相邻的数有关。triangle[i,j] = min(triangle[i-1,j-1],triangle[i-1,j])+ triangle[i,j]


#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i].back() += triangle[i - 1].back();
            for (int j = 1; j < triangle[i].size() - 1; j++) {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};