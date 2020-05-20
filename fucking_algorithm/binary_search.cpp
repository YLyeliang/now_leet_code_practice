#include<vector>
using namespace std;

// 主要讲述几个常用的二分查找场景：寻找一个数、寻找左侧边界、寻找右侧边界。
//
// 一、二分查找框架
int binarySearch(int[] nums,int target) {
    int left=0,right=...;
    while (...) {
        int mid = left+(right-left)/2;
        if (nums[mid]==target){
            ...
        } else if ( nums[mid]<target) {
            left = ...
        } else if (nums[mid]>target) {
            right = ...
        }
    }
    return ...;
}

//在使用bs时，需要将else if的情况考虑清楚，保证逻辑严谨。
//其中， mid=left+(right-left)/2 与 (left+right)/2效果相同，但是前者能够有效防止两者相加时数字太大导致的溢出问题。
//
//二、寻找一个数
//最常见，也是最简单的一种情况，存在则返回其索引，else -1.
int binarySearch(int[] nums, int target) {
    int left=0;
    int right=nums.length-1; //注意数组索引

    while (left<=right) {
        mid=left+(right-left)/2;
        if(nums[mid]== target) 
            return mid;
        else if (nums[mid]<target)
            left = mid+1;
        else if (nums[mid]>target)
            riht= mid-1;
    }
    return -1;
}

// 为什么使用left<=right,而不是left<right。因为right初始化为最后一个元素的索引，使用left<=right，表明搜索区间为
// [left,right]，而不是[left,right)。
// 例子，当一个数组[1,2]时，搜索时，left=0,right=1, target=2,第一次没停止，left+1; left<=right，找到target。
// 如果使用<,函数返回-1,是错误的。
// 如果非要使用<，可以在返回时进行判断
   while(left < right) {
         // ..
        }
    return nums[left] == target ? left : -1;

// 局限性：对于不重复的有序数组来说，算法具有高效性，但是对于具有重复数字的数组，比如[2,3,3,3,4],target为3.
// 此时返回索引2，如果想找到数组的左边界or有边界，则该方法无法处理。因此需要额外的处理。
//
// 三、寻找左侧边界的bs
int left_bound(int[] nums, int target) {
    if (nums.length==0) return -1;
    int left=0;
    int right=nums.length; //注意

    while (left<right) { // 注意
        mid=left+(right-left)/2;
        if (nums[mid]==target)
            right=mid;
        else if (nums[mid]<target)
            left=mid+1;
        else if (nums[mid]>target)
            right=mid;
    }
    return left;
}

// 为什么使用< rather than <=.
// 因为right=nums.length,搜索区间为[left,right), while (left<right)的终止条件为left==right,
// 此时的搜索区间为[left,left)，即为左边界
// 使用<=的话需要进行一定的修改
int left_bound(int[] nums, int target) {
    if (nums.length==0) return -1;
    int left=0,right=nums.length-1;

    while (left<=right) {
        mid=left+(right-left)/2;
        if (nums[mid]<target)
            left=mid+1; //[mid+1,right]
        else if (nums[mid]>target)
            right=mid-1;//[left,mid-1]
        else if (nums[mid]==target)
            right=mid-1; //收缩右侧边界
    }
    //检查出界情况
    if (left>=nums.length||nums[left]!=target)
        return -1;
    return left;
}

//三、寻找右侧边界的二分查找
//先写左闭右开的方法
int right_bound(int[] nums, int target) {
    if (nums.length==0) return -1;
    int left=0,right=nums.length;

    while (left<right) {
        mid = left+(right-left)/2;
        if (nums[mid]==target)
            left=mid+1; //
        else if (nums[mid]<target)
            left=mid+1;
        else if (nums[mid]>target)
            right=mid;
    }
    return left-1; // 
}
// 算法终止条件为left==right,返回right-1也可。

