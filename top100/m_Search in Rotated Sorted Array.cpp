// created by yel on 2022/3/13
// 二分搜索

// There is an integer array nums sorted in ascending order (with distinct values).
//
//Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
// such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
//
//Given the array nums after the possible rotation and an integer target, return the index of target
// if it is in nums, or -1 if it is not in nums.
//
//You must write an algorithm with O(log n) runtime complexity.
//
//Example 1:
//Input: nums = [4,5,6,7,0,1,2], target = 0
//Output: 4
//
// Example 2:
//Input: nums = [4,5,6,7,0,1,2], target = 3
//Output: -1
//
// Example 3:
//Input: nums = [1], target = 0
//Output: -1
//
//Constraints:
//1 <= nums.length <= 5000
//-104 <= nums[i] <= 104
//All values of nums are unique.
//nums is an ascending array that is possibly rotated.
//-104 <= target <= 104

// 问题:存在一个升序的数组，在调用函数之前，数组在索引k处进行了旋转。
// 给定旋转后的数组nums,和target，返回target的索引，不存在则为-1.要求O(logN)

// 方法：
// 给定的是旋转之后的数组和一个整数target，求的是这个target在数组中的索引。
// 通常来说，遍历整个数组则可以知道该target的位置。但这样为O(N)不符合题意
// 可以采用二分法，如果中值>右侧，则说明左侧为旋转前的右侧，右侧为旋转前的左侧(较小的数)
// 首先找到最小数的的索引(旋转的位置)rot.然后再次二分搜索，计算mid时，realmid = (mid+rot)%n为实际的二分搜索的中值。
// 比较nums[realmid]和target的大小来继续二分搜索
//

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (hi + lo) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else
                hi = mid;
        }
        int rot = lo;
        lo = 0;
        hi = n - 1;
        while (lo <= hi) {
            int mid = (hi + lo) / 2;
            int realmid = (mid + rot) % n;
            if (nums[realmid] == target) return realmid;
            if (nums[realmid] < target) lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;

    }
};