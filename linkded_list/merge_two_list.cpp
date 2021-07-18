//
// Created by yel on 2021/7/7.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr)
            return l2;
        else
            return l1;
        ListNode *p;
        if (l1->val <= l2->val) {
            p = l1;
            l1 = l1->next;
        } else {
            p = l2;
            l2 = l2->next;
        }
        ListNode *res = p;
        while (l1 || l2) {
            if (l1 == nullptr) {
                p->next = l2;
                break;
            }
            if (l2 == nullptr) {
                p->next = l1;
                break;
            }

            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }

        }
        return res;
    }
};