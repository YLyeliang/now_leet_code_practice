//
// Created by yel on 2021/7/18.
//

// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.
//
// For example, the following two linked lists begin to intersect at node c1:
// It is guaranteed that there are no cycles anywhere in the entire linked structure.
//
//Note that the linked lists must retain their original structure after the function returns.

// 问题: 给定连个单链表,返回相交结点,否则返回null.

// 方法: 把两个链表相同的部分记为c，相交节点记为*, 则第一个链表记为 a * c, 第二个链表记为b * c
//两个虚拟链表AB, BA可以记为：
// AB = a * c b * c
// BA = b * c a * c
// a, b长度不一定同，但是第二个 * 之前两个链表的长度相同，由此两个虚拟链表走相同步数到达的相同点即为相交节点*.


#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;

            // 如果遇到相同节点,则返回该结点
            if (p1 == p2) return p1;

            // 如果其中一个到达尾节点,则以令一个链表的头节点作为起始节点继续前进.
            if (p1 == NULL) p1 = headB;
            if (p2 == NULL) p2 = headA;
        }
        return p1;
    }
};