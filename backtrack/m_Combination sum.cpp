// created by yel on 2022/3/14
// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order.
//
//The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.
//
//It is guaranteed that the number of unique combinations that sum up to target is less than
// 150 combinations for the given input.
//
//Example 1:
//Input: candidates = [2,3,6,7], target = 7
//Output: [[2,2,3],[7]]
//Explanation:
//2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
//7 is a candidate, and 7 = 7.
//These are the only two combinations.
//
// Example 2:
//Input: candidates = [2,3,5], target = 8
//Output: [[2,2,2,2],[2,3,3],[3,5]]
//
// Example 3:
//Input: candidates = [2], target = 1
//Output: []
//
//Constraints:
//
//1 <= candidates.length <= 30
//1 <= candidates[i] <= 200
//All elements of candidates are distinct.
//1 <= target <= 500

// 问题：给定不重复的数组candidates,和target.返回一个list,包含所有和等于target的独立组合，candidates中的数字可以重复利用。
// 独立定义为，至少有一个数字利用的频率不一致。       题目中的组合数量少于150

// 方法：首先思考一下暴力的方法，遍历整个数组，针对当前数字num, 计算target - num.然后遍历剩下数组，继续减直到找到结果=0的组合。
// 然后继续使用当前数字相减，重复上述过程。 O(N^3)

// 1. 回溯
// 考虑递归的方式，每次计算remain = target - num. 然后递归调用函数进行计算，结果=0时append到数组当中。
// 然后进行回溯，每次回溯时移除数组的最后一个字符。同时遍历candidates的下一个数.
// NOTE:常见回溯问题
// https://leetcode.com/problems/combination-sum/discuss/16502/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)

// 2. DP
// 考虑到暴力方法中有很多重复遍历的地方。比如说计算8 -2 = 6时，6的组合有222和 3 3两种。每次遍历会重新计算。如果将中间结果进行
// 保存，则可以进行节省。
// 则可以考虑构建dp数组，其中dp[i]表示target为i时的所有独立组合。
//



#include "iostream"
#include "vector"

using namespace std;


// 回溯
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        std::sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtrack(res, temp, candidates, target, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &temp, vector<int> &candidates, int remain, int start) {
        if (remain < 0) return;
        else if (remain == 0) res.push_back(temp);
        else
            for (int i = start; i < candidates.size(); i++) {
                temp.push_back(candidates[i]);
                backtrack(res, temp, candidates, remain - candidates[i], i);
                temp.pop_back();
            }
    }
};



