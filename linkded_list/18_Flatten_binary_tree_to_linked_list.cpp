// created by yel on 2022/2/27

// Given the root of a binary tree, flatten the tree into a "linked list":
//
// The "linked list" should use the same TreeNode class where the right child pointer points to
// the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
//
//Example 1:
//Input: root = [1,2,5,3,4,null,6]
//Output: [1,null,2,null,3,null,4,null,5,null,6]

//Example 2:
//Input: root = []
//Output: []

//Example 3:
//Input: root = [0]
//Output: [0]
//
//Constraints:
//The number of nodes in the tree is in the range [0, 2000].
//-100 <= Node.val <= 100
//
//Follow up: Can you flatten the tree in-place (with O(1) extra space)?

// 问题：给定二叉树的根节点，铺平成一个链表。链表使用树的结构类型，其中right等价于next,left=nullptr.
// 链表的顺序为二叉树的前序遍历结果。
// 要求：O(1) space.

// 方法：二叉树的前序遍历为 root->left->right。
// 先考虑 O(n) space:
// 1. 构建二叉树的前序遍历。每一次将新建一个树节点，使用尾插法构建即可。

// 再来考虑O(1) space:
// 解法1：
// 前序遍历为根左右。 逆向思维一下，使用右左根的递归方式，可以得到反转链表，然后使用尾插法的方式，构建正序链表。
// time O(n)

#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    TreeNode *pre = nullptr;
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        // 右左根顺序遍历
        flatten(root->right);
        flatten(root->left);
        // 明确每个节点需要做的事情；
        // 尾插法构建反转链表
        root->right = pre;
        root->left = nullptr;
        pre = root;

    }
};