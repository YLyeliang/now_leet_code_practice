// created by yel on 2022/3/14

// Given an integer array nums of unique elements, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.
//
//Example 1:
//
//Input: nums = [1,2,3]
//Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//Example 2:
//
//Input: nums = [0]
//Output: [[],[0]]
//
//Constraints:
//
//1 <= nums.length <= 10
//-10 <= nums[i] <= 10
//All the numbers of nums are unique.

// 问题：给定不重复的数组，返回所有可能的子集。不能使用重复的子集，可包含空集。

// 方法：回溯法.定义一个递归函数，该递归函数要明确当前时刻需要做什么(一般是添加结果).
// 然后遍历数组,添加结果然后递归，跳出递归后回溯到上一个时刻),继续完成递归.

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res{};
        vector<int> tmp;
        backtrack(res, tmp, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &tmp, vector<int> &nums, int start) {
        res.push_back(tmp);
        for (int i = start; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrack(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }

};