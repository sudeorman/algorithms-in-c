#include <stdio.h>
#define V 5

void DFS(int graph[V][V], int visited[V], int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < V; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

int main() {
    int graph[V][V] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };

    int visited[V] = {0};

    printf("DFS traversal: ");
    DFS(graph, visited, 0);

    return 0;
}
