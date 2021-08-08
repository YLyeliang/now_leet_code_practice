//
// Created by yel on 2021/7/30.
//

#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(NULL) {}
};

using namespace std;


class Solution {
public:
    ListNode *FindKthToTail(ListNode *pHead, int k) {
        ListNode *p = pHead, *q = pHead;
        cout << p << " " << q << endl;

        return q;
    }
};

int main() {
    ListNode a(10);
    ListNode *p1 = &a;

    ListNode b(12);
    ListNode *p2 = &b;

    p1->next = p2;
    cout << "p address: " << p1 << endl;
    cout << p1->val << " address: " << p1->next << endl;
    cout << p2 << endl;

    p1 = p1->next;    // 等价于 p = p2
    cout << p1->val << " address: " << p1 << endl;

    Solution sol;
    ListNode *res;
    res = sol.FindKthToTail(p1, 1);
    cout << res << endl;


}