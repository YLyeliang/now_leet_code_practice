// created by yel on 2022/4/19

// Given two strings word1 and word2, return the minimum number of operations
// required to convert word1 to word2.
//
// You have the following three operations permitted on a word:
//
// Insert a character
// Delete a character
// Replace a character
//
// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
//
// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
//
// Constraints:
//
// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.

// 问题：求编辑距离.
// 有三种操作，插入、删除和替换。字符串word1转换到word2需要的最小操作次数为编辑距离。

// 方法：DP方法
// abb adc
// dp

// 定义dp[i][j]为，将字符串word1[:i]转换成word2[:j]所需的最小次数
// 极端条件下，word1转成0个字符的操作次数为dp[i][0] = len(word1), dp[0][j] =
// len(word2). 注意0个字符和1个字符， dp[1][1]开始有字符

// 对问题进行抽象，假设已知word1[:i-1]到word2[:j-1]的次数dp[i-1][j-1]，
// 当word1[i-1] == word2[j-1]，则不需要操作，dp[i][j] = dp[i-1][j-1].
// e.g, 已知dp[0][0] = 0, dp[1][1] = dp[0][0]
// 当word1[i-1] != word2[j-1]，有三种情况：
// 1. 替换word1[i-1]为word2[j-1]. 此时， dp[i][j] = dp[i-1][j-1] + 1
// 即当前的两个字符相等.
// 2. if word1[:i-1] == word2[:j], 删除word1[i-1]. dp[i][j] = dp[i-1][j] + 1

// 3. if word1[:i]+ word2[j-1] = word2[:j], 插入word2[j-1]到word1[:i]. dp[i][j]
// = dp[i][j-1] + 1

// 该方法time: O(nm),   space: O(nm)

// 进一步优化；
#include <vector>

#include "iostream"
#include "string"

using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // initialize
    for (int i = 1; i <= m; i++) dp[i][0] = i;
    for (int j = 1; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] ==
            word2[j - 1])  // word[i-1] 对应第i个字符
                           // dp[i]对应第i个字符(因为包括0字符的情况)
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min(dp[i - 1][j - 1] + 1,
                         min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
      }
    return dp[m][n];
  }
};

// Note that each time when we update dp[i][j], we only need dp[i - 1][j - 1],
// dp[i][j - 1] and dp[i - 1][j]. We may optimize the space of the code to use
// only two vectors.
class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<int> pre(n + 1, 0), cur(n + 1, 0);
    for (int j = 1; j <= n; j++) {
      pre[j] = j;
    }
    for (int i = 1; i <= m; i++) {
      cur[0] = i;
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          cur[j] = pre[j - 1];
        } else {
          cur[j] = min(pre[j - 1], min(cur[j - 1], pre[j])) + 1;
        }
      }
      fill(pre.begin(), pre.end(), 0);
      swap(pre, cur);
    }
    return pre[n];
  }
};

// Or even just one vector.
class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size(), pre;
    vector<int> cur(n + 1, 0);
    for (int j = 1; j <= n; j++) {
      cur[j] = j;
    }
    for (int i = 1; i <= m; i++) {
      pre = cur[0];
      cur[0] = i;
      for (int j = 1; j <= n; j++) {
        int temp = cur[j];
        if (word1[i - 1] == word2[j - 1]) {
          cur[j] = pre;
        } else {
          cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
        }
        pre = temp;
      }
    }
    return cur[n];
  }
};