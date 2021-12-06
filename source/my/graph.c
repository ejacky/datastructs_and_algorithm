#include <stdio.h>


#define MAX         100

// 边
typedef struct eNode {
    /* data */
    int weight;   // 权值
    int iv;       // 指向顶点
    struct eNode *next;
} ENode;

// 顶点
typedef struct _VNode {
    char data;

    ENode *first_edge;

} VNode;


// 邻接表
typedef struct lGraph {
    int vexnum;
    int edgenum;
    VNode vex[MAX];

} LGraph;

int main() {



    return 0;

}


// 深度优先
void DFSTraverse(LGraph graph) {

    int visited[MAX];
    for (int i = 0 ; i < graph.vexnum; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < graph.vexnum; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
        }
    }

}

// 深度优先递归遍历
void DFS(LGraph graph, int i, int *visited) {

    visited[i] = 1;
    printf("%c", graph.vex[i].data);

    ENode *node = graph.vex[i].first_edge;
    while (node != NULL) {
        if (!visited[node->iv]) {
            DFS(graph, node->iv, visited);
        }

        node = node->next;
    }
}

// 非递归深度遍历， 利用栈
void DFSNoRecur(LGraph graph, int i, int *visited) {
    int S[MAX];

    PushStack(S, i);

    while (!EmptyStack(S)) {

        PopStack(S, i);
        printf("%c", graph.vex[i].data);
        visited[i] = 1;

        ENode *node = graph.vex[i].first_edge;
        while (node != NULL) {
            if (!visited[node->iv]) {
                PushStack(S, node->iv);
            }

            node = node->next;
        }
    }
}


void BFSTraverse(LGraph graph) {

    int visited[MAX];
    for (int i = 0 ; i < graph.vexnum; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < graph.vexnum; i++) {
        if (!visited[i]) {
            BFS(graph, i, visited);
        }
    }

}

// 广度优先非递归遍历, 利用队列
static BFS(LGraph graph, int u, int *visited) {
   
    int Q[MAX];

    visited[u] = 1;
    EnQueue(Q, u);

    while (!EmptyQueue(Q)) {

        int j;
        DeDueue(Q, j);

        ENode *node = graph.vex[j].first_edge;
        
        while (node != NULL) {
            if (!visited[node->iv]) {
                visited[node->iv] = 1;
                EnQueue(Q, node->iv);
            }

            node = node->next;
        }
    }
}


// 队列
void EnQueue(int *Q, int i) {

}

void DeQueue(int *Q, int j) {

}

int EmptyQueue(int *Q)  {
    return 0;
}

// 栈
void PushStack(int *S, int i) {

}

void PopStack(int *S, int j) {

}

int EmptyStack(int *S)  {
    return 0;
}

//todo 有向图的入度
//todo 图中 u 到 v 是否有路径
//todo 图中找到 u 到 v 的一条路径

