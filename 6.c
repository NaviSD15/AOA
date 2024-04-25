#include <stdio.h>
#define SIZE 20
#define INFINITY 32767

void Prim(int G[][SIZE], int nodes) {
    int tree[SIZE], i, j, k;
    int min_dist, v1 = 0, v2 = 0, total = 0;

    // Initializing tree array to track included vertices in MST
    for (i = 0; i < nodes; i++)
        tree[i] = 0;

    printf("\n\nThe Minimal Spanning Tree Is:\n");
    tree[0] = 1; // Start with the first vertex in the tree

    // Loop to select edges for MST
    for (k = 1; k < nodes; k++) {
        min_dist = INFINITY;

        // Finding the minimum weight edge connecting the tree to non-tree vertices
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                if (G[i][j] && ((tree[i] && !tree[j]) || (!tree[i] && tree[j]))) {
                    if (G[i][j] < min_dist) {
                        min_dist = G[i][j];
                        v1 = i;
                        v2 = j;
                    }
                }
            }
        }

        // Adding the selected edge to MST
        if (min_dist != INFINITY) {
            printf("\nEdge (%d, %d) and weight = %d", v1, v2, min_dist);
            tree[v1] = tree[v2] = 1;
            total += min_dist;
        }
    }

    // Outputting the total weight of the MST
    printf("\n\nTotal Path Length Is = %d\n", total);
}

int main() {
    int G[SIZE][SIZE], nodes;
    int v1, v2, length, i, j, n;

    printf("\n\tPrim's Algorithm \n");
    printf("\nEnter Number of Nodes in The Graph: ");
    scanf("%d", &nodes);

    // Initializing the graph adjacency matrix
    for (i = 0; i < nodes; i++)
        for (j = 0; j < nodes; j++)
            G[i][j] = 0;

    printf("Enter Number of Edges in The Graph: ");
    scanf("%d", &n);

    // Reading edges and weights
    printf("\nEnter edges and weights \n");
    for (i = 0; i < n; i++) {
        printf("\nEnter Edge by V1 and V2: ");
        scanf("%d %d", &v1, &v2);
        printf("Enter corresponding weight:");
        scanf("%d", &length);
        G[v1][v2] = G[v2][v1] = length; // Creating undirected graph
    }

    // Calling Prim's algorithm to find MST
    Prim(G, nodes);

    return 0;
}
