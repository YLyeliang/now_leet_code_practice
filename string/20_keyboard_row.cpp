//
// Created by yel on 2021/9/15.
//

// Given an array of strings words,
// return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
//
//In the American keyboard:
//
//the first row consists of the characters "qwertyuiop",
//the second row consists of the characters "asdfghjkl", and
//the third row consists of the characters "zxcvbnm".
//
//Example 1:
//
//Input: words = ["Hello","Alaska","Dad","Peace"]
//Output: ["Alaska","Dad"]
//Example 2:
//
//Input: words = ["omk"]
//Output: []
//Example 3:
//
//Input: words = ["adsdf","sfd"]
//Output: ["adsdf","sfd"]

// 问题：给定字符串数组，返回其中所有的能够被键盘上单行所表示的字符串。"qwertyuiop" "asdfghjkl" "zxcvbnm"

// 方法：构建一个字母表数组，每一行的字符用不同的二进制表示001,010,100。
// 遍历所有字符串，每个字符串用一个标志位7(111)表示，该标志位与每一个字符做与操作,
// 如果结果为1，2，4，则说明来自同一行。如果结果为0，则说明有字符来自其他行

#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        vector<int> dict(26);
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for (int i = 0; i < rows.size(); i++) {
            for (auto c : rows[i]) dict[c - 'A'] = 1 << i;
        }
        vector<string> res;
        for (auto w : words) {
            int r = 7;
            for (char c : w) {
                r &= dict[toupper(c) - 'A'];
                if (r == 0) break;
            }
            if (r) res.push_back(w);
        }
        return res;
    }
};

int main() {
    vector<string> str{"Hello", "Alaska", "Dad", "Peace"};
    Solution sol;
    sol.findWords(str);
}