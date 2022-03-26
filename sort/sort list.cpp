// created by yel on 2022/3/20

// Given the head of a linked list, return the list after sorting it in ascending order.
//
//Example 1:
//Input: head = [4,2,1,3]
//Output: [1,2,3,4]
//
// Example 2:
//Input: head = [-1,5,3,4,0]
//Output: [-1,0,3,4,5]
//
// Example 3:
//Input: head = []
//Output: []
//
// Constraints:
//The number of nodes in the list is in the range [0, 5 * 104].
//-105 <= Node.val <= 105
//
//Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

// 问题：链表排序

// 方法：归并排序,bottom-up & top-down
// 归并排序的思想：分治法，将链表/数组从中间拆分成两部分，对每一部分做排序，持续这一动作至每一部分变成单独的数字(即每个数组为一部分)
// 到最底部时每一个数字为以部分，这时候

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
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        // get length
        int length = 0;
        ListNode *cur = head;
        while (cur) {
            length++;
            cur = cur->next;
        }

        ListNode p(0);
        p.next = head;
        ListNode *left, *right, *tail;
        // bottom-up, step = 1 2 ... n/2;
        for (int step = 1; step < length; step <<= 1) {
            cur = p.next;
            tail = &p;
            while (cur) {
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return p.next;
    }

private:
    /**
     * 将链表分成两部分，前者包含前n个节点，返回第二个链表的头
     */
    ListNode *split(ListNode *head, int n) {
        for (int i = 1; head&& i < n; i++) head = head->next;
        if (!head) return nullptr;
        ListNode *second = head->next;
        head->next = nullptr;
        return second;
    }

    /**
     * 合并链表l1和l2,并添加到head尾部，返回合并后的尾部
     */
    ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head) {
        ListNode *cur = head;
        while (l1 && l2) { // 排序
            if (l1->val >= l2->val) {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        cur->next = l1 ? l1 : l2;
        while (cur->next)cur = cur->next;
        return cur;

    }
};