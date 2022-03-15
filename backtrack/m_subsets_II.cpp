// created by yel on 2022/3/14

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.
//
//Example 1:
//Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
//
// Example 2:
//Input: nums = [0]
//Output: [[],[0]]
//
// Constraints:
//1 <= nums.length <= 10
//-10 <= nums[i] <= 10

// 问题：给定包含重复数字的数组，返回所有可能的子集。不能包含重复的子集。

// 方法：相对于子集I，这里的数组中元素存在重复数字。

// 回溯法
// 需要修改回溯过程中的条件判断,来过滤掉重复数字

#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> tmp{};
        std::sort(nums.begin(), nums.end());
        backtrack(res, tmp, nums, 0);
        return res;

    }

    void backtrack(vector<vector<int>> &res, vector<int> &tmp, vector<int> &nums, int start) {
        res.push_back(tmp);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            tmp.push_back(nums[i]);
            backtrack(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};