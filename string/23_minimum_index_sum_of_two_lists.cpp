//
// Created by 叶亮 on 2021/12/11.
//

// Suppose Andy and Doris want to choose a restaurant for dinner,
// and they both have a list of favorite restaurants represented by strings.
//
// You need to help them find out their common interest with the least list index sum.
// If there is a choice tie between answers, output all of them with no order requirement.
// You could assume there always exists an answer.
//
//
//
//Example 1:
//
//Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
//Output: ["Shogun"]
//Explanation: The only restaurant they both like is "Shogun".
//Example 2:
//
//Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
//Output: ["Shogun"]
//Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).

// 问题：给定两个字符串数组，找到两个相同的字符串，且他们的索引/下标之和最小。

// 方法：1. O(n^2): 遍历List1的同时遍历list2,将相同的字符串和索引和添加，最后比较最小的索引和取对应的字符串。
// 2. O(n): 使用hash，将所有字符串存入hash表，然后遍历另一个字符串，寻找相同的字符串，取最小索引和。
#include "iostream"
#include "string"
#include "map"
#include "vector"

using namespace std;


class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        vector<string> res;
        map<string, int> dict1 = {};
        for (int i = 0; i < list1.size(); i++) dict1[list1[i]] = i;
        int min = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            if (dict1.count(list2[i]) != 0)
                if (dict1[list2[i]] + i < min) min = dict1[list2[i]] + i, res.clear(), res.push_back(list2[i]);
                else if (dict1[list2[i]] + i == min) res.push_back(list2[i]);
        }
        return res;
    }
};