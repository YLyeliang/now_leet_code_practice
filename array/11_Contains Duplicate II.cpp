//
// Created by yel on 2021/8/11.
//

//Given an integer array nums and an integer k,
// return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
//
//
//
//Example 1:
//
//Input: nums = [1,2,3,1], k = 3
//Output: true
//Example 2:
//
//Input: nums = [1,0,1,1], k = 1
//Output: true
//Example 3:
//
//Input: nums = [1,2,3,1,2,3], k = 2
//Output: false

// 问题：给定数组和整数k,如果存在两个相同的数，其索引的距离<=k，则返回true

// 方法：
// 1.构建哈希表:效率较低
// 2.滑动窗口：构建一个集合，并使用长度为k的滑动窗口，将窗口内的数全部添加进集合中，如果添加成功，则说明窗口内不存在相等的数；如果出现添加失败，则说明
// 两个数相同，且再距离内；每次前进时，删除左边的元素（窗口外的元素），再将右边的元素添加到集合中，

// 3.滑动窗口 with map
#include "vector"
#include "unordered_set"
#include "map"
#include "unordered_map"

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            if (dict.find(nums[i]) != dict.end() && abs(dict[nums[i]] - i) <= k)
                return true;
            dict[nums[i]] = i;
        }
        return false;

    }
};

class Solution2 {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> tmp;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) tmp.erase(nums[i - k - 1]);
            if (!tmp.insert(nums[i]).second) return true;
        }
        return false;

    }
};

class Solution3 {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {

        unordered_map<int, int> nmap;
        for (int i = 0; i < nums.size(); i++) {
            if (nmap.count(nums[i]) == 0)
                nmap[nums[i]] = i;
            else if (i - nmap[nums[i]] <= k)
                return true;
            else
                nmap[nums[i]] = i;
        }

        return false;

    }
};