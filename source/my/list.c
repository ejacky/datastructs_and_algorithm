#include <stdio.h>

typedef struct lnode {
    struct lnode *next;
    ElemType data;
}LNode, *LinkList;

// 链表删除指定元素
void DelElem(LNode *n, ElemType x) {
    LNode *p;
    if (n == NULL) {
        return;
    }
    if (n->data == x) {
        p = n;
        n = n->next;
        free(p);
        DelElem(n, x);
    } else {
        DelElem(n->next, x);
    }
}

// 返回链表中最大元素
ElemType MaxElem(LNode *n) {
    if (n == NULL) {
        return n->data;
    }
    ElemType m = MaxElem(n->next);
    if (n->data > m) {
        return n->data;
    } else {
        return m;
    }
}

// 反转链表
struct LNode* ReverseList(LNode* head) {
    LNode* pre = NULL;
    LNode* cur = head;
    while (cur) {
        LNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

