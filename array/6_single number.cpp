//
// Created by yel on 2021/8/9.
//

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
//
//You must implement a solution with a linear runtime complexity and use only constant extra space.
//
//
//
//Example 1:
//
//Input: nums = [2,2,1]
//Output: 1
//Example 2:
//
//Input: nums = [4,1,2,1,2]
//Output: 4
//Example 3:
//
//Input: nums = [1]
//Output: 1

// 问题：非空整数数组，每个元素都出现两次，仅有一个出现一次，找到该数。 要求：O(n) runtime O(1) space

// 方法：使用异或方式，对数组的所有元素进行异或操作，最后的结果为出现一次的数，以 2，1，4，5，4，1，2为例。
// 前4个数的异或为2^1^4^5 = 10 ^01^ 100 ^ 101 = 10 = 2
// 所有数的异或为2^1^4^5^4^1^2,相消之后得到5


#include "vector"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (auto num:nums)
            result ^= num;
        return result;
    }
};

int main() {
    vector<int> nums{2, 1, 4, 5, 4, 1, 2};
    int result = 0;
    for (auto iter = nums.begin(); iter < nums.end() - nums.size() / 2; iter++) {
        result ^= *iter;
    }
    return 0;
}