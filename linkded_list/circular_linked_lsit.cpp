//
// Created by yel on 2021/7/7.
//

#include "stdio.h"
#include "iostream"

// 循环链表和非循环链表其实创建的过程唯一不同的是，非循环链表的尾结点指向空（NULL），而循环链表的尾指针指向的是链表的开头。

typedef struct list {
    int data;
    struct list *next;

    list(int a, list *b) : data(a), next(b) {}
} list;
//data为存储的数据，next指针为指向下一个结点


// 初始化
// 先创建一个头结点并且给其开辟内存空间，在开辟内存空间成功之后，将头结点的next指向head自身，创建一个init函数来完成；
// 为了重复创建和插入，我们可以在init函数重新创建的结点next指向空，而在主函数调用创建之后，将head头结点的next指针指向自身。
list *initList() {
    list *head = (list *) malloc(sizeof(list));
    if (head == NULL) {
        printf("failed");
        exit(0);
    } else {
        head->next = NULL;
        return head;
    }
}

int main() {
    // 主函数调用初始化
    list *head = initList();
    head->next = head;
}


// 创建
// 通过逐步的插入操作，创建一个新的节点，将原有链表尾结点的next指针修改指向到新的结点，新的结点的next指针再重新指向头部结点，
// 然后逐步进行这样的插入操作，最终完成整个单项循环链表的创建。

int insertList(list *head) {
    int data;
    scanf_s("%d", data);
    list *node = initList();
    node->data = data;
    if (head != NULL) {
        list *body = head;
        while (body->next != head) {
            body = body->next;
        }
        // 找到链表尾部后
        body->next = node;
        node->next = head;
        return 1;
    } else {
        printf("Head has no data");
        return 0;
    }
}

// 插入
list *insertList(list *head, int pos, int data) {
    list *node = initList();
    node->data = data;
    list *body = head;

    if (head != NULL) {
        for (int i = 1; i < pos; i++)
            body = body->next;
        node->next = body->next;
        body->next = node;
    }
    return head;
}