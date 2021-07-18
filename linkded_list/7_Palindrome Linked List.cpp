//
// Created by yel on 2021/7/18.
//

// 给定单链表的头节点,判断链表是否为回文. O(n) time O(1) space
// 回文: 1221 121 正反序相等


// 判断回文,即判断首位节点的值是否相等.通常是是使用首尾指针向中间收缩即可.但是单链表之只能指向下一个节点.
// 若要同时判断首位节点,可以使用递归,并建立一个全局链表.
#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *tmp;

    bool isPalindrome(ListNode *head) {
        tmp = head;
        return check(head);
    }

    bool check(ListNode *p) {
        if (p == NULL) return true;

        // 注意,这里是在递归调用之后进行比较,即首先遍历完整个链表,然后才是对比尾节点与tmp(头节点)的值,然后在对tmp进行+1,递归返回到上一级,继续对比.
        bool isPal = check(p->next) & (p->val == tmp->val);
        tmp = tmp->next;
        return isPal;
    }
};

// 1 2 1
// check(2) & 1 == 1
// check(2): check(1) & (p