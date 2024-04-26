#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[], int V) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%6d %13d\n", i, dist[i]);
}

void dijkstra(int **graph, int src, int V) {
    int *dist = (int *)malloc(V * sizeof(int));
    bool *sptSet = (bool *)malloc(V * sizeof(bool));

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSolution(dist, V);

    free(dist);
    free(sptSet);
}

void floydWarshall(int **graph, int V) {
    int **dist = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        dist[i] = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printf("Following matrix shows the shortest distances between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < V; i++)
        free(dist[i]);
    free(dist);
}

int **createGraph(int V) {
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph[i] = (int *)malloc(V * sizeof(int));

    printf("Enter the adjacency matrix representing the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int value;
            do {
                scanf("%d", &value);
                if (i == j && value != 0) {
                    printf("Invalid input! Diagonal elements must be 0.\n");
                    printf("Please enter a valid value: ");
                }
            } while (i == j && value != 0);
            graph[i][j] = value;
        }
    }
    return graph;
}

int main() {
    int V, choice;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    int **graph = createGraph(V);

    printf("\nEnter your choice of algorithm:\n");
    printf("1. Dijkstra's algorithm\n");
    printf("2. Floyd-Warshall algorithm\n");
    printf("3. Both\n");
    printf("Enter choice (1/2/3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nDijkstra's algorithm:\n");
            dijkstra(graph, 0, V);
            break;
        case 2:
            printf("\nFloyd-Warshall algorithm:\n");
            floydWarshall(graph, V);
            break;
        case 3:
            printf("\nDijkstra's algorithm:\n");
            dijkstra(graph, 0, V);
            printf("\nFloyd-Warshall algorithm:\n");
            floydWarshall(graph, V);
            break;
        default:
            printf("Invalid choice!\n");
    }

    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
