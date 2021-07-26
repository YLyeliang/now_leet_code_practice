//
// Created by yel on 2021/7/26.
//

// Given head which is a reference node to a singly-linked list.
// The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
//
//Return the decimal value of the number in the linked list.

// 问题：给定链表头节点，二进制表示的链表转成十进制整数

// 思想：链表从头节点开始遍历到尾节点。建立一个变量保存由头节点到当前节点的值，在每次取下一个节点的时候，将当前结果左移一位，并将当前节点的值进行相加。
// Note:可以使用逻辑或和左移，即完全使用位运算来完成，可以提升效率。

#include "iostream"
#include "vector"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(NULL) {}
};


class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int res = 0;
        while (head) {
            res = (res << 1) + head->val;
            head = head->next;
        }
        return res;
    }
};
