// created by yel on 2022/2/26

// Given the head of a singly linked list where elements are sorted in ascending order,
// convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which
// the depth of the two subtrees of every node never differ by more than 1.
//
//Example 1:
//
//
//Input: head = [-10,-3,0,5,9]
//Output: [0,-3,9,-10,null,5]
//Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
//Example 2:
//
//Input: head = []
//Output: []
//
//
//Constraints:
//
//The number of nodes in head is in the range [0, 2 * 104].
//-105 <= Node.val <= 105

// 问题：给定一个升序排列的单向链表，转换成一个高度平衡的BST。高度平衡指一个二叉树其两个子树的的深度差不超过1

// 方法：中序遍历一颗BST可以得到一个升序数组。
// 使用递归思想，构建一个递归函数来创建BST。有以下几个问题需要解决
// 1. 获取链表中心点。 使用快慢指针，快指针走两步，慢指针走一步，当快指针走到底时，慢指针所在位置为链表中点
// 2. 得到链表中点后，递归构造二叉树。左子树为链表为左边部分，右子树为链表右边部分。（因为是链表中点作为root，则是一颗平衡二叉树)
// 3. 递归函数。明确递归函数需要做的事情，当链表节点为空时，返回空；当链表下一个节点为空时，说明该节点为链表尾部，返回一个值相等的树节点；
// 结合1和2，完成递归函数
//
//
//

#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        auto fast = head->next, slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto mid = slow->next;    // get the middle node
        slow->next = nullptr;
        auto root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};

