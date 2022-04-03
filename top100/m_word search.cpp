// created by yel on 2022/4/3

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cells,
// where adjacent cells are horizontally or vertically neighboring.
// The same letter cell may not be used more than once.
//
//Example 1:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
//Output: true
//
// Example 2:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
//Output: true
//
// Example 3:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
//Output: false
//
//Constraints:
//m == board.length
//n = board[i].length
//1 <= m, n <= 6
//1 <= word.length <= 15
//board and word consists of only lowercase and uppercase English letters.
//
//
//Follow up: Could you use search pruning to make your solution faster with a larger board?

// 问题：给定mxn的字符矩阵，和字符串word. 如果word能被矩阵中的一条路径构成(相邻元素),返回true.每个字符只能使用一次

// 方法：DFS搜索.遍历矩阵，以某一个点开始，进行DFS搜索，搜索四个方向，当遇到不匹配的字符或超出边界则返回false,
// 回溯到之前搜索的节点，往另一个方向DFS. time O(mn4^k) k == word.size()

#include "iostream"
#include <vector>

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
        if (word.size() == 0)
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