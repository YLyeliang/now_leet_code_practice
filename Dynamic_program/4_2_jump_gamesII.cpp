//
// Created by 叶亮 on 2021/12/18.
//

// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//You can assume that you can always reach the last index.
//
//Example 1:
//
//Input: nums = [2,3,1,1,4]
//Output: 2
//Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
//Example 2:
//
//Input: nums = [2,3,0,1,4]
//Output: 2

// Constraints:
//
//1 <= nums.length <= 104
//0 <= nums[i] <= 1000

// 问题：与I中判断能否到达最后位置不同，II的先决条件是必能到达最后，求最小跳跃次数

// 方法：可以构建dp[],dp[i]表示到达当前索引的最小步数。可知，dp[i] = dp[i-1]
// 一个BFS问题。思考一下，在当前索引时可以跳跃nums[i]步，则最远可以到达的距离为i+nums[i];
// 定义三个变量，jumps, curEnd, curFarthest.
// jumps为跳跃次数，curEnd为当前能走到的终点，curFarthest为在走到curEnd之中找到的实际能走到的最远地点。
// 遍历数组，在(begin,curEnd)之间更新curFarthest,当走到curEnd时，
// jumps++(因为达到了curEnd，但可能curFarthest更远，这时表明在(begin,curEnd)之间已经换了另一个索引再次跳跃),
// 并更新curEnd = cur Farthest.
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int jumps = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            curFarthest = max(curFarthest, i + nums[i]);
            if (i == curEnd) {
                jumps++;
                curEnd = curFarthest;
            }
        }
        return jumps;

    }
};