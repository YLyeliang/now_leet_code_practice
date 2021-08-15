//
// Created by yel on 2021/8/15.
//

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//Note that you must do this in-place without making a copy of the array.
//
//
//
//Example 1:
//
//Input: nums = [0,1,0,3,12]
//Output: [1,3,12,0,0]
//Example 2:
//
//Input: nums = [0]
//Output: [0]

// 问题：给定整数数组nums, 将所有的0移到最后且保持非0数的顺序不变。     Note:必须是in-place(在已有数组上进行操作)

// 方法：
// 1.对于每一个0，往后遍历找到第一个非0的数与其进行交换，如此迭代即可。 最坏情况下：O(N^2)
// 2.遍历数组，建立一个索引，表示非0数的终点，将每一个遇到的非0数，有序从头放置，并且索引+1，对于索引后的数，全部置0. 最坏情况下:

#include "vector"

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int> &nums) {

        for (int i = 0; i < nums.size(); i++) {
            if (i != nums.size() - 1 && nums[i] == 0) {
                int end = i + 1;
                while (end != nums.size() && nums[end] == 0) end++;
                nums[i] = nums[end];
                nums[end] = 0;
            }
        }
    }
};

class Solution2 {
public:
    void moveZeroes(vector<int> &nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                nums[j++] = nums[i];
        }

        for (; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};


int main() {
    vector<int> nums{0, 1, 0, 3, 12};
    Solution sol;
    sol.moveZeroes(nums);
}