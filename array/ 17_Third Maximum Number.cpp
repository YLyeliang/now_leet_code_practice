//
// Created by yel on 2021/8/16.
//

// Given integer array nums, return the third maximum number in this array. If the third maximum does not exist, return the maximum number.
//
//
//
//Example 1:
//
//Input: nums = [3,2,1]
//Output: 1
//Explanation: The third maximum is 1.
//Example 2:
//
//Input: nums = [1,2]
//Output: 2
//Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
//Example 3:
//
//Input: nums = [2,2,3,1]
//Output: 1
//Explanation: Note that the third maximum here means the third maximum distinct number.
//Both numbers with value 2 are both considered as second maximum.

// 问题：给定数组，返回数组中第三大的数，如果不存在，则返回最大数。 Note:能够找到O(n)解。

// 方法：1.粗暴方法：对其排序，然后找第三个大的数。
// 2. 使用集合，

#include "vector"
#include "set"

using namespace std;


class Solution {
public:
    int thirdMax(vector<int> &nums) {
        set<int> top3;
        for (int num : nums)
            if (top3.insert(num).second && top3.size() > 3)
                top3.erase(top3.begin());
        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
    }
};


int main() {
    vector<int> nums{3, 3, 2, 2};
    Solution sol;
    auto res = sol.thirdMax(nums);
    return 0;
}