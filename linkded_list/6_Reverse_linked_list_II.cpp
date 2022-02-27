// created by yel on 2022/2/26

// Given the head of a singly linked list and two integers left and right where left <= right,
// reverse the nodes of the list from position left to position right, and return the reversed list.
//
//Example 1:
//Input: head = [1,2,3,4,5], left = 2, right = 4
//Output: [1,4,3,2,5]

//Example 2:
//Input: head = [5], left = 1, right = 1
//Output: [5]
//
//Constraints:
//The number of nodes in the list is n.
//1 <= n <= 500
//-500 <= Node.val <= 500
//1 <= left <= right <= n

//Follow up: Could you do it in one pass?

// 问题：反转链表2，给定单向链表的头，和两个整数left & right, where left <= right.
// 反转从位置left到right这一段的链表，返回该链表

// 方法：
// 1. (太复杂)遍历链表，计数到left时，建立一个p_l指针存储当前位置；同时建立一个新的链表，使用尾插法来构建链表，到right时，链表构建结束，
// 指向下一个节点，同时将p_l指向新建立的链表即可。
// 细节： 遍历链表，到left时，存储left前面的节点。反转left到right之间的链表，到right时，将reverse_list->next = head->next.
// p_l->next =  reverse_list;

// 2. 首先定位到left之前的节点(pre),和left节点(cur).然后移动 cur->next到pre后面 right-left次。
// 重点是反转链表部分。

#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *p = new ListNode(0), *pre = p, *cur;
        p->next = head;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        cur = pre->next;
        // 反转链表，重点部分
        for (int i = 0; i < right - left; i++) {
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
        }
        return p->next;
    }
};