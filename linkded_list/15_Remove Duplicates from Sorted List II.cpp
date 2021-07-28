//
// Created by yel on 2021/7/28.
//

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list. Return the linked list sorted as well.

// 问题：从有序链表中移除重复节点II:移除所有的重复节点，只保留不重复的节点。

// 方法：与一不同的地方在于，这里将所有重复的节点都删除，而不是保留一个。
// 递归：每次递归时比较当前节点和下一个节点是否相等，如果相等，则跳过当前节点和下一个节点，如果不相等，则当前节点next下指向下一个节点的递归

//
#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(NULL) {}
};


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return 0;
        if (!head->next) return head;

        ListNode *p = head->next;
        int val = head->val;
        if (val != p->val) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            while (p && p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};
