// created by yel on 2024/2/23
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard
// such that no two queens attack each other.
//
// Given an integer n, return all distinct solutions to the n-queens puzzle. You
// may return the answer in any order.
//
// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space,
// respectively.
//
// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as
// shown above Example 2:
//
// Input: n = 1
// Output: [["Q"]]
//
// Constraints:
//
// 1 <= n <= 9

// 问题：N皇后问题，放置n个皇后在一个nxn的棋盘上，彼此不在攻击范围
// 给定n,返回所有离散解. Q and . 表示皇后和空格
// 皇后可以攻击同一行、同一列、同一斜线上的任何棋子

// 回溯算法：遍历行，在每一行检查哪一列是合法的(45角、135角、列上是否存在Q)，合法即加入Q，搜寻完后回溯，直到搜寻到第n行的合法q
//

#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> tmp(n, string(n, '.'));
    BackTrack(res, tmp, 0, n);
    return res;
  }

  void BackTrack(vector<vector<string>>& res, vector<string>& tmp, int row,
                 const int& n) {
    if (row == n) {
      res.emplace_back(tmp);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (CheckValid(tmp, row, col, n)) {
        tmp[row][col] = 'Q';
        BackTrack(res, tmp, row + 1, n);
        tmp[row][col] = '.';
      }
    }
  }
  bool CheckValid(vector<string>& tmp, int row, int col, const int& n) {
    // col check
    for (int i = 0; i < n; ++i) {
      if (tmp[i][col] == 'Q') {
        return false;
      }
    }
    // 45 check
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (tmp[i][j] == 'Q') {
        return false;
      }
    }
    // 135 check
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (tmp[i][j] == 'Q') {
        return false;
      }
    }

    return true;
  }
};

// Solution B: Use flag vectors as bitmask, 4ms:
//
// The number of columns is n, the number of 45° diagonals is 2 * n - 1, the number of 135° diagonals is also 2 * n - 1. When reach [row, col], the column No. is col, the 45° diagonal No. is row + col and the 135° diagonal No. is n - 1 + col - row. We can use three arrays to indicate if the column or the diagonal had a queen before, if not, we can put a queen in this position and continue.
//
// NOTE: Please don't use vector<bool> flag to replace vector<int> flag in the following C++ code. In fact, vector<bool> is not a STL container. You should avoid to use it. You can also get the knowledge from here and here.

// 使用数组表示是否已经使用过，不用每次迭代遍历是否合理
class Solution {
 public:
  std::vector<std::vector<std::string> > solveNQueens(int n) {
    std::vector<std::vector<std::string> > res;
    std::vector<std::string> nQueens(n, std::string(n, '.'));
    std::vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
    solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
    return res;
  }
 private:
  void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag_col, std::vector<int> &flag_45, std::vector<int> &flag_135, int row, int &n) {
    if (row == n) {
      res.push_back(nQueens);
      return;
    }
    for (int col = 0; col != n; ++col)
      if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
        flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
        nQueens[row][col] = 'Q';
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
        nQueens[row][col] = '.';
        flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
      }
  }
};

// But we actually do not need to use three arrays, we just need one. Now, when reach [row, col], the subscript of column is col, the subscript of 45° diagonal is n + row + col and the subscript of 135° diagonal is n + 2 * n - 1 + n - 1 + col - row.

class Solution {
 public:
  std::vector<std::vector<std::string> > solveNQueens(int n) {
    std::vector<std::vector<std::string> > res;
    std::vector<std::string> nQueens(n, std::string(n, '.'));
    /*
    flag[0] to flag[n - 1] to indicate if the column had a queen before.
    flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
    flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
    */
    std::vector<int> flag(5 * n - 2, 1);
    solveNQueens(res, nQueens, flag, 0, n);
    return res;
  }
 private:
  void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag, int row, int &n) {
    if (row == n) {
      res.push_back(nQueens);
      return;
    }
    for (int col = 0; col != n; ++col)
      if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
        flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
        nQueens[row][col] = 'Q';
        solveNQueens(res, nQueens, flag, row + 1, n);
        nQueens[row][col] = '.';
        flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
      }
  }
};
