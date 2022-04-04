// created by yel on 2022/4/3

// Given an array of integers nums and an integer limit,
// return the size of the longest non-empty subarray such that the absolute
// difference between any two elements of this subarray is less than or equal to
// limit.
//
// Example 1:
// Input: nums = [8,2,4,7], limit = 4
// Output: 2
// Explanation: All subarrays are:
//[8] with maximum absolute diff |8-8| = 0 <= 4.
//[8,2] with maximum absolute diff |8-2| = 6 > 4.
//[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
//[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
//[2] with maximum absolute diff |2-2| = 0 <= 4.
//[2,4] with maximum absolute diff |2-4| = 2 <= 4.
//[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
//[4] with maximum absolute diff |4-4| = 0 <= 4.
//[4,7] with maximum absolute diff |4-7| = 3 <= 4.
//[7] with maximum absolute diff |7-7| = 0 <= 4.
// Therefore, the size of the longest subarray is 2.
// Example 2:
//
// Input: nums = [10,1,2,4,7,2], limit = 5
// Output: 4
// Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute
// diff is |2-7| = 5 <= 5. Example 3:
//
// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
// Output: 3
//
//
// Constraints:
//
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 0 <= limit <= 109

// 问题：给定数组nums,求最长子数组的长度，其中子数组中的任意两个数的差的绝对值<=limit

// 方法：使用两个双边队列，分别表示最大值和最小值.使用双指针分别表示数组的头尾
// 最大队列的更新方式：遍历数组，将队列中小于当前元素的尾部出列，然后将当前值添加到队列，则可以得到递减的最大队列
// 最小队列的更新同上，规则相反.拿到最大队列和最小队列之后，遍历数组，如果max-min
// >limit，则移动左指针.同时，在移动前，需要判断左指针处的元素是否为最大最小，如果是则从队列中删除

#include "deque"
#include "iostream"
#include "vector"
using namespace std;

  class Solution {
   public:
    int longestSubarray(vector<int>& nums, int limit) {
      deque<int> maxd, mind;
      int l = 0;
      int res = 1;
      // loop
      for (int r = 0; r < nums.size(); ++r) {
        // update maxd & mind
        while (!maxd.empty() && maxd.back() < nums[r]) maxd.pop_back();
        while (!mind.empty() && mind.back() > nums[r]) mind.pop_back();
        maxd.push_back(nums[r]);
        mind.push_back(nums[r]);

        // shrink left pointer
        while (maxd.front() - mind.front() > limit) {
          if (nums[l] == maxd.front()) maxd.pop_front();
          if (nums[l] == mind.front()) mind.pop_front();
          ++l;
        }
        res = max(res, r - l + 1);
      }
      return res;
    }
  };