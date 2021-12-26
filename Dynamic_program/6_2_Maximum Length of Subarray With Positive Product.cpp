//
// Created by 叶亮 on 2021/12/19.
//

// Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
//
//A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
//
//Return the maximum length of a subarray with positive product.
//
//
//
//Example 1:
//
//Input: nums = [1,-2,-3,4]
//Output: 4
//Explanation: The array nums already has a positive product of 24.
//Example 2:
//
//Input: nums = [0,1,-2,-3,-4]
//Output: 3
//Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
//Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
// Example 3:
//
//Input: nums = [-1,-2,-3,0,1]
//Output: 2
//Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
//
//
//Constraints:
//
//1 <= nums.length <= 105
//-109 <= nums[i] <= 109

// 问题：给定数组，返回一个子数组的最大长度，该子数组的所有元素之积为正数

// 方法：
// 用pos[i],neg[i]表示以i结尾时的积为正/负的最大连续子数组长度
// pos[0] = 0
// neg[0] = 0
// pos[1] = 1
// neg[1] = 0
// pos[2] = 1  nums[2] = -1
// neg[2] = 2  因为pos[1] = 1， 且 nums[2] < 0 , neg[2] = pos[1] + 1

// 可知，if nums[i] > 0:
// pos[i] = 1 + pos[i-1]
// neg[i] = 1 + neg[i-1] if neg[i-1] > 0 else 0
// if nums[i] < 0:
// pos[i] = 1 + neg[i-1] if neg[i-1] >0 else 0
// neg[i] = 1 + pos[i-1]
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int> &nums) {

        vector<int> pos(nums.size(), 0);
        vector<int> neg(nums.size(), 0);
        if (nums[0] > 0) pos[0] = 1;
        if (nums[0] < 0) neg[0] = 1;
        int res = pos[0];
        if (nums.size() == 0) return res;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                pos[i] = 1 + pos[i - 1];
                neg[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
            } else if (nums[i] < 0) {
                pos[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
                neg[i] = 1 + pos[i - 1];
            }
            res = max(res, pos[i]);
        }
        return res;

    }
};