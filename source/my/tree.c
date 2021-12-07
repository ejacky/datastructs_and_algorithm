#include <stdio.h>
typedef struct biTree
{
    ElemType data;
    struct biTree *lChild;
    struct biTree *rChild;
    struct biTree *parent;

    int depth;
    int bf;
    /* data */
} BiTNode, *BiTree;


int main() {

}

// 计算每个结点的平衡因子
int FactorDepthMake(BiTree *tree) {
    if (tree != NULL) {
        int m = n = 0;
        if (tree->lChild != NULL) {
            m = FactorDepthMake(tree->lChild)
        }
        if (tree->rChild != NULL) {
            n = FactorDepthMake(tree->rChild)
        }
        tree->depth = (m > n)?m : n;
        tree->bf = m - n;

    }
    return tree->depth;
}

// 二叉树节点求和
int Sum(BiTNode *b) {
    if (b == NULL) {
        return 0;
    }

    return (b->data + Sum(b->lChild) + Sum(b->rChild));
}

// 销毁树
void DestroyTree(BiTNode *b) {
    if (b != NULL) {
        DestroyTree(b->lChild);
        DestroyTree(b->rChild);
        free(b);
    } else {
        return ;
    }
}

// 求深度
int Depth(BiTNode *b) {
    int m,n;
    if b == NULL {
        return 0;
    }

    m = Depth(b->lChild);
    n = Depth(b->rChild);

    if (m > n) {
        return m+1;
    } else {
        return n+1;
    }
}

// 求节点个数
int NodeCount(BiTNode *b) {
    int lNum, rNum;
    if (b == NULL) {
        return 0;
    } else {
        lNum = NodeCount(b->lChild);
        rNum = NodeCount(b->rChild);
        return lNum + rNum + 1;
    }
}

// 递归先序遍历
void PreOrder(BiTNode *b) {
    if (b == NULL) {
        return;
    } else {
        printf("%d", b->data);
        PreOrder(b->lChild);
        PreOrder(b->rChild);
    }
}

// 非递归先序
void PreOrderNoRecur(BiTree root) {
    BiTNode *b;
    InitStack(s);
    PushStack(s, root);
    while (!EmptyStack(s)) {
        PopStack(s, b);
        printf("%d", b->data);
        if (b->lChild != NULL) {
            PushStack(s, b->lChild);
        }
        if (b->rChild != NULL) {
            PushStack(s, b->rChild);
        }
    }
}

// 中序递归
void InOrder(BiTNode *b) {
    if (b != NULL) {
        InOrder(b->lChild);
        printf("%d", b->data);
        InOrder(b->rChild);
    }
}

// 中序非递归
void InOrderNoRecur(BiTree root) {
    InitStack(s);
    BiTNode *p;
    p = root;
    while (!EmptyStack(s) || p != NULL) {
        while (p->lChild != NULL) {
            PushStack(s, p);
            p = p->lChild;
        }

        if (!EmptyStack(s)) {
            PopStack(s, p);
            printf("%d", p->data);
            p = p->rChild;
        }
    }
}

//todo 根节点到某一节点的路径

//递归的三大要素 https://blog.csdn.net/dreamispossible/article/details/90552557
// 1 理解函数意义
// 2 寻找递归返回条件
// 3 找出等价关系

