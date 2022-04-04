// created by yel on 2022/4/4

// Given the head of a linked list, return the node where the cycle begins. If
// there is no cycle, return null.
//
// There is a cycle in a linked list if there is some node in the list that can
// be reached again by continuously following the next pointer. Internally, pos
// is used to denote the index of the node that tail's next pointer is connected
// to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as
// a parameter.
//
// Do not modify the linked list.
//
// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the
// second node.
//
// Example 2:
// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the
// first node.
//
// Example 3:
// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.
//
// Constraints:
//
// The number of the nodes in the list is in the range [0, 104].
//-105 <= Node.val <= 105
// pos is -1 or a valid index in the linked-list.
//
//
// Follow up: Can you solve it using O(1) (i.e. constant) memory?

// 问题： 链表有环，返回环入口的节点

// 方法： I中，判断的是链表是否有环，通过快慢指针的方式来实现。
// II中，需要找到环的入口.
// 简而言之，当快慢指针遇到的时候，从链表头部开始走，当头指针和慢指针相遇时，即为入口

// 证明：
// Distance traveled by slow when they meet: L1+L2
// Distance traveled by fast when they meet: L1+L2+x+L2, where x is the
// remaining length of the cycle (meeting point to start of the cycle).
//
// 2(L1+L2) = L1+L2+x+L2
// 2L1 + 2L2 = L1+2L2+x
//=> x = L1
//

#include "iostream"

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    ListNode *slow = head, *fast = head, *entry = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {  // slow meet fast, then walk slow and entry
        while (slow != entry) {
          slow = slow->next;
          entry = entry->next;
        }
        return entry;
      }
    }
    return nullptr;
  }
};