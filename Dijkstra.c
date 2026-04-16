#include <stdio.h>
#define V 5
#define INF 9999

int minDistance(int dist[], int visited[]) {
    int min = INF, index = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[V][V], int start) {
    int dist[V], visited[V] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Baslangic dugumu: %d\n", start);
    for (int i = 0; i < V; i++) {
        printf("%d -> %d = %d\n", start, i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0,10,3,0,0},
        {10,0,1,2,0},
        {3,1,0,8,2},
        {0,2,8,0,7},
        {0,0,2,7,0}
    };

    dijkstra(graph, 0);
    return 0;
}
