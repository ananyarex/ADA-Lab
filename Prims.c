#include <stdio.h>
#include <limits.h>

#define INF INT_MAX // Represents no edge (infinity)

void prims(int n, int cost[10][10]) {
    int visited[10] = {0}; // Tracks visited vertices
    int mst[10][3];        // Stores edges in MST (vertex1, vertex2, weight)
    int sum = 0;           // Sum of MST weights
    int edges = 0;         // Number of edges in the MST

    visited[0] = 1; // Start from the first vertex

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        // Find the smallest edge connecting visited and unvisited vertices
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            // Add the edge to MST
            visited[v] = 1;
            mst[edges][0] = u;
            mst[edges][1] = v;
            mst[edges][2] = min;
            sum += min;
            edges++;
        }
    }

    // Print the MST
    printf("Edges in Minimal Spanning Tree:\n");
    for (int i = 0; i < edges; i++) {
        printf("(%d, %d) - Weight: %d\n", mst[i][0], mst[i][1], mst[i][2]);
    }
    printf("Sum of weights in Minimal Spanning Tree: %d\n", sum);
}

int main() {
    int cost[10][10], n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 999 or INT_MAX for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(n, cost); // Call Prim's algorithm
    return 0;
}
