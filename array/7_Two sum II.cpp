//
// Created by yel on 2021/8/9.
//

// Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
//
//Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.
//
//The tests are generated such that there is exactly one solution. You may not use the same element twice.
//
//
//
//Example 1:
//
//Input: numbers = [2,7,11,15], target = 9
//Output: [1,2]
//Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
//Example 2:
//
//Input: numbers = [2,3,4], target = 6
//Output: [1,3]
//Example 3:
//
//Input: numbers = [-1,0], target = -1
//Output: [1,2]

// 问题：给定有序数组，找到两个数，其和为target. 返回这两个数的索引(1-indexed)

// 方法：可以构建一个哈希表映射，key:value分别对应 数字：索引。
// 遍历数组，对每个数首先用target-num检索哈希表，没找到则用num:index存到哈希表中。

// 2.双指针方法，首尾双指针数字相加，若大于target,右指针左移，否则左指针右移。


#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> dict;
        for (int i = 0; i < numbers.size(); ++i) {
            if (dict.find(target - numbers[i]) != dict.end())
                return {min(dict[target - numbers[i]], i + 1), max(dict[target - numbers[i]], i + 1)};
            dict[numbers[i]] = i + 1;

        }
        return {};
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        auto l = numbers.begin(), r = numbers.end() - 1;
        while (*l + *r != target) {
            if (*l + *r > target)
                r--;
            else
                l++;
        }
        return {int(l - numbers.begin()), int(r - numbers.begin())};
    }
};