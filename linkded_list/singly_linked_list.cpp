//
// Created by yel on 2021/6/30.
//
#include "iostream"
#include "stdio.h"

using namespace std;

// 定义
typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkedList;


int main() {


}

// 链表的初始化：创建一个单链表的前置结点，并向后逐步添加结点，
LinkedList listinit() {
    Node *L;
    L = (Node *) malloc(sizeof(Node));
    if (L == NULL) {
        printf("failed");
        exit(0);
    }
    L->next == NULL;
}

// 头插法构建单链表
// 利用指针指向下一个结点元素的方式进行逐个创建，使用头插入法最终得到的结果是逆序的。
LinkedList LinkedListCreateH() {
    Node *L;
    L = (Node *) malloc(sizeof(Node));
    L->next = NULL;

    int x; // x为链表数据域中的数据
    while (scanf("%d", &x) != EOF) {
        Node *p;
        p = (Node *) malloc(sizeof(Node));
        p->data = x;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

// 尾插法构建单链表
// 头插法生成的链表中，结点的次序和输入数据的顺序不一致。若希望两者次序一致，则需要尾插法。
// 该方法是将新结点逐个插入到当前链表的表尾上，为此必须增加一个尾指针r, 使其始终指向当前链表的尾结点.
LinkedList LinkedListCreateT() {
    Node *L;
    L = (Node *) malloc(sizeof(Node));
    L->next = NULL;

    Node *r;
    r = L;  // r始终指向终端结点，开始时指向头结点
    int x;
    while (scanf("%d", &x) != EOF) {
        Node *p;
        p = (Node *) malloc(sizeof(Node));
        p->data = x;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return L;
}

// 遍历单链表如打印、修改
// 从链表的头开始，逐步向后进行每一个元素的访问，称为遍历。
// 进行遍历的思路极其简单，只需要建立一个指向链表L的结点，然后沿着链表L逐个向后搜索即可
void printList(LinkedList L) {
    Node *p = L->next; // 头结点
    int i = 0;
    while (p) {
        printf("%dth data:%d \n", ++i, p->data);
        p = p->next;
    }
}

//链表内容的修改，在链表中修改值为x的元素变为为k。
LinkedList LinkedListReplace(LinkedList L, int x, int k) {
    Node *p = L->next;
    while (p) {
        if (p->data == x)
            p->data = k;
        p = p->next;
    }
    return L;

}

// 插入
// 链表的插入操作主要分为查找到第i个位置，将该位置的next指针修改为指向我们新插入的结点，而新插入的结点next指针指向我们i+1个位置的结点。
// 其操作方式可以设置一个前驱结点，利用循环找到第i个位置，再进行插入。
LinkedList LinkedListInsert(LinkedList L, int i, x) {
    Node *pre; // 前驱结点，来遍历链表
    for (int temp_i = 1; temp < i; temp_i++)
        pre = pre->next;
    // pre到达插入位置
    Node *p;
    p = (Node *) malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;
    return L;
}

// 删除
// 删除元素要建立一个前驱结点和一个当前结点，当找到了我们需要删除的数据时，
// 直接使用前驱结点跳过要删除的结点指向要删除结点的后一个结点，再将原有的结点通过free函数释放掉。

LinkedList LinkedListDelete(LinkedList L, int x) {
    Node *p, *pre; // p 为查找的结点
    p = L->next;
    while (p->data != x) {
        pre = p;
        p = p->next;
    }
    pre->next = p->next;    // 将前驱指向删除结点的后继
    fread(p);
    return L;
}