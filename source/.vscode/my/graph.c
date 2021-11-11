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


static BFS(LGraph graph) {
   
    int Q[MAX];
    int visited[MAX];
    for (int i = 0; i < graph.vexnum; i++ ) {
        visited[i] = 0 ;
    }

    visited[0] = 1;
    EnQueue(Q, 0);

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

void EnQueue(int *Q, int i) {

}

void DeDueue(int *Q, int j) {

}

int QIsEmpty(int *Q)  {
    return 0;
}