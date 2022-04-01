// created by yel on 2022/3/30

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.
//
//Example 1:
//Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//
// Example 2:
//Input: strs = [""]
//Output: [[""]]
//
// Example 3:
//Input: strs = ["a"]
//Output: [["a"]]

// 问题：给定字符串数组，将所有的anagrams(相同字母异序词)进行分组，并返回结果

// 方法：
// 直接想法. 1. 遍历数组，以第一个字符为base，统计anagrams,生成一个数组；
// 2. 重新遍历，跳过已统计过的字符；统计其他字符。
// Time: O(n^2)

// 哈希表+排序: 1. 遍历字符串数组，对字符串进行排序，之后构建哈希表，key为排序后的字符，value为未排序的字符数组；
// 2. 遍历哈希表，将value保存为结果输出
//

// 优化：
// 考虑到都是小写字符，排序方式可以改成字符计数的方式

#include "iostream"
#include "unordered_map"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mp;
        for (string s: strs)
            mp[strSort(s)].push_back(s);
        vector<vector<string>> anagrams;
        for (auto p: mp) {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }

private:
    string strSort(const string s) {
        int counter[26] = {0};
        for (char c: s)
            counter[c - 'a']++;
        string t;
        for (int i = 0; i < 26; i++) {
            t += string(counter[i], i + 'a');
        }
        return t;

    }
};