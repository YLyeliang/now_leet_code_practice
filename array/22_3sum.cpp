//
// Created by yel on 2021/8/25.
//

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//
//Notice that the solution set must not contain duplicate triplets.
//
//
//
//Example 1:
//
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]
//Example 2:
//
//Input: nums = []
//Output: []
//Example 3:
//
//Input: nums = [0]
//Output: []

// 问题：给定数组，返回所有的三个数的子数组，不能重复取相同索引下的数字，且子数组的和为0.

// 方法:[-4,-1,-1,0,1,2].首先对数组排序。使用双指针方法。遍历数组，以当前数字为基准，对余下数字创建l和r双指针分别指向头部和尾部。由于是已经排序好的
// 数组，双指针向中间收缩，根据三个数之和是否等于0移动指针。大于0则r--,小于0则l++.
// 注意：需要考虑重复的数字，每次移动指针的时候，需要判断是否与上一个数字重复。

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;

            if (i != 0 && nums[i] == nums[i - 1]) continue;  // 判断当前数字是否与前一个数字重复

            while (l < r) {
                int target = nums[i] + nums[l] + nums[r];

                if (target == 0) { // 找到一个子数组
                    res.push_back({nums[i], nums[l], nums[r]});

                    // 移动双指针，进行去重
                    while (r - 1 > l && nums[r - 1] == nums[r]) r--;
                    while (l + 1 < r && nums[l + 1] == nums[l]) l++;

                    // 去重后，移动到下一个数
                    r--;
                    l++;
                } else if (target > 0)
                    r--;
                else
                    l++;
            }
        }
        return res;
    }
};

int main() {
    vector<int> num{-1, 0, 1, 2, -1, -4};
    Solution sol;
    sol.threeSum(num);
    return 0;
}