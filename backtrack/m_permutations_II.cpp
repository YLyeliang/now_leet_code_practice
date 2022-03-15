// created by yel on 2022/3/14

// Given a collection of numbers, nums, that might contain duplicates,
// return all possible unique permutations in any order.
//
//Example 1:
//Input: nums = [1,1,2]
//Output:
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
//
// Example 2:
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//Constraints:
//1 <= nums.length <= 8
//-10 <= nums[i] <= 10

// 问题：给定数组nums,可能包含重复数字，返回所有独立的置换数组。

// 方法：相比I,数组可包含重复数字。
// 置换后的数组为数字元素之间的交换。怎么样去除重复字符是关键。
// 在不包含重复数字的时候，每次递归从0开始遍历,只需要判断当前字符是否已存在于tmp中即可。
// 在包含重复数字后，需要一个额外的变量来记录当前数字是否被使用，如果被使用，则跳过该数字进入下一个。
// 此外，当以重复数字重新遍历时，需要跳过(因为已经回溯过了)

#include "iostream"
#include "vector"

using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        std::sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrack(res, tmp, nums, used);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &tmp, vector<int> &nums, vector<bool> &used) {
        if (tmp.size() == nums.size())
            res.push_back(tmp);
        else
            for (int i = 0; i < nums.size(); i++) {
                if (used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
                used[i] = true;
                tmp.push_back(nums[i]);
                backtrack(res, tmp, nums, used);
                used[i] = false;
                tmp.pop_back();
            }

    }
};