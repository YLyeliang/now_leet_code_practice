// created by yel on 2022/4/4

// Given an array, rotate the array to the right by k steps, where k is
// non-negative.
//
// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation:
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
//
// Constraints:
//
// 1 <= nums.length <= 105
//-231 <= nums[i] <= 231 - 1
// 0 <= k <= 105
//
// Follow up:
//
// Try to come up with as many solutions as you can. There are at least three
// different ways to solve this problem. Could you do it in-place with O(1)
// extra space?

// 问题：给定数组，向右移动k步，返回移动后的数组.

// 方法：汇总
// https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C%2B%2B-solutions

// 1.建立一个数组拷贝num_copy, 可以计算出移动后的位置为(i+k)%n, 则nums[(i+k)%n]
// = num_copy[i]   O(n) time O(n) space

// 2. 反转前n-k个数，反转后k个数，反转整个数组.
#include "iostream"
#include "vector"
using namespace std;
class Solution {
  void rotate(vector<int>& v, int k) {
    std::rotate(v.rbegin(), v.rbegin() + k % v.size(), v.rend());
  }
};

class Solution2
{
 public:
  void rotate(int nums[], int n, int k)
  {
    k = k%n;

    // Reverse the first n - k numbers.
    // Index i (0 <= i < n - k) becomes n - k - i.
    reverse(nums, nums + n - k);

    // Reverse tha last k numbers.
    // Index n - k + i (0 <= i < k) becomes n - i.
    reverse(nums + n - k, nums + n);

    // Reverse all the numbers.
    // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
    // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
    reverse(nums, nums + n);
  }
};