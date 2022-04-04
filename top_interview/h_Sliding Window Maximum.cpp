// created by yel on 2022/4/4

// You are given an array of integers nums, there is a sliding window of size k
// which is moving from the very left of the array to the very right. You can
// only see the k numbers in the window. Each time the sliding window moves
// right by one position.
//
// Return the max sliding window.
//
// Example 1:
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
//
// Example 2:
// Input: nums = [1], k = 1
// Output: [1]
//
// Constraints:
//
// 1 <= nums.length <= 105
//-104 <= nums[i] <= 104
// 1 <= k <= nums.length

// 问题：给定一个数组nums,和一个尺寸为k的滑动窗口。移动滑窗，返回每一次移动时的滑窗最大值

// 方法：构建一个最大双边队列maxd.
// maxd为递减顺序，初始化：遍历初始化窗口，判断nums[r] > maxd.back(),
// 如果大于则队尾出列，将新的值入列，保证maxd为一个递减的队列.
// 移动窗口：首先判断nums[l] ==
// maxd.front()，如果等于则队首出列，再移动时l++,r++，再回到上一步判断新增数值添加到队列中
#include "deque"
#include "iostream"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> maxd;
    vector<int> res;
    int l = 1, r;
    // initialize
    for (int i = 0; i < k; i++) {
      while (!maxd.empty() && nums[i] > maxd.back()) maxd.pop_back();
      maxd.push_back(nums[i]);
    }
    res.push_back(maxd.front());
    if (nums[0] == maxd.front()) maxd.pop_front();
    for (r = k; r < nums.size(); ++r, l++) {
      while (!maxd.empty() && nums[r] > maxd.back()) maxd.pop_back();
      maxd.push_back(nums[r]);
      res.push_back(maxd.front());
      if (nums[l] == maxd.front()) maxd.pop_front();
    }
    return res;
  }
};