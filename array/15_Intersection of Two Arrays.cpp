//
// Created by yel on 2021/8/15.
//

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
//
//
//
//Example 1:
//
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2]
//Example 2:
//
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [9,4]
//Explanation: [4,9] is also accepted.

// 问题： 求两个数组的交集，结果中每个数字是唯一的


#include "vector"
#include "unordered_set"

using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
        for (auto n : nums2) {
            if (s.erase(n)) {
                ans.push_back(n);
            }
        }
        return ans;
    }
};