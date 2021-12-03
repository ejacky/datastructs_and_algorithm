#include <stdio.h>

typedef struct lnode {
    struct lnode *next;
    ElemType data;
}LNode, *LinkList;

// 链表删除指定元素
void delElem(LNode *n, ElemType x) {
    LNode *p;
    if (n == NULL) {
        return;
    }
    if (n->data == x) {
        p = n;
        n = n->next;
        free(p);
        delElem(n, x);
    } else {
        delElem(n->next, x);
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

//todo 反转链表

