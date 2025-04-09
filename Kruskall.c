#include <stdio.h>
#include <stdlib.h>

#define MAX 999 // Represents infinity

typedef struct {
    int u, v, w; // u and v are the vertices, w is the weight of the edge
} Edge;

Edge edges[100], mst[100]; // Arrays to store edges and MST edges
int parent[100];           // Array for union-find
int numEdges = 0;          // Number of edges
int n;                     // Number of vertices

// Function to find the root of a vertex
int find(int vertex) {
    if (parent[vertex] == vertex)
        return vertex;
    return find(parent[vertex]);
}

// Function to perform union of two sets
void unionSets(int u, int v) {
    parent[find(u)] = find(v);
}

// Kruskal's Algorithm
void kruskal() {
    int i, j, minCost = 0;

    // Sort edges based on their weights
    for (i = 0; i < numEdges - 1; i++) {
        for (j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize parent array for union-find
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    int mstEdges = 0; // Number of edges added to MST

    // Process edges
    for (i = 0; i < numEdges; i++) {
        if (find(edges[i].u) != find(edges[i].v)) { // Check if adding the edge forms a cycle
            mst[mstEdges++] = edges[i]; // Add edge to MST
            unionSets(edges[i].u, edges[i].v); // Perform union
            minCost += edges[i].w; // Add edge weight to MST cost
        }
        if (mstEdges == n - 1) // MST is complete
            break;
    }

    // Print the MST
    printf("Edges in Minimal Spanning Tree:\n");
    for (i = 0; i < mstEdges; i++) {
        printf("(%d, %d) - Weight: %d\n", mst[i].u, mst[i].v, mst[i].w);
    }
    printf("Total Weight of MST: %d\n", minCost);
}

int main() {
    int i;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (u v w) where u and v are vertices and w is the weight:\n");
    for (i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(); // Call Kruskal's algorithm
    return 0;
}
