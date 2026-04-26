#include <stdio.h>

#define V 5        // Total number of vertices in the graph
#define INF 999999 // Represents infinity (a very large value)

// Function to find the vertex with the smallest distance
// among the vertices that are not yet visited
int extractMin(int dist[], int visited[])
{
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++)
    {
        // Select the unvisited vertex with minimum distance value
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function implementing Dijkstra's shortest path algorithm
void dijkstra(int graph[V][V])
{
    int dist[V];     // Stores shortest distance from source vertex
    int visited[V];  // Indicates whether a vertex is finalized

    // Initialize all distances as infinite and visited as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Set distance of source vertex (vertex 0) to zero
    dist[0] = 0;

    // Process all vertices
    for (int count = 0; count < V; count++)
    {
        // Select the closest unvisited vertex
        int u = extractMin(dist, visited);

        // Stop if no reachable vertex remains
        if (u == -1)
            break;

        visited[u] = 1; // Mark selected vertex as visited

        // Update distances for all adjacent vertices
        for (int j = 0; j < V; j++)
        {
            // Update only if:
            // - There is a direct edge from u to j
            // - j has not been visited yet
            if (graph[u][j] > 0 && !visited[j])
            {
                // Relaxation step: check for shorter path via u
                if (dist[j] > dist[u] + graph[u][j])
                {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }

    // Display shortest distances from source vertex
    printf("\nVertex \t Distance from Source (0)\n");
    for (int i = 0; i < V; i++)
        printf("%d --> %d\n", i, dist[i]);
}

int main()
{
    // Graph represented using adjacency matrix
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    // Execute Dijkstra's Algorithm
    dijkstra(graph);

    return 0;
}
