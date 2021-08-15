//
// Created by yel on 2021/8/15.
//

// You are given a sorted unique integer array nums.
//
//Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
//
//Each range [a,b] in the list should be output as:
//
//"a->b" if a != b
//"a" if a == b
//
//
//Example 1:
//
//Input: nums = [0,1,2,4,5,7]
//Output: ["0->2","4->5","7"]
//Explanation: The ranges are:
//[0,2] --> "0->2"
//[4,5] --> "4->5"
//[7,7] --> "7"

// 问题：给定数组，返回递增的范围数组，start->end

// 方法：遍历数组，判断子数组是否是递增的，返回尾数构建一个范围。然后使用新的start和end继续遍历。


#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;

        for (int i = 0, n = nums.size(); i < n; i++) {
            int begin = nums[i];
            while (i != (n - 1) && nums[i] == nums[i + 1] - 1)
                i++;
            int end = nums[i];
            if (begin == end)
                res.push_back(to_string(begin));
            else
                res.push_back(to_string(begin) + "->" + to_string(nums[i]));
        }

        return res;
    }
};