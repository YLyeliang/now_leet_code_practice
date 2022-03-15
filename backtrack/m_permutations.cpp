// created by yel on 2022/3/14

// Given an array nums of distinct integers, return all the possible permutations.
// You can return the answer in any order.
//
//Example 1:
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

//Example 2:
//Input: nums = [0,1]
//Output: [[0,1],[1,0]]

//Example 3:
//Input: nums = [1]
//Output: [[1]]
//
//Constraints:
//1 <= nums.length <= 6
//-10 <= nums[i] <= 10
//All the integers of nums are unique.

// 问题：给定不重复的数组，返回所有可能的置换

// 方法：回溯法.递归地遍历数组，遍历过程中每次判断当前的数字是否已经添加到了tmp数组当中，如果已添加，则遍历下一个数字；
// 否则，添加到当前数组中，然后递归；得到结果之后回溯到上一个数字，继续遍历下一个数字。


#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res, tmp, nums);
        return res;

    }

    void backtrack(vector<vector<int>> &res, vector<int> &tmp, vector<int> &nums) {
        if (tmp.size() == nums.size())
            res.push_back(tmp);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (std::find(tmp.begin(), tmp.end(), nums[i]) != tmp.end()) continue;
                tmp.push_back(nums[i]);
                backtrack(res, tmp, nums);
                tmp.pop_back();
            }
        }
    }
};