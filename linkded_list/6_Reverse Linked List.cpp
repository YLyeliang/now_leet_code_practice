//
// Created by yel on 2021/7/18.
//

// 链表反序

// 使用尾插法构建一个新的链表即可.
#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// 尾插法, O(n)空间
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode res(0);
        ListNode *p = &res;
        while (head) {
            ListNode *tmp = new ListNode(head->val);
            tmp->next = p->next;
            p->next = tmp;
            head = head->next;
        }
        return res.next;
    }
};

// 用三个指针
class Solution2 {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = new ListNode(0), *cur = head;
        pre->next = head;
        while (cur && cur->next) {
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }
        return pre->next;
    }
};

// 递归方法
class Solution3 {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};