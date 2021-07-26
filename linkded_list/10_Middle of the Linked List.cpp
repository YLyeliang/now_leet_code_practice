//
// Created by yel on 2021/7/21.
//


// Given a non-empty, singly linked list with head node head, return a middle node of linked list.
//
//If there are two middle nodes, return the second middle node.

// 问题： 给定非空单链表，返回中间节点，如果有两个中间节点，返回第二个。

// 方法：1.使用递归方法，建立全局变量记录当前节点的索引，和节点总数，以及返回节点；递归遍历节点，每次索引+1，遍历完之后，保留总数，并类似树的
// 后序遍历一样，从尾节点开始索引-1，并判断索引是否为中点。

// 2.快慢指针

#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(NULL) {}
};


class Solution {
    int count = 0;
    int total;
    ListNode *res;
public:
    ListNode *middleNode(ListNode *head) {
        check(head);
        return res;
    }

    void check(ListNode *p) {
        if (p == NULL) {
            total=count;
            return;
        }
        count += 1;
        check(p->next);
        count -= 1;
        if (count == total / 2 )
            res = p;
    }
};


class Solution2 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};