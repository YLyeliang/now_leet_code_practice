// created by yel on 2022/1/20

// Given a string s, find the length of the longest substring without repeating characters.
//
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
//
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
//
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//Constraints:
//0 <= s.length <= 5 * 104
//s consists of English letters, digits, symbols and spaces

// 给定字符串，找到没有重复字符的最大子串
// 使用滑动窗口的方法，使用一个向量来存储字符最后一次的出现位置，初始化为-1。
// 遍历字符串，每次迭代索引当前字符在向量中的位置，如果大于最后一次的出现位置
// （表明当前字符和最后一次出现位置的字符相同），则计算该位置与当前位置的距离
// 同时更新当前字符的最后一次出现位置


#include "iostream"
#include "string"
#include "vector"
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256,-1);
        int start = -1;
        int res=0;
        for (int i=0;i<s.length();i++){
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            res = max(res,i-start);
        }
        return res;
    }
};

int main() {
    string s = "abcabcbb";
    Solution sol;
    int res = sol.lengthOfLongestSubstring(s);
    cout << res << endl;
}