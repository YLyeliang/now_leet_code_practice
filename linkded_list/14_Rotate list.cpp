//
// Created by yel on 2021/7/28.
//

// Given the head of a linked list, rotate the list to the right by k places.

// 问题：给定链表头节点，将链表向右旋转k个位置。即每次将尾节点移到头节点

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Explanation: 12345 -> 51234 -> 45123

// 方法：首先将链表首尾相连构成一个环，并计算链表的长度。当旋转k个位置=链表长度时，等于没有旋转，因此可以用取余的方式来获得实际旋转k%=len个位置。
// 首先定位到尾节点，旋转k个位置后，尾节点的位置为len-k(脑补转圈圈).则新的尾节点的下一个节点为新的头节点，将新的尾节点指向空指针，返回新的头节点即可。

#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;
        int len = 1;
        ListNode *newH, *tail;
        newH = tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        if (k % len) {
            for (auto i = 0; i < len - k; i++) tail = tail->next; // 得到新的尾节点
        }
        newH = tail->next;
        tail->next = nullptr;

        return newH;
    }
};