// created by yel on 2024/2/23

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//
//
// Example 1:
//
//
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED" Output: true Example 2:
//
//
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE" Output: true Example 3:
//
//
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB" Output: false
//
//
// Constraints:
//
// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
//
//
// Follow up: Could you use search pruning to make your solution faster with a larger board?

// 给定 mxn的字符串矩阵，和字符串str,判断矩阵中是否存在相邻字符连成的串 == str
// 回溯： 遍历矩阵，
// 1. 对于每一个cell，深度优先搜索其上下左右四个方向
// 2. 搜索函数：当前cell != word[0](首字母)，则返回，回溯到上一步骤
// 3. 满足时，将当前cell赋为#(表示已走过)，取子集substr(1)，继续四个方向搜索
// 4. word ==0,表示全部已经被找到，return true

#include "iostream"
#include "vector"
using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); i++)
      for (int j = 0; j < board[0].size(); j++)
        if (dfs(board, i, j, word))
          return true;
    return false;
  }

  bool dfs(vector<vector<char>> &board, int i, int j, string &word) {
    if (word.length() == 0)
      return true; // 剩下字符串为空，说明全部找到
    // 超出边界 or 当前字符不等于要搜索的字符
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[0] != board[i][j])
      return false;
    char tmp = board[i][j]; // 当前的board
    board[i][j] = '#';   // 表明已经搜索过,用于某一条方向搜索时未回溯的状态表示，避免重复搜索
    string s = word.substr(1);
    bool res = (dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s) || dfs(board, i - 1, j, s) ||
                dfs(board, i + 1, j, s));
    // 回溯
    board[i][j] = tmp;
    return res;
  }
};