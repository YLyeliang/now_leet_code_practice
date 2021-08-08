//
// Created by yel on 2021/8/8.
//

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
// representing the number of elements in nums1 and nums2 respectively.
//
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
//
// The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
// To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
// and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

// 问题：有两个升序整型数组num1和num2,和两个整数m和n,分别表示数组的元素数量。
// 将两个数组进行合并保持有序。注意：结果需保存再num1中。

// 方法：考虑到num1的长度为m+n，则可以使用双指针的方法，分别指向两个数组的有实际数字的末端。通过比较大小，按照逆序的方式对num1进行值的修改。
// [1,2,3] [2,5,6] ->   [1,2,3,0,0,6];
// [1,2,3] [2,5] -> [1,2,3,0,5,6];
// [1,2,3] [2] -> [1,2,3,3,5,6];
// [1,2,] [2] -> [1,2,2,3,5,6];

#include "vector"

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        int l = m + n;
        for (int i = l - 1; i >= 0 && !nums2.empty(); --i) {
            if (m >0 && nums1[m - 1] > nums2.back()) {
                nums1[i] = nums1[m - 1];
                m--;
            } else {
                nums1[i] = nums2.back();
                nums2.pop_back();
            }
        }
    }
};