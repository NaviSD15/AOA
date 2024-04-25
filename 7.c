#include <stdio.h>

#define V 4 // Number of vertices in the graph
#define INF 99999 // Infinity value for representing unreachable paths

void floydWarshall(int graph[V][V]) {
    // Perform the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Update shortest path if vertex k is on the shortest path from i to j
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() {
    int graph[V][V];

    // Get the graph as input from the user
    printf("Enter the adjacency matrix of the graph (%dx%d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (i == j) {
                graph[i][j] = 0; // Diagonal elements (self-loop) should be 0
            } else if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF; // Convert 0 to INF for unreachable paths (except self-loop)
            }
        }
    }

    // Find and print all pair shortest paths using Floyd-Warshall Algorithm
    floydWarshall(graph);

    printf("All Pair Shortest Paths:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF) {
                printf("INF\t"); // Print INF for unreachable paths
            } else {
                printf("%d\t", graph[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
