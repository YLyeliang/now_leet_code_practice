//
// Created by yel on 2021/8/16.
//

// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
//
//
//
//Example 1:
//
//Input: nums = [4,3,2,7,8,2,3,1]
//Output: [5,6]
//Example 2:
//
//Input: nums = [1,1]
//Output: [2]
//
//
//Constraints:
//
//n == nums.length
//1 <= n <= 105
//1 <= nums[i] <= n
//
//
//Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

//　问题：有n个元素的数组，nums[i]在区间[1,n]内，返回所有在区间内但是不在nums内的数。 Note:O(n) time in-place.

// 方法：卡吕到所有元素均在区间[1,n]内，且数组长度为n。遍历数组，对于每个元素，找到其element-1的索引（区间内第element个数），并将其置为索引的负数，表示该数出现过。
// 第二次遍历找到所有非负数，其下标+1表示丢失的数。

#include "vector"

using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};

int main() {
    vector<int> ans{4, 3, 2, 7, 8, 2, 3, 1};
    Solution sol;
    sol.findDisappearedNumbers(ans);
}