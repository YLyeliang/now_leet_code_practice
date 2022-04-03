// created by yel on 2022/4/3
// Given an unsorted array of integers nums, return the length of the longest
// consecutive elements sequence. You must write an algorithm that runs in O(n)
// time.
//
// Example 1:
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.
//
// Example 2:
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
//
// Constraints:
// 0 <= nums.length <= 105
//-109 <= nums[i] <= 109

// 问题：给定未排序的整型数组，返回最长连续元素序列的长度

// 方法：构建一个哈希表，key为数组中的元素，val为该元素组成的最长连续元素序列的长度
// 遍历整个数组，判断当前字符是否在哈希表中，已存在则跳过；否则添加到表中，长度为1，然后寻找-1,+1的数值的最大长度
// 总长 = left + right +1，并更新连续元素序列中的边界部分的长度信息, 即num-left,
// num-right = sum

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int res = 0;
    unordered_map<int, int> map;
    for (const int n : nums) {
      if (map.find(n) == map.end()) {
        int left = (map.find(n - 1) == map.end()) ? 0 : map[n - 1];
        int right = (map.find(n + 1) == map.end()) ? 0 : map[n + 1];
        int sum = left + right + 1;
        map[n] = sum;
        map[n - left] = sum;
        map[n + right] = sum;
        res = max(res, sum);
      } else
        continue;
    }
    return res;
  }
};

int main() {
  vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  Solution sol;
  sol.longestConsecutive(nums);
}