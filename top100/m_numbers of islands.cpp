// created by yel on 2022/4/4

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and
// '0's (water), return the number of islands.
//
// An island is surrounded by water and is formed by connecting adjacent lands
// horizontally or vertically. You may assume all four edges of the grid are all
// surrounded by water.
//
// Example 1:
// Input: grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
// Output: 1
// Example 2:
//
// Input: grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
// Output: 3
//
//
// Constraints:
//
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

// 问题：给定mxn的矩阵，矩阵由1(岛屿)和0(水)构成，返回岛屿数量.
// 一个岛屿定义为相邻陆地(横向纵向)组成，且由水包围，. 并假定矩阵边缘均为水域.

// 方法：DFS和BSF均可.

// DFS:
// 遍历数组，构建一个二维矩阵，表示是否已经搜索过.每次遇到1时判断是否搜索过，已搜则跳过，
// 否则岛屿数量+1，进行DFS，并将对应位置设置为1.
// 另一种更简单的方法不需要构建二维矩阵，在遍历时，遇到1则++,并将整个岛屿进行删除.

// BFS:
//

#include "iostream"
#include "queue"
#include "vector"
using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    vector<vector<int>> s;
    int res = 0;
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        if (grid[i][j] == '1') {
          res++;
          dfs(grid, i, j);
        }
    return res;
  }
  // delete adjacent islands
  void dfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
    grid[i][j] = '0';
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }
};

class Solution2 {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0,
        offsets[] = {0, 1, 0, -1, 0};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          islands++;
          grid[i][j] = '0';
          queue<pair<int, int>> todo;
          todo.push({i, j});
          while (!todo.empty()) {
            pair<int, int> p = todo.front();
            todo.pop();
            for (int k = 0; k < 4; k++) {
              int r = p.first + offsets[k], c = p.second + offsets[k + 1];
              if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                grid[r][c] = '0';
                todo.push({r, c});
              }
            }
          }
        }
      }
    }
    return islands;
  }
};