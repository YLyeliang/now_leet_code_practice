//
// Created by 叶亮 on 2021/12/26.
//

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
//
//Note that the same word in the dictionary may be reused multiple times in the segmentation.
//
//
//
//Example 1:
//
//Input: s = "leetcode", wordDict = ["leet","code"]
//Output: true
//Explanation: Return true because "leetcode" can be segmented as "leet code".
//Example 2:
//
//Input: s = "applepenapple", wordDict = ["apple","pen"]
//Output: true
//Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//Note that you are allowed to reuse a dictionary word.
//Example 3:
//
//Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//Output: false

// Constraints:
//
//1 <= s.length <= 300
//1 <= wordDict.length <= 1000
//1 <= wordDict[i].length <= 20
//s and wordDict[i] consist of only lowercase English letters.
//All the strings of wordDict are unique.

// false: appleabandonme word: apple abandon me aband

// 问题：给定字符串s和单词数组，问能否将字符串按照数组里的单词分开

// 分析：1. 错误解法：1. 遍历数组，对每个单词做匹配，匹配成功则移到下一个。原因：某些字符串可以匹配多个单词，并没有做出最合适的匹配选择；
// 2. DP解法：分解子问题，这里需要的是对字符串做单词的匹配。可能包含多种匹配的情况，这里需要建立一个DP数组来做记忆；
// 建立长度为s的dp数组，其中dp[i]表示索引为i的字符以单词w结尾。那么，遍历字符串
// dp[i] = s[i - len(w)+1:i+1] in wordDict && dp[i-len(w)] == True.

#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (auto w: wordDict) {
                if (w.length() <= i)
                    if (dp[i - w.length()] == true && s.substr(i - w.length(), w.length()) == w) {
                        dp[i] = true;
                        break;
                    }

            }
        }
        return dp.back();
    }
};