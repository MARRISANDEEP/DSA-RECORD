#include <stdio.h>
#include <stdlib.h>

#define V 5  // Total number of vertices in the graph

// Function to find the vertex with the minimum key value
// from the set of vertices not yet included in MST
int minKey(int key[], int visited[])
{
    int min = 999999;   // Set initial minimum as a large value
    int min_index = 0;  // Variable to store index of minimum key

    for (int i = 0; i < V; i++)
    {
        // Select the unvisited vertex with smallest key value
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to display the MST edges and total weight
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's MST:\n");
    printf("Edge \tWeight\n");

    int total = 0;

    // Start from vertex 1 since vertex 0 is the root node
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    // Print total cost of MST
    printf("Total Cost = %d\n", total);
}

// Function implementing Prim's Minimum Spanning Tree algorithm
void primMST(int graph[V][V])
{
    int parent[V];   // Stores the resulting MST (parent of each vertex)
    int key[V];      // Stores minimum weight edge for each vertex
    int visited[V];  // Marks vertices already included in MST

    // Initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++)
    {
        key[i] = 999999;
        visited[i] = 0;
    }

    // Start from vertex 0
    key[0] = 0;      // Ensure this vertex is picked first
    parent[0] = -1;  // Root node of MST

    // Build MST with V-1 edges
    for (int count = 0; count < V - 1; count++)
    {
        // Pick vertex with smallest key value
        int u = minKey(key, visited);

        visited[u] = 1; // Mark vertex as included in MST

        // Update adjacent vertices of the selected vertex
        for (int v = 0; v < V; v++)
        {
            // Update key if:
            // - Edge exists between u and v
            // - v is not yet included in MST
            // - Current edge weight is smaller than existing key[v]
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the final Minimum Spanning Tree
    printPrimMST(parent, graph);
}

int main()
{
    // Graph represented using adjacency matrix
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    // Execute Prim's Algorithm
    primMST(graph);

    return 0;
}
