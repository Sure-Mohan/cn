#include <stdio.h>
#define INF 9999
#define MAX 10
void dijkstra(int g[MAX][MAX], int n, int src) {
    int dist[MAX], visited[MAX];
    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;
    // Main algorithm
    for (int c = 0; c < n - 1; c++) {
        int u = -1;
        // Pick minimum distance unvisited vertex
        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        visited[u] = 1;
        // Relax edges
        for (int v = 0; v < n; v++)
            if (g[u][v] && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }
    printf("Vertex  Distance\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}
int main() {
    int n, g[MAX][MAX], src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    printf("Enter source: ");
    scanf("%d", &src);
    dijkstra(g, n, src);
    return 0;
}
