//
// Created by yel on 2021/7/18.
//

// Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list,
// instead you will be given access to the node to be deleted directly.
//
//It is guaranteed that the node to be deleted is not a tail node in the list.

// 给定链表中的一个要删除的节点,将其删除.

// ?这个问题有点反常识.评论区给的解法是将当前节点的值修改为下一个节点的值,然后跳过.
// 这个更像是对节点进行修改,然后跳过下一个节点,这可能会造成内存的泄露,因为跳过的节点没有删除,并且不知道其分配的空间是在栈上或是堆上,是否需要手动释放.

#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};