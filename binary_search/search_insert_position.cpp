// created by yel on 2024/2/25

// Given a sorted array of distinct integers and a target value, return the
// index if the target is found. If not, return the index where it would be if
// it were inserted in order.
//
// You must write an algorithm with O(log n) runtime complexity.
//
// Example 1:
//
// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:
//
// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:
//
// Input: nums = [1,3,5,6], target = 7
// Output: 4
//
//
// Constraints:
//
// 1 <= nums.length <= 104
//-104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
//-104 <= target <= 104

// 问题：给定有序数组和target,返回该target的索引(if
// found).如果找不到，则返回他应该被有序插入所在位置的索引

// 分析：要求O(log n)，则是二分搜索方法。由于是有序数组，使用BS进行搜索即可
#include "iostream"

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int r = nums.size() - 1;
    int l = 0;
    while (l < r) {
      int mid = l + (r - l) / 2;  // avoid overflow
      if (target == nums[mid]) {
        return mid;
      }
      if (target > nums[mid]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return nums[l] < target ? l + 1 : r;
  }
};