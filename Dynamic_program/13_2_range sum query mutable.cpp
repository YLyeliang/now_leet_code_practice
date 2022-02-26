// created by yel on 2022/2/6

// Given an integer array nums, handle multiple queries of the following types:
//
//Update the value of an element in nums.
//Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
//Implement the NumArray class:
//
//NumArray(int[] nums) Initializes the object with the integer array nums.
//void update(int index, int val) Updates the value of nums[index] to be val.
//int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
//
//Example 1:
//
//Input
//["NumArray", "sumRange", "update", "sumRange"]
//[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
//Output
//[null, 9, null, 8]
//
//Explanation
//NumArray numArray = new NumArray([1, 3, 5]);
//numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
//numArray.update(1, 2);   // nums = [1, 2, 5]
//numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
//
//Constraints:
//
//1 <= nums.length <= 3 * 104
//-100 <= nums[i] <= 100
//0 <= index < nums.length
//-100 <= val <= 100
//0 <= left <= right < nums.length
//At most 3 * 104 calls will be made to update and sumRange.

// 问题：给定数组，实现一个数组类型的数据结构，并完成以下功能：
// 1. 初始化
// 2. 更新元素
// 3. 求sumRange

// 方法：
// 超时!!!!：
// 1. 使用标准的构造函数方法。对于sumRange函数，使用prefix来存储前缀和，然后使用prefix[right] - prefix[left-1]得到
// 当使用update更新时，prefix数组需要进行相应的修改(遍历index之后的数组进行差值相加)
// 该方法在进行n次调用update-rangeSum时，其time为 NO(N)

// 2. segment tree方法: 线段树方法
// 什么是线段树：以数组为例，根节点存储一个全局的数字区间，左子树存储区间的左半部分，右子树存储区间的右半部分，
// 直到叶节点。 每个节点存储的结构为：1. 区间左端点、右端点；2. 区间内要维护的信息(可以是区间的和)
// 线段树的update时间为 O(logN)

#include "iostream"
#include "vector"

using namespace std;

// 1. normal method.
class NumArray {
    vector<int> _nums;
    vector<int> pre = vector<int>(1, 0);
public:

    NumArray(vector<int> &nums) {
        _nums = nums;
        for (int i = 0; i < nums.size(); i++)
            pre.push_back(nums[i] + pre[i]);
    }

    void update(int index, int val) {
        int diff = val - _nums[index];
        _nums[index] = val;
        for (int i = index + 1; i < pre.size(); i++)
            pre[i] += diff;
    }

    int sumRange(int left, int right) {
        return pre[right + 1] - pre[left];
    }
};


// 2. segment tree
class Node {
public:
    int start, end, total;
    Node *left;
    Node *right;

    Node(int s, int e) : start(s), end(e), total(0), left(NULL), right(NULL) {}


};

class NumArray2 {
    Node *root;
public:
    Node *createTree(vector<int> &nums, int l, int r) {
        // 1. base case
        if (l > r)
            return nullptr;
        Node *root = new Node(l, r);
        // 2. leaf node
        if (l == r) {
            root->total = nums[l];
            return root;
        }
        int mid = l + (r - l) / 2;
        // 3. recursively create segment tree
        // left child
        root->left = createTree(nums, l, mid);
        root->right = createTree(nums, mid + 1, r);
        root->total = root->left->total + root->right->total;
        return root;
    }

    // update the segment tree
    int updateTree(Node *root, int i, int val) {
        if (root == nullptr) return 0;
        int diff;
        // 1. query the given index
        if (root->start == i && root->end == i) {
            diff = val - root->total;
            root->total = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if (i > mid) // loop right node
            diff = updateTree(root->right, i, val);
        else
            diff = updateTree(root->left, i, val);
        root->total += diff;
        return diff;
    }

    int queryTree(Node *root, int i, int j) {
        // null case
        if (root == nullptr) return 0;
        // equal case
        if (root->start == i && root->end == j) return root->total;
        int mid = (root->start + root->end) / 2;
        // in the right section
        if (i > mid) return queryTree(root->right, i, j);
        // in the left section
        if (j <= mid) return queryTree(root->left, i, j);
        // in the middle section
        return queryTree(root->left, i, mid) + queryTree(root->right, mid + 1, j);
    }

    NumArray2(vector<int> &nums) {
        // create segment tree
        int n = nums.size();
        root = createTree(nums, 0, n - 1);
    }

    void update(int index, int val) {
        updateTree(root, index, val);
    }

    int sumRange(int left, int right) {
        return queryTree(root, left, right);
    }
};