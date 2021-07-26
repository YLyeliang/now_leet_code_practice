//
// Created by yel on 2021/7/26.
//

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// 问题：给定链表头节点，移除从尾到头的第n个节点，并返回头节点。

// 解法：1.递归方法:使用递归的方法，从尾节点开始，每经过一个节点+1，当数值等于n时，返回该节点指向的下一个节点地址，否则返回该节点

// 2. 双指针方法：首先用一个指针走n步，假设总共m个节点，则剩下m-n个节点，另一个指针从头节点开始走m-n步，即到达指定节点，然后删除该节点。
// 该方法不会导致内存溢出，
#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(NULL) {}
};

class Solution {
public:
    int m = 0;

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        head = check(head, n);
        return head;
    }

    ListNode *check(ListNode *p, int n) {
        if (p == NULL) return NULL;
        p->next = check(p->next, n);
        m += 1;
        if (m == n)
            return p->next;
        else
            return p;
    }
};

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** slow = &head;
        ListNode* fast = head;
        while (n--) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = &((*slow)->next);
        }

        ListNode* entry = *slow;
        *slow = entry->next;
        delete entry;
        return head;
    }
};