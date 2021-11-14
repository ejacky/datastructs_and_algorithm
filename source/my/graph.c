#include <stdio.h>


#define MAX         100

// 边
typedef struct _ENode {
    /* data */
    int weight;   // 权值
    int iv;       // 指向顶点
    struct _ENode *next;
} ENode;

// 顶点
typedef struct _VNode {
    char data;

    ENode *first_edge;

} VNode;


// 邻接表
typedef struct _LGraph {
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

static DFS(LGraph graph, int i, int *visited) {

    visited[i] = 1;
    printf("%c", graph.vex[i].data);

    ENode *node = graph.vex[i].first_edge;
    while (node != NULL) {
        if (!visited[node->iv]) {
            DFS(graph, node->next, visited);
        }

        node = node->next;
    }
}

// 非递归深度遍历， 利用栈
static DFS1(LGraph graph, int i, int *visited) {
    int S[MAX];

    PushStack(S, i);

    while (!SIsEmpty(S)) {

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

static BFS(LGraph graph, int u, int *visited) {
   
    int Q[MAX];

    visited[u] = 1;
    EnQueue(Q, u);

    while (!QIsEmpty(Q)) {

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

void DeDueue(int *Q, int j) {

}

int QIsEmpty(int *Q)  {
    return 0;
}

// 栈
void PushStack(int *S, int i) {

}

void PopStack(int *S, int j) {

}

int SIsEmpty(int *S)  {
    return 0;
}
