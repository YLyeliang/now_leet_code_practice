//
// Created by yel on 2021/8/4.
//

// 给定二叉树，和一个targetSum，返回从根节点到叶节点的路径和等于targetSum的所有路径。

// 经典问题：可以使用DFS和BFS来解决，其中可以分别使用递归和迭代来实现。
// DFS:1.递归， 使用前序遍历的方式，可以得到所有的路径，在每一次的递归调用时/传到下一个节点时，保存targetSum之前节点的和，当为叶节点时，
// 比较targetSum与当前节点加上之前节点之和是否相等，如果相等，表明这一条路径是匹配的。
// DFS:2.迭代. 迭代的方式一般通过构建栈或队列来存储节点。



#include "iostream"
#include "vector"

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
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        getAllPath(root, targetSum, {}, result);
        return result;

    }

    void getAllPath(TreeNode *root, int targetSum, vector<int> tmp, vector<vector<int>> &res) {
        if (!root)
            return;
        if (!root->left and !root->right and targetSum == root->val) {
            tmp.push_back(root->val);
            res.push_back(tmp);
        }
        tmp.push_back(root->val);
        getAllPath(root->left, targetSum - root->val, tmp, res);
        getAllPath(root->right, targetSum - root->val, tmp, res);
    }
};
