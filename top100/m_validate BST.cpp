// created by yel on 2022/4/3

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//
//A valid BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//
//Example 1:
//Input: root = [2,1,3]
//Output: true
//
// Example 2:
//Input: root = [5,1,4,null,null,3,6]
//Output: false
//Explanation: The root node's value is 5 but its right child's value is 4.
//
//Constraints:
//The number of nodes in the tree is in the range [1, 104].
//-231 <= Node.val <= 231 - 1

// 问题：给定二叉树的root，判断是否为合理的BST

// 方法：BST的特性为，中序遍历结果为有序数组，根据这一特性进行比较。
// 在整个过程中，需要判断与上一个搜索节点的值，因此需要一个额外的变量来进行存储。设置一个全局变量来进行存储；

#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool res = true;

    TreeNode *pre = nullptr;

public:
    bool isValidBST(TreeNode *root) {
        inorderTraverse(root);
        return res;
    }

    void inorderTraverse(TreeNode *root) {
        if (root == nullptr) return;

        isValidBST(root->left);

        if (pre == nullptr)
            pre = root;
        else {
            if (root->val <= pre->val)
                res = false;
            pre = root;

        }
        isValidBST(root->right);

    }
};