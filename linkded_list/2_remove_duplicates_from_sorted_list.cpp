//  给定有序链表头节，移除重复节点，每个重复的节点保留一个。

// 方法，因为是有序链表，所以每次比较当前节点和下一个节点是否相等，相等就跳过；
// 优化:如果有多个字符相等，则需要一次次跳过，比较费时间，可以建立一个指针，指向下一个不相等的节点；
class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode *p = head;
        ListNode *d = head;
        while (head){
            while (d&& d->val == head->val){
                d=d->next;
            }
            head->next =d;
            head=head->next;
        return p;
    }
};
