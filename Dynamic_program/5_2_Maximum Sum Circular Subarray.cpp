//
// Created by 叶亮 on 2021/12/18.
//

// Given a circular integer array nums of length n,
// return the maximum possible sum of a non-empty subarray of nums.
//
//A circular array means the end of the array connects to the beginning of the array.
// Formally, the next element of nums[i] is nums[(i + 1) % n] and
// the previous element of nums[i] is nums[(i - 1 + n) % n].
//
//A subarray may only include each element of the fixed buffer nums at most once.
// Formally, for a subarray nums[i], nums[i + 1], ..., nums[j],
// there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
//
//Example 1:
//
//Input: nums = [1,-2,3,-2]
//Output: 3
//Explanation: Subarray [3] has maximum sum 3.
//Example 2:
//
//Input: nums = [5,-3,5]
//Output: 10
//Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
//
// Example 3:
//
//Input: nums = [-3,-2,-3]
//Output: -2
//Explanation: Subarray [-2] has maximum sum -2.
//
//
//Constraints:
//
//n == nums.length
//1 <= n <= 3 * 104
//-3 * 104 <= nums[i] <= 3 * 104

// 问题：给定环形数组(首尾相接),求子数组的最大和。

// 分析：环形数组，即nums[i+1] = nums[(i+1)%n], n为数组长度。
// 错误分析：环形可以分解为两个数组，1. 尾部移到头部；2. 头部移到尾部。即两个子问题的最大子数组和. 移动头部和尾部都只能移单个元素，
// 若最大子数组和首尾相接包含多个元素时则不适用。

// https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
// 该问题有两种情况：
// 1. 最大数组和在中间部分，可以参考5_1 max_subarray.
// 2. 最大数组首尾相接，这里可以转换成1.-> 找到最小数组和，total - minSum即为所求；

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0,maxSum=nums[0],curMax=0,minSum=nums[0],curMin=0;
        for (auto a: nums){
            curMax = max(a,curMax+a);
            maxSum = max(curMax,maxSum);
            curMin = min(a,curMin+a);
            minSum = min(curMin,minSum);
            total +=a;
        }
        return maxSum >0? max(maxSum, total- minSum) : maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,4,-5,4,-5,9,4};
    int result = sol.maxSubarraySumCircular(nums);
    cout << result << endl;
}