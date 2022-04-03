// created by yel on 2022/4/2

// Given an array of integers heights representing the histogram's bar height
// where the width of each bar is 1, return the area of the largest rectangle in the histogram.
//
//Example 1:
//Input: heights = [2,1,5,6,2,3]
//Output: 10
//Explanation: The above is a histogram where width of each bar is 1.
//The largest rectangle is shown in the red area, which has an area = 10 units.
//
// Example 2:
//Input: heights = [2,4]
//Output: 4
//
//Constraints:
//1 <= heights.length <= 105
//0 <= heights[i] <= 104

// 问题：给定直方图数组，求最大矩形。

// 方法： 可以将直方图分成一个个区域，每一个区域由升序柱子表示，分别计算升序柱子的面积大小，取最大值。
// 直方图数组append一个0，表示最小值。然后遍历数组，建立一个索引数组，用来存储遍历过的索引值。
// 如果数组呈现升序时，则一直append到索引数组里.
// 当，索引数组不为空、并且上一个柱子高度>=当前高度时。则对之前的所有升序的柱子进行判断，计算其最大矩形。
// 循环计算： 获取上一个索引中的柱子高度，计算宽度为上一个索引到当前索引的距离，乘以柱子高度.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        heights.push_back(0);
        vector<int> index;
        for (int i =0;i<heights.size();i++){
            while (index.size()>0 && heights[index.back()]>=heights[i]){
                // get the height
                int h = heights[index.back()];
                index.pop_back();

                // calculate the distance
                // if have index, then calculate the dis = cur_index - last_index
                int idx = index.size()>0? index.back(): -1;
                if (h*(i-idx -1)> ret)
                    ret = h*(i-idx-1);
            }

            index.push_back(i);
        }
        return ret;
    }
};
int main() {
    Solution sol;
    vector<int> height = {6, 6, 6, 6, 6};
    sol.largestRectangleArea(height);
}

