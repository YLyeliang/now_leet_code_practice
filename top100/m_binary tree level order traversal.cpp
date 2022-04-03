// created by yel on 2022/4/3

// Given the root of a binary tree, return the level order traversal of its
// nodes' values. (i.e., from left to right, level by level).
//
// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
//
// Example 2:
// Input: root = [1]
// Output: [[1]]
//
// Example 3:
// Input: root = []
// Output: []
//
// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
//-1000 <= Node.val <= 1000

// 问题：给定二叉树的根节点，返回层序遍历的结果

// 方法：
// 1. 使用队列.
// 构建队列来从左至右的存储当前行的所有节点，循环读取这些队首节点，每次读取一个节点，则将左右节点push到队尾

// 2. 前序遍历: 前序遍历为根左右，在遍历过程中，其值为从左到右，从上到下。
// 但由于前序遍历会深度优先，需要一个额外的变量来表示当前的深度信息，并根据这个深度信息，来在对应的数组中添加节点值
// e.g depth=1时push到depth=1的数组， depth=2时push到depth为2的数组。

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// pre-Order
class Solution {
 private:
  vector<vector<int>> res;

 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    preOrder(root, 0);
    return res;
  }
  void preOrder(TreeNode *root, int depth) {
    if (root == nullptr) return;
    if (res.size() == depth) res.push_back(vector<int>());
    res[depth].push_back(root->val);
    preOrder(root->left, depth + 1);
    preOrder(root->right, depth + 1);
  }
};

// queue

class Solution2 {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      vector<int> cur_level;
      for (int i = 0; i < n; i++) {
        TreeNode *p = q.front();
        q.pop();
        cur_level.push_back(p->val);
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
      }
      res.push_back(cur_level);
    }
    return res;
  }
};
