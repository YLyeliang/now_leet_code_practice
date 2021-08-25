//
// Created by yel on 2021/8/25.
//


// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
//
//0 <= a, b, c, d < n
//a, b, c, and d are distinct.
//nums[a] + nums[b] + nums[c] + nums[d] == target
//You may return the answer in any order.
//
//
//
//Example 1:
//
//Input: nums = [1,0,-1,0,-2,2], target = 0
//Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
//Example 2:
//
//Input: nums = [2,2,2,2,2], target = 8
//Output: [[2,2,2,2]]

// 问题：给定长度为n的数组，返回四个数的子数组，其和等于target.不能取重复索引下的数字，

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums1, int target) {
        vector<vector<int>> res;
        int n = nums1.size();
        if (n < 4)return res;
        sort(nums1.begin(), nums1.end());
        vector<long int> nums(nums1.begin(), nums1.end());  // 测试样例中会出现超过int大小的和值，需要进行转换。
        for (int i = 0; i < n - 3; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;   // 去重

            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break; //如果连续4个数仍大于target,跳过)
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue; // 如果当前数字加上后三个数字仍小于target，跳过
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
                int l = j + 1, r = n - 1;
                int remain = target - nums[i] - nums[j];
                while (l < r) {
                    int sum = nums[l] + nums[r];
                    if (sum < remain) l++;
                    else if (sum > remain) r--;
                    else {
                        res.push_back({static_cast<int>(nums[i]), static_cast<int>(nums[j]), static_cast<int>(nums[l]),
                                       static_cast<int>(nums[r])});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (r > l && nums[r] == nums[r + 1]) r--;
                    }
                }
            }
        }
        return res;

    }
};

int main() {
    vector<int> num{1, 0, -1, 0, -2, 2};
    Solution sol;
    vector<vector<int>> res = sol.fourSum(num, 0);
    return 0;
}