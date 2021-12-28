// An integer array is called arithmetic if it consists of at least three elements and
// if the difference between any two consecutive elements is the same.
//
//For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
//Given an integer array nums, return the number of arithmetic subarrays of nums.
//
//A subarray is a contiguous subsequence of the array.
//
//
//
//Example 1:
//
//Input: nums = [1,2,3,4]
//Output: 3
//Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
//Example 2:
//
//Input: nums = [1]
//Output: 0

// Constraints:
//
//1 <= nums.length <= 5000
//-1000 <= nums[i] <= 1000

// 问题：给定一个数组，求等差子数组的个数（等差数组，个数>3)

// 分析：dp[i]表示以i**结尾**时的子数组个数。以i=2开始，若A[i-2],A[i-1],A[i]构成等差数列，dp[i] = 1,
// e.g [1,2,3,4], dp[2] = 1, dp[3] = cond(i) + dp[i-1] + 1( if A[i] - A[i-1] == A[i-2] - A[i-3]
// 这里，有两种情况。 1. cond(i)(表示当前三个构成等差数列). 2 前面的数加上当前数字仍构成等差数列，+1
// 初始化dp[:2] = 0
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        if (nums.size() < 3) return 0;
        vector<int> dp(nums.size(), 0);
        dp[2] = nums[2] - nums[1] == nums[1] - nums[0] ? 1 : 0;
        int res = dp[2];
        for (int i = 3; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1;
            res += dp[i];
        }
        return res;
    }
};