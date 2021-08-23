//
// Created by yel on 2021/8/23.
//

/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with;
and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
 Your goal is to maximize the number of your content children and output the maximum number.



Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
You have 3 cookies and their sizes are big enough to gratify all of the children,
You need to output 2.
*/

// 问题：分配饼干。你是一个优秀的家长，要为你的孩子们分配饼干（害，木有孩子）。每个孩子至多一个饼干。每个孩子有一个贪心系数g[i],表示这个孩子至少分到多少尺寸的饼干才会满足，
// 每一个饼干j有一个尺寸s[j]. 如果s[j] >= g[i], 可以直接把饼干j分给第i个孩子，使得该孩子心满意足。目标是最大限度地使孩子们心满意足，并求出最大数量。
// 饼干不可拆分。

// 转换成数学来说，就是给定一个数组g和一个数组s,求使得s的数字能够组成g中数字的最大个数。

// 方法；对s和g进行排序，按照贪心算法，先满足需求小的，尽量用小的饼干。

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i])
                i++;
            j++;
        }
        return i;
    }
};
