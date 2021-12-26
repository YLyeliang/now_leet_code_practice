//
// Created by 叶亮 on 2021/12/19.
//

// You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
//
//The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
//
//Return the maximum score of a pair of sightseeing spots.
//
//
//
//Example 1:
//
//Input: values = [8,1,5,2,6]
//Output: 11
//Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
//Example 2:
//
//Input: values = [1,2]
//Output: 2

// 问题：给定观光点的分数数组，求数组中一对观光点的最大分数；其值 = 分数之和 - 观光点距离

// 方法：
// 记录当前的最佳分数，每前进一步，最佳分数-1；
// 每次计算当前点与最佳分数之和。
// cur为当前的最佳分数,每次更新res =  max(res, cur + val)
// cur则每次更新为 cur = max(cur,val) - 1.(下一次迭代需要-1)
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &values) {
        int res = 0, cur = 0;
        for (auto val: values) {
            res = max(res, cur + val);
            cur = max(cur, val) - 1;
        }
        return res;

    }
};