// created by yel on 2022/3/13

// Given an array of integers nums sorted in non-decreasing order,
// find the starting and ending position of a given target value.
//
//If target is not found in the array, return [-1, -1].
//
//You must write an algorithm with O(log n) runtime complexity.
//
//Example 1:
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//
// Example 2:
//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
//
// Example 3:
//Input: nums = [], target = 0
//Output: [-1,-1]
//
//Constraints:
//0 <= nums.length <= 105
//-109 <= nums[i] <= 109
//nums is a non-decreasing array.
//-109 <= target <= 109

// 问题：给定一个非降序的数组nums和值target，找到target在数组中的起点和终点索引。
// 方法：
// 数组含有重复数字，要找到其起点和终点。
// 首先想到的是：遍历整个数组，逐一对比，就可以找到起点和终点 O(n)，但不满足题目要求
// 上述方法需要遍历整个数组，没有利用到有序数组的特性，复杂度还有一定优化空间。

// 二分法：如果使用二分法的话。考虑一下情形，当mid<target or mid > target则继续二分。
// 当mid == target时，则需要确定起点和终点。这时向两边进行扩散，找到起点和终点索引即可。
// 扩散的时候需要遍历数组，考虑到极端条件下，其复杂度仍为O(n)

// 二分法-优化：使用两次二分法，分别寻找target的上下界(target和target+1).
// 得到下界l和上界l-1的索引后，判断nums[l] == target,l < nums.size()即可


#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else { // 扩散
                int li = mid, ri = mid;
                while (li >= 0 && nums[li] == target)li--;
                while (ri <= r && nums[ri] == target) ri++;
                return {++li, --ri};
            }
        }
        return {-1, -1};
    }
};

class Solution2 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int li = binary_search(nums, target);
        int ri = binary_search(nums, target + 1) - 1;   // higher bound
        if (li < nums.size() && nums[li] == target)
            return {li, ri};
        else
            return {-1, -1};

    }

    int binary_search(vector<int> &nums, int target) { // search for the lower bound
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};
