// created by yel on 2024/2/28
// Given the root of a binary tree, check whether it is a mirror of itself
// (i.e., symmetric around its center).
//
// Example 1:
// Input: root = [1,2,2,3,4,4,3]
// Output: true
//
// Example 2:
// Input: root = [1,2,2,null,3,null,3]
// Output: false
//
// Constraints:
// The number of nodes in the tree is in the range [1, 1000].
//-100 <= Node.val <= 100
//
// Follow up: Could you solve it both recursively and iteratively?

// 问题：给定二叉树，判断是否是对称树
// 使用递归函数，其输入为左子树和右子树，该函数判断左右是否为空， 是否相等 &
// 递归该函数左 && 递归该函数右
#include "iostream"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    // recursively compare left and right
    if (!root) {
      return true;
    }
    return Compare(root->left, root->right);
  }
  bool Compare(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    }
    if (!left || !right) {
      return false;
    }
    return (left->val == right->val) && Compare(left->left, right->right) &&
           Compare(left->right, right->left);
  }
};

// 迭代方法:python

// class Solution2:
//     def isSymmetric(self, root):
//                               if root is None:
//     return True
//
//     stack = [[root.left, root.right]]
//
//             while len(stack) > 0:
//     pair = stack.pop(0)
//                 left = pair[0]
//     right = pair[1]
//
//                 if left is None and right is None:
//     continue
//     if left is None or right is None:
//     return False
//     if left.val == right.val:
//     stack.insert(0, [left.left, right.right])
//
//         stack.insert(0, [left.right, right.left])
//             else:
//     return False
//     return True