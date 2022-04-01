// created by yel on 2022/3/30

// Given an array of intervals where intervals[i] = [starti, endi],
// merge all overlapping intervals, and return an array of the non-overlapping intervals
// that cover all the intervals in the input.
//
//Example 1:
//Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
// Example 2:
//Input: intervals = [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
//Constraints:
//1 <= intervals.length <= 104
//intervals[i].length == 2
//0 <= starti <= endi <= 104

// 问题：给定一个数组，每个元素为区间intervals, intervals[i] = [start_i, end_i]. 合并所有重叠区间，并返回。

// 方法：
// 1. 首先对数组进行升序排序，并建立res,将第一个结果push进去.
// 2. 遍历数组，判断当前区间start是否大于res最后区间的end. >则push到res,否则进行合并

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[0] <= b[0]; });
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > res.back()[1]) res.push_back(intervals[i]);
            else
                res.back()[1] = max(intervals[i][1], res.back()[1]);
        }
        return res;
    }
};