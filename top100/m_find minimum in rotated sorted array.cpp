// created by yel on 2022/4/19

// Suppose an array of length n sorted in ascending order is rotated between 1
// and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
//
//[4,5,6,7,0,1,2] if it was rotated 4 times.
//[0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results
// in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
//
// Given the sorted rotated array nums of unique elements, return the minimum
// element of this array.
//
// You must write an algorithm that runs in O(log n) time.
//
// Example 1:
// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
//
// Example 2:
// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4
// times.
//
// Example 3:
// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
//
// Constraints:
// n == nums.length
// 1 <= n <= 5000
//-5000 <= nums[i] <= 5000
// All the integers of nums are unique.
// nums is sorted and rotated between 1 and n times.

// 问题：求旋转后的有序数组里的最小值。
// 给定一个数组，该数组为升序数组旋转n次后的结果。求最小值。
// 旋转1次为整体右移一位，尾部移到头部。
// 要求 时间O(logN)

// 方法：logN可以想到二分法.
// 使用二分法找到最小值min的索引：如果mid >
// right，则旋转前mid在右侧，right在左侧。 此时，left = mid+1 如果 mid <right,
// right = mid -1
//

#include "iostream"
#include "vector"

using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] > nums[r])
        l = mid + 1;
      else
        r = mid;
    }
    return nums[l];
  }
};