// created by yel on 2022/1/19

// General summary of what kind of problem can/ cannot solved by Two Pointers
// 哪类问题可以使用双指针的总结
// https://leetcode.com/problems/subarray-sum-equals-k/discuss/301242/General-summary-of-what-kind-of-problem-can-cannot-solved-by-Two-Pointers

// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
//
//
//
//Example 1:
//
//Input: nums = [1,1,1], k = 2
//Output: 2
//Example 2:
//
//Input: nums = [1,2,3], k = 3
//Output: 2
//
//
//Constraints:
//
//1 <= nums.length <= 2 * 104
//-1000 <= nums[i] <= 1000
//-107 <= k <= 107

// 问题：找到和为k的连续子数组的个数

// 方法：前缀和+哈希表
// 遍历数组，计算到当前位置的和。然后使用一个哈希表来存储前缀和的出现次数。
// dict[sums]++. 这里的意义是，前缀和出现的次数，
// 则count += dict[sums - k] if sums - k in dict.
//


#include "iostream"
#include "map"

using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0,sums = 0;
        std::map<int,int> pre_sum;
        pre_sum[0]++;
        for (int i=0; i<=nums.size();i++){
            sums+=nums[i];
            count +=pre_sum[sums-k];
            pre_sum[sums]++;
        }
        return count;

    }
};



