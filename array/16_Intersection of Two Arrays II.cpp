//
// Created by yel on 2021/8/16.
//


// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
//
//
//
//Example 1:
//
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2,2]
//Example 2:
//
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [4,9]
//Explanation: [9,4] is also accepted.
//
//
//Constraints:
//
//1 <= nums1.length, nums2.length <= 1000
//0 <= nums1[i], nums2[i] <= 1000
//
//
//Follow up:
//
//What if the given array is already sorted? How would you optimize your algorithm?
//What if nums1's size is small compared to nums2's size? Which algorithm is better?
//What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

// 问题：给定两个数组，求交集。II：在返回的结果中，每个元素的个数应该与两个数组中相交的部分相同。

// 方法：在I中，结果中交集元素只需出现一次即可。这里则需要出现所有相交的部分。因此，不能使用集合来实现。
// 以nums1为基准，遍历nums2,对每个元素num,对nums1进行删除，如果能够删除（nums1与nums2中的该元素是相交的），则在结果中进行添加。
// 复杂度为O(NM) N for length of nums1, and M for nums2.
// 2.使用哈希表，存储nums1的元素num:count.然后遍历nums2，发现相同元素时，对哈希表对应元素计数-1.

// 后续：
// 1. 如果数组已经排序好的话，在遍历的过程中，当找到相同的数时，可以两个指针同时前进，直到不相等；则继续寻找下一个两个相同的元素。
// 2. 如果nums1比nums2尺寸小的话。
// 3. 如果nums2在硬盘上排序好了。并且内存有限（不能一次读取所有元素）。1)将nums1 or nums2读到哈希表中，然后按块读取另一个数组，计算交集
// 2)两个都不能完全读到内存中，则分别对其进行排序。然后每次读取两个元素到内存中进行比较。

// leetcode:
// Store the two strings in distributed system(whether self designed or not), then using MapReduce technique to solve the problem;
//
// Processing the Strings by chunk, which fits the memory, then deal with each chunk of data at a time;
//
// Processing the Strings by streaming, then check.

#include "vector"

using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        for (auto num:nums2) {
            vector<int>::iterator iter = nums1.begin();
            while (iter != nums1.end() and *iter != num)
                iter++;
            if (iter != nums1.end()) {
                res.push_back(*iter);
                nums1.erase(iter);
            }
        }
        return res;
    }
};