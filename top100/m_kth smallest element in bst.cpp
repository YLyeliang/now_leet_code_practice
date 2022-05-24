// created by yel on 2022/5/21

// Given the root of a binary search tree, and an integer k, return the kth
// smallest value (1-indexed) of all the values of the nodes in the tree.
//
// Example 1:
// Input: root = [3,1,4,null,2], k = 1
// Output: 1
//
// Example 2:
// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3
//
// Constraints:
// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104
//
//
// Follow up: If the BST is modified often (i.e., we can do insert and delete
// operations) and you need to find the kth smallest frequently, how would you
// optimize?

// 问题：给定BST的根节点和整数k,返回第k个最小数（1-indexed)

// 方法：BST的中序遍历为有序数组，使用非递归方式进行实现。当遍历到第k个时则返回
#include "iostream"
#include "stack"
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
class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> s;
    while (root) {
      s.push(root);
      root = root->left;
    }
    while (k != 0) {
      // process current node
      k--;
      auto p = s.top();
      s.pop();
      if (k == 0) return p->val;
      // check current node whether have right node
      auto right = p->right;
      while (right) {
        s.push(right);
        right = right->left;
      }
    }
    return -1;
  }
};