//
// Created by yel on 2021/8/23.
//

// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
// Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
//
//Notice that you may not slant the container.
//
//
//
//Example 1:
//
//
//Input: height = [1,8,6,2,5,4,8,3,7]
//Output: 49
//Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
// In this case, the max area of water (blue section) the container can contain is 49.
//Example 2:
//
//Input: height = [1,1]
//Output: 1
//Example 3:
//
//Input: height = [4,3,2,1,4]
//Output: 16
//Example 4:
//
//Input: height = [1,2,1]
//Output: 2

// 问题：给定一个整数数组h，每个数字表示一个高为h[i]的柱子，该柱子的横坐标为i,找到两个柱子，使得其构成平面蓄水池，使得里面的水不会溢出来，求最大的蓄水空间.

// 方法：该问题即求直角坐标系中多个坐标为(i,h[i])的线段能够构成的最大矩形面积。
// 面积 = 宽 x 高，要找到一个合适的宽和高来计算面积。假设一开始使用两端的线段来构建举行。其宽为len(h)-1.高为min(h[0],h[-1])
// 可以得到面积S = (len(h)-1) * min(h[0],h[-1])。然后，使用双指针，向中间收缩，抛弃掉短边，向中间移动，计算新的柱子构建的面积和当前的面积，保留最大值。
// 依次迭代，直到两根柱子相遇。

#include "vector"

using namespace std;


class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1, S = 0;
        while (i < j) {
            S = max(S, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return S;
    }
};