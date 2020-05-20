

// 用递归的方式反转链表

// 链表结构
class ListNode {
    int val;
    ListNode next;
    ListNode (int x){val=x;}
}

// 给定链表和位置，反转指定位置的链表
// 1->2->3->4->5->NULL , m=2, n=4
// 1->4->3->2->5->NULL
//
// 迭代法的思路，for循环找到m，然后for循环反转m-n的链表

// 主要说说递归的实现方式，
//一、递归反转整个链表
//
ListNode reverse(ListNode head) {
    if (head.next==NULL) return head;
    ListNode last=reverse(head.next);
    head.next.next=head;
    head.next=NULL;
    return last;
}

//1. 递归函数要有base case，也就是第一句
//

// 二、反转链表前N个节点
// 思路与一差不多，只需要稍加修改
ListNode successor=NULL; //后驱节点

// 反转以head为起点的n个节点，返回新的头节点
ListNode reverseN(ListNode head,int n){
    if (n==1) {
        // 记录第n+1个节点
        successor=head.next;
        return head;
    }
    //以head.next为起点，反转前n-1个节点
    ListNode last=reverseN(head.next,n-1);
    head.next.next=head;
    // 让反转后的head节点和后面的节点连起来
    head.next=successor;
    return last;
}

// 三、反转链表的一部分
// 给定一个索引区间[m,n]（索引从1开始），反转区间内的链表元素
// 如果m=1，就等于第二部分所说
ListNode reverseBetween(ListNode head, int m, int n) {
    // base case
    if (m==1) {
        //相当于反转前n个元素
        return reverseN(head,n);
    }
    // ...
}

// 如果m!=1，可以在递归的时候依次对m,n减1，即让head.next ...表示为初始索引
ListNode reverseBetween(ListNode head, int m, int n) {
    // base case
    if (m==1) {
        return reverseN(head,n);
    }
    head.next= reverseBetween(head.next,m-1,n-1);
    return head;
}

