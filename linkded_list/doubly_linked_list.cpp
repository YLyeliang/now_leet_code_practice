//
// Created by yel on 2021/7/4.
//
#include "stdio.h"
#include "iostream"

// 在单链表的基础上，对于每一个结点设计一个前驱结点，前驱结点与前一个结点相互连接，构成一个链表，就产生了双向链表的概念了。双向链表可以简称为双链表，
// 是链表的一种，它的每个数据结点中都有两个指针，分别指向直接后继和直接前驱。所以，从双向链表中的任意一个结点开始，都可以很方便地访问它的前驱结点和后继结点。
typedef struct line {
    int data;           //data
    struct line *pre;   //pre node
    struct line *next;  //next node
} line, *a;
//分别表示该结点的前驱(pre)，后继(next)，以及当前数据(data)

// 创建
// 创建双向链表需要先创建头结点，然后逐步的进行添加双向链表的头结点是有数据元素的，也就是头结点的data域中是存有数据的，这与一般的单链表是不同的。
// 对于逐步添加数据，先开辟一段新的内存空间作为新的结点，为这个结点进行的data进行赋值，然后将已成链表的上一个结点的next指针指向自身，自身的pre指针指向上一个结点。
// 双向链表创建的过程可以分为：创建头结点->创建一个新的结点->将头结点和新结点相互链接->再度创建新结点。
line *initLine(line *head) {
    int number, pos = 1, input_data;
    scanf_s("%d", &number);
    if (number < 1)return NULL;
    head = (line *) malloc(sizeof(line)); // 开辟一块为line的大小的字节的内存，返回void*,表示未确定类型的指针，然后将类型转换成line*型，
    head->pre = NULL;
    head->next = NULL;
    scanf_s("%d", input_data); // 数据
    pos++;
    head->data = input_data;

    line *list = head;
    while (pos <= number) {
        line *node = (line *) malloc(sizeof(line));
        node->next = NULL;
        node->pre = NULL;
        scanf_s("%d", input_data);
        pos++;
        node->data = input_data;
        list->next = node;
        node->pre = list;
        list = list->next;
    }
    return head;
}

// 插入
// 对于每一次的双向链表的插入操作，首先需要创建一个独立的结点，并通过malloc操作开辟相应的空间；
// 其次我们选中这个新创建的独立节点，将其的pre指针指向所需插入位置的前一个结点；
// 同时，其所需插入的前一个结点的next指针修改指向为该新的结点，该新的结点的next指针将会指向一个原本的下一个结点，
// 而修改下一个结点的pre指针为指向新结点自身，这样的一个操作我们称之为双向链表的插入操作
line *insertLine(line *head, int data, int add) {
    //三个参数分别为：进行此操作的双链表，插入的数据，插入的位置
    line *node = (line *) malloc(sizeof(line));
    node->pre = NULL;
    node->next = NULL;
    node->data = data;
    // 插入到表头时
    if (add == 1) {
        node->next = head;
        head->pre = node;
        head = node;
    } else {
        line *body = head;
        for (int i = 1; i < add; i++) {
            body = body->next;
        }
        // 表尾
        if (body->next == NULL) {
            body->next = node;
            node->pre = body;
        } else {
            node->next = body->next;
            body->next->pre = node;
            node->pre = body;
            body->next = node;
        }
    }
    return head;
}


// 删除
// 删除操作的过程是：
// 选择需要删除的结点->选中这个结点的前一个结点->将前一个结点的next指针指向自己的下一个结点->选中该节点的下一个结点->将下一个结点的pre指针修改指向为自己的上一个结点。
// 之后，我们释放删除结点，归还空间给内存。
line *deleteLine(line *head, int data) {
    //输入的参数分别为进行此操作的双链表，需要删除的数据
    line *node = head;
    while (node) {
        if (node->data == data) {
            node->pre->next = node->next;
            node->next->pre = node->pre;
            free(node);
            return head;
        }
        node = node->next;
    }
    return head;
}

