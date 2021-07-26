//
// Created by yel on 2021/7/26.
//

// Given a linked list, swap every two adjacent nodes and return its head.
// You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

// 问题：给定链表，交换每两个相邻的节点，并返回头节点。 Note:不能修改节点的值

// 方法： 使用三个指针。对于头节点，第一次交换时只需要考虑两个节点的交换就行，然后迭代的将两个指针指向下两个节点，这里两个节点交换之后，上两个节点的
// 右侧节点指向的指向也需要进行改变，所以需要第三个指针来改变该节点的指向。

#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL | head->next == NULL) return head;
        ListNode *cur = head;
        ListNode *lat = head->next;
        ListNode *res = head->next;
        ListNode *pre = NULL;
        while (cur && lat) {
            cur->next = lat->next;
            lat->next = cur;
            if (pre)
                pre->next = lat;
            pre = cur;
            cur = cur->next;
            if (cur != NULL)
                lat = cur->next;
            else
                break;
        }
        return res;
    }
};

// 优化：使用二级指针，可以减少一级指针的调用
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head, *a, *b;
        while ((a = *pp) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
};
