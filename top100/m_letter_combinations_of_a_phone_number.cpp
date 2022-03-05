// created by yel on 2022/3/5

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that
// the number could represent. Return the answer in any order.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below.
// Note that 1 does not map to any letters.
//
//Example 1:
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

//Example 2:
//Input: digits = ""
//Output: []

//Example 3:
//Input: digits = "2"
//Output: ["a","b","c"]
//
//Constraints:
//
//0 <= digits.length <= 4
//digits[i] is a digit in the range ['2', '9'].

// 问题：给定一个字符串，包含2-9，返回数字可能表示的所有组合。
// 数字表示的字符为手机输入法九宫格。

// 方法：
// 1. 暴力解法：首先对数字和对应的字符做个hash map，然后遍历数字，每个数字对应的字符进行遍历组合。
//

// 2. 暴力解法会重复遍历。因此，创建一个数组，来存储之前遍历的结果。然后遍历剩下的字符串时,
// 遍历之前的结果，每个结果+上当前遍历的字符。并刷新结果。
// O(n^3)

#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    const vector<string> pad = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res{""};
        for (auto d: digits) {  // iter the digits
            vector<string> tmp; //  store the combination
            for (auto c: pad[d - '0']) {    // iter the char string.
                for (auto s: res)  //
                    tmp.push_back(s + c);
            }
            res.swap(tmp);  // 交换两个容器的内容
        }
        return res;
    }
};