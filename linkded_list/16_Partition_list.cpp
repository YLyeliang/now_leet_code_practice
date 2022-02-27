// created by yel on 2022/2/26

// Given the head of a linked list and a value x,
// partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//Example 1:
//Input: head = [1,4,3,2,5,2], x = 3
//Output: [1,2,2,4,3,5]

//Example 2:
//Input: head = [2,1], x = 2
//Output: [1,2]

//Constraints:
//The number of nodes in the list is in the range [0, 200].
//-100 <= Node.val <= 100
//-200 <= x <= 200

// 问题：给定链表头部和值x, 分割链表，使得小于x的节点在链表前面，并保存链表之前的顺序

// 方法：
// 1. 基础方法：构建两个链表，遍历一次当前链表，根据值的大小进行尾插法生成。最后将两个链表进行拼接。
// Time: O(n) Space: O(n)

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
    ListNode *partition(ListNode *head, int x) {
        ListNode res(0), right(0);
        ListNode *p_l = &res, *p_r = &right;
        while (head) {
            ListNode *&ref = head->val < x ? p_l : p_r;
            ref->next = head;
            ref = ref->next;

            head = head->next;

        }
        // merge two listnode.
        p_l->next = right.next;
        p_r->next = nullptr;
        return res.next;

    }
};
