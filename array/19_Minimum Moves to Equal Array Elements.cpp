//
// Created by yel on 2021/8/16.
//

// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
//
//In one move, you can increment n - 1 elements of the array by 1.
//
//
//
//Example 1:
//
//Input: nums = [1,2,3]
//Output: 3
//Explanation: Only three moves are needed (remember each move increments two elements):
//[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
//Example 2:
//
//Input: nums = [1,1,1]
//Output: 0
//
//
//Constraints:
//
//n == nums.length
//1 <= nums.length <= 105
//-109 <= nums[i] <= 109
//The answer is guaranteed to fit in a 32-bit integer.

// 问题：给定长为n的数组，求使得所有元素相等所需要的步数。 每一步，可以为n-1个元素+1

// 方法：是一类数学问题；假设元素之和sum, 长度n,最小数min.
// 假设m步之后相等，则元素之和为 sum + (n-1)*m = x * n   (x为m步的值)
// x = min+m
// -> m = x - min -> nm = xn -min*n -> m = sum - min*n

#include "vector"

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return 0;
        int mn = nums[0];
        long sum = nums[0];
        for(int i = 1; i < n; ++i)
        {
            mn = min(mn,nums[i]);
            sum += nums[i];
        }
        return sum -long(mn)*long(n);
    }
};