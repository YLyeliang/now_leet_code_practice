//
// Created by yel on 2021/8/11.
//

// Given an array nums of size n, return the majority element.
//
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
//
//
//
// Example 1:
//
// Input: nums = [3,2,3]
// Output: 3
// Example 2:
//
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// 问题：长度为n的数组，返回出现次数超过n/2的元素。

// 分析：
// 1.暴力：遍历整个数组，将每一个元素加入到哈希表中，出现次数+1, O(n) time O(n) space.
// 2. Boyer-Moore majority vote algorithm https://www.cs.utexas.edu/~moore/best-ideas/mjrty/.
// 多数投票算法，该算法的核心：遍历整个数组，以第一个数为候选数，其出现次数计为1，当后续数字相同时次数+1，不相同时-1，当计数为0时，更换新遇到的数字
// 重新计数，直到最后，剩下的数即为最多数的元素。

#include "vector"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate)
                count++;
            else
                count--;

        }
        return candidate;
    }
};