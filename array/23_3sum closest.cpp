//
// Created by yel on 2021/8/25.
//

// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
//
//Return the sum of the three integers.
//
//You may assume that each input would have exactly one solution.
//
//
//
//Example 1:
//
//Input: nums = [-1,2,1,-4], target = 1
//Output: 2
//Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//Example 2:
//
//Input: nums = [0,0,0], target = 1
//Output: 0

// 问题：给定长度为n的数组和target,找到三个数的数组，其和最接近target.返回他们的和。
// 与3sum思想一致，使用双指针方法。区别在于这里判断的是子数组的和与target的距离，根据sum和target的大小来决定双指针的移动。sum>target,r--; else l++;

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;

            if (i != 0 && nums[i] == nums[i - 1]) continue;  // 判断当前数字是否与前一个数字重复

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return sum;
                if (abs(target - sum) < abs(target - res))  // 是否是最近距离
                    res = sum;

                if (sum > target)
                    r--;
                else
                    l++;
            }
        }
        return res;
    }
};