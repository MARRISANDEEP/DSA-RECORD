#include <stdio.h>

#define V 5  // Total number of vertices

// Function implementing a greedy approximation for Vertex Cover
void findVertexCover(int graph[V][V])
{
    int visited[V];  // Marks whether a vertex is included in the cover

    // Initialize all vertices as not included
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    // Iterate through all edges in the graph
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            // If an edge exists and neither vertex is selected
            if (graph[u][v] == 1 && !visited[u] && !visited[v])
            {
                // Add both vertices to the vertex cover
                visited[u] = 1;
                visited[v] = 1;
            }
        }
    }

    // Display the vertices included in the cover
    printf("Approximate Vertex Cover: ");

    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i])
        {
            printf("%d ", i);
            count++;
        }
    }

    // Print total number of vertices selected
    printf("\nTotal vertices in the cover: %d\n", count);
}

int main()
{
    // Graph represented using adjacency matrix
    // 1 indicates presence of edge, 0 indicates no edge
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("Executing Vertex Cover Approximation...\n");

    // Call the approximation function
    findVertexCover(graph);

    return 0;
}
