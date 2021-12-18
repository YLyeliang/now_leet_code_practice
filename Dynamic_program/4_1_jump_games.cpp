//
// Created by 叶亮 on 2021/12/17.
//

#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

// You are given an integer array nums. You are initially positioned at the array's first index,
// and each element in the array represents your maximum jump length at that position.
//
//Return true if you can reach the last index, or false otherwise.
//
//
//
//Example 1:
//
//Input: nums = [2,3,1,1,4]
//Output: true
//Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
//Example 2:
//
//Input: nums = [3,2,1,0,4]
//Output: false
//Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0,
// which makes it impossible to reach the last index.

// 问题： 一个数组，每个元素表示最大跳跃距离(不超过即可)。从起始点开始，能达到最后则返回true.

// 方法：只要当前位置的可用距离点数>离最后位置的距离便能达到目的地。
// 那么，可以使用dp[i]表示当前i的最大可用距离。
// 例1:dp[0]=2, dp[1] = max(dp[0]-1, nums[1]) = 3, dp[2] = max(dp[1]-1, nums[2]) = 2, dp[3] = 1, dp[4] = 4
// 只要dp[-2]>0即可。
// formula: dp[i] = max(dp[i-1]-1,nums[i])
// dp[0] = nums[0]


class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        if (n==1) return true;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (dp[i-1] ==0) return false;
            dp[i] = max(dp[i - 1] - 1, nums[i]);
        }
        return dp[n - 2];
    }
};