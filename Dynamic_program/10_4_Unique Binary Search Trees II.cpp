// created by yel on 2022/2/5
#include "iostream"
#include "vector"

using namespace std;

// 问题：给定整数n,返回所有结构独立的BST，其结点数为1-n。以任意序列返回结果。

// 方法：与I不同的是，这里要返回所有BST的结构。
// 考虑到可以从n-1的树构建出n个结点的树。这里有2种条件：
// 1. n-th node is the new root, new_root -> left = old_root
// 2. n-th node is not the new root. Traverse the old tree, when the node has right child,
// perform: old node -> right = n-th node, n-th node -> left = right child.
// When reach the end of the tree, add the n-th node as the leaf node.

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *clone(TreeNode *root) {
        if (root == nullptr)
            return nullptr;
        TreeNode *new_root = new TreeNode(root->val);
        new_root->left = clone(root->left);
        new_root->right = clone(root->right);
        return new_root;
    }

    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> res(1, nullptr);
        for (int i = 1; i <= n; i++) {
            vector<TreeNode *> tmp;
            for (int j = 0; j < res.size(); j++) {
                // case 1: n-th node is the new root
                TreeNode *oldroot = res[j];
                TreeNode *root = new TreeNode(i);
                TreeNode *target = clone(oldroot);
                root->left = target;
                tmp.push_back(root);
                if (oldroot != nullptr) {
                    TreeNode *tmpold = oldroot;
                    // case 2: 1) n-th node is not the root.
                    while (tmpold->right != nullptr) {
                        TreeNode *nonroot = new TreeNode(i);
                        TreeNode *tright = tmpold->right;
                        tmpold->right = nonroot;
                        nonroot->left = tright;
                        TreeNode *target = clone(oldroot);  // add into vector
                        tmp.push_back(target);
                        tmpold->right = tright; // recover back into original state.
                        tmpold = tmpold->right; // traverse next right node.
                    }
                    tmpold->right = new TreeNode(i);
                    TreeNode *target = clone(oldroot);
                    tmp.push_back(target);
                    tmpold->right = nullptr;
                }
            }
            res = tmp;
        }
        return res;
    }
};
