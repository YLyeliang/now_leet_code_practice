// created by yel on 2022/3/15

// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.
//
//Example 1:
//Input: candidates = [10,1,2,7,6,1,5], target = 8
//Output:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//]

//Example 2:
//Input: candidates = [2,5,2,1,2], target = 5
//Output:
//[
//[1,2,2],
//[5]
//]
//
//Constraints:
//1 <= candidates.length <= 100
//1 <= candidates[i] <= 50
//1 <= target <= 30

// 问题：给定一个数组candidates(包含重复数字),和一个target。求和为target的所有独立组合(candidates中的数字只能利用一次)

// 方法：相比I，这里的数组包含重复数字，并且只可以利用一次。难点在于如何略过已使用过的重复数字。
// 回溯：首先对数组进行升序排序，25212 -> 12225. 在回溯递归期间，设置一个额外的变量来记录字符是否已经使用过.
// 遇到重复字符时，如果前一个数字使用过，则表明是持续递归，未回溯过的数组，可以统计；
// 如果前一个没有使用过，则表明是已经回溯删除的数字，那么当前数字不需要再进行额外的统计


#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(candidates.size(), false);
        std::sort(candidates.begin(), candidates.end());
        backtrack(res, tmp, candidates, used, target, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &tmp, vector<int> &candidates, vector<bool> &used, int target,
                   int start) {
        if (!tmp.empty() && target == 0)
            res.push_back(tmp);
        else if (target < 0) return;
        else
            for (int i = start; i < candidates.size(); i++) {
                if (i > start && !used[i - 1] && candidates[i] == candidates[i - 1]) continue;
                tmp.push_back(candidates[i]);
                used[i] = true;
                backtrack(res, tmp, candidates, used, target - candidates[i], i + 1);
                used[i] = false;
                tmp.pop_back();
            }
    }
};