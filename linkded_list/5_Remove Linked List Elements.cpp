//
// Created by yel on 2021/7/18.
//

// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val,
// and return the new head.

// 问题:给定链表头节点和一个整数,移除链表中所有值与该整数相等的节点.

// 方法:在leetcode中,给出的链表是不包含起始头节点的,而是从链表的第一个值开始.
// 这里需要建立一个头节点,其next为给定链表的地址.然后遍历链表,跳过相等的节点.最后返回起始头节点->next.
#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode dummy(0);

        ListNode *p = &dummy;
        p->next = head;

        while (p && p->next != NULL) {
            if (p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return dummy.next;
    }
};