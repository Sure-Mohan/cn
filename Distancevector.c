#include <stdio.h>
#define INF 999
#define MAX 10
int main() {
    int n, i, j, k, updated;
    int cost[MAX][MAX], dist[MAX][MAX];
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (999 for INF):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    // Initialize distance table
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = cost[i][j];
    // Distance Vector Algorithm
    do {
        updated = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                for (k = 0; k < n; k++)
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        updated = 1;
                    }
    } while (updated);
    // Print final distance table
    printf("\nFinal Distance Table:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }
    return 0;
}
