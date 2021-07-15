//  判断链表是否有环
//
//  使用快慢指针的方式，一个走一步，另一个走两步，当两个指针相遇，则链表有环。且相遇时节点为环的出口。

class Solution{
public:
    bool hasCycle(ListNode* head){
        if (head==NULL) return false;
        ListNode *s=head;
        ListNode *f=head;
        while (f->next && f->next->next){
            s=s->next;
            f=f->next;
            if (s==f) return true;
        }
        return false;
    }
