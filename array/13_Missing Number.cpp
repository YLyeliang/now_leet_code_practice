//
// Created by yel on 2021/8/15.
//

// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
//
//Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
//
//
//
//Example 1:
//
//Input: nums = [3,0,1]
//Output: 2
//Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
//Example 2:
//
//Input: nums = [0,1]
//Output: 2
//Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

// 问题：给定一个数组，包含n个不同的数，其在范围[0,n]内，返回范围内缺失的数。 Note: O(1) space O(n) time

// 方法：1. 根据等差数列的公式，和为(1+n)*n/2,则减去所有其他数，剩下的即为缺失的数

#include "vector"

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int res = (1 + nums.size()) * nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            res -= nums[i];
        }
        return res;

    }
};