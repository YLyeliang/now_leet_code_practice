//
// Created by 叶亮 on 2021/12/26.
//

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
//
//
//
//Example 1:
//
//
//Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6
//Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
//Example 2:
//
//Input: height = [4,2,0,3,2,5]
//Output: 9
//
//
//Constraints:
//
//n == height.length
//1 <= n <= 2 * 104
//0 <= height[i] <= 105
//Accepted
//968,718
//Submissions
//1,763,827

// 问题：给定一个height数组，表示高度图的长度；求装满水后的储水体积。

// 分析：以例2为例，
//      |
// |    |
// |  | |
// || |||
// || |||

// 这里建立一个dp[]数组，dp[i]表示以索引i结尾时的最大储水体积；
// dp[0] = 0, h[0] = 4
// dp[1] = 0, h[1] = 2
// dp[2] = 0, h[2] = 0
// dp[3] = 4, h[3] = 3 因为height为4的和3的构成一个可蓄水区域，减去其中所占高度, 3 * 2 - 2 = 4
// dp[4] = 4, h[4] = 2 h[4] < h[3]
// dp[5] = 9, h[5] = 5 h[5]> h[4] 形成了一个更高的区域,
// dp[5] = min(h[5],h[0]) * (5-1) - sum(h[1:5]) + dp[0] =  4 * 4 - 2 -3 -2 = 9

// 考虑另外一种情况，

// | | |
// | | |
// dp[0]=0, dp[1]=1, dp[2] =2 ,dp[3] =2, dp[4] = 4
// dp[4] = min(h[4],h[2])* (4 - 2 -1) + dp[2]

// 则，可以知道。遍历过程中，迭代更新dp的大小，同时保存max(h)信息，height[i]>= max(h)时，
// 则dp[i] = min(max(h), height[i]) * (i - index(max(h) -1 ) - sum(h[index(max(h))+1:i]) + dp[index(max(h))]

// | |
// | | |
#include "vector"
#include "algorithm"
#include "numeric"
#include "iostream"

using namespace std;


// 通过率: 234/320
class Solution {
public:
    int trap(vector<int> &height) {
        int res = 0;
        if (height.size() <= 2) return 0;
        vector<int> dp(height.size(), 0);
        int index = height[0] > height[1] ? 0 : 1;
        int max_h = max(height[0], height[1]);
        for (int i = 2; i < height.size(); i++) {
            int area = min(max_h, height[i]) * (i - index - 1);
            int sums = accumulate(height.begin() + index + 1, height.begin() + i, 0);
            dp[i] = max(area - sums, 0) + dp[index];
            if (height[i] >= max_h) {
                max_h = height[i];
                index = i;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


//https://leetcode.com/problems/trapping-rain-water/discuss/17357/Sharing-my-simple-c%2B%2B-code%3A-O(n)-time-O(1)-space
// 双指针的方式，左边和右边分别使用两个指针，以及maxleft和maxright分别存储左右两边的最大高度；
// 向中间收缩，矮侧指针先移动，遇到坑位，则结果补上。
class Solution {
public:
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};

int main() {
    vector<int> test = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sol;
    int res = sol.trap(test);
    cout << res << endl;
}