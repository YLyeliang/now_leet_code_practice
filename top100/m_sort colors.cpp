// created by yel on 2022/4/3

// Given an array nums with n objects colored red, white, or blue,
// sort them in-place so that objects of the same color are adjacent,
// with the colors in the order red, white, and blue.
//
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//
//You must solve this problem without using the library's sort function.
//
//Example 1:
//Input: nums = [2,0,2,1,1,0]
//Output: [0,0,1,1,2,2]
//
// Example 2:
//Input: nums = [2,0,1]
//Output: [0,1,2]
//
// Constraints:
//n == nums.length
//1 <= n <= 300
//nums[i] is either 0, 1, or 2.

// 问题：给定n个元素的数组，其中分别有R、W、B三种颜色。对他们进行排序，排序为RWB，相同颜色为相邻分布
// 分别用012表示这些颜色. 要求in-place

// 方法：
// 1. 直接进行排序. 不符合题意. O(nlogn)

// 2. 三指针方式；分别构建r,w,b指针. 当w<b时，如果nums[w] == 0,则交换w和r的值，并同时向后移动一位，
//作用是将后面的0与前面的1进行交换； 如果nums[w] ==1,则white已经在正确的位置，移动white指针.
// 如果nums[w] ==2,则交换w和b的位置，同时b往前移一位.

#include "iostream"
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int r = 0, w = 0, b = nums.size() - 1;

        while (w <= b)
            if (nums[w] == 0) {
                int tmp = nums[w];
                nums[w] = nums[r];
                nums[r] = tmp;
                w++, r++;
            } else if (nums[w] == 1) {
                w++;
            } else {
                int tmp = nums[w];
                nums[w] = nums[b];
                nums[b] = tmp;
                b--;
            }
    }
};