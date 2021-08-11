//
// Created by yel on 2021/8/11.
//

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
//
//
//
//Example 1:
//
//Input: nums = [1,2,3,1]
//Output: true
//Example 2:
//
//Input: nums = [1,2,3,4]
//Output: false
//Example 3:
//
//Input: nums = [1,1,1,3,3,4,3,2,4,2]
//Output: true

// 问题：给定整数数组，如果有重复数字返回true,否则为false.

// 分析：
// 1. 一行代码：数组转集合,比较大小； :)
// 2: 构建字典/哈希表映射，遍历数组时索引哈希表
// 3. 先对数组排序，然后遍历数组，查看前后是否相等（最快）


#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};