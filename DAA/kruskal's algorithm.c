#include <stdio.h>

#define V 5   // Total number of vertices
#define E 6   // Total number of edges

int parent[V]; // Array used for Union-Find (Disjoint Set)

// Function to find the root (leader) of a vertex
int findLeader(int v)
{
    // Move up the parent chain until reaching the root
    while (parent[v] != v)
        v = parent[v];

    return v;
}

// Function to unite two sets (Union operation)
void mergeSets(int u, int v)
{
    int a = findLeader(u);
    int b = findLeader(v);

    // Make one root point to the other
    parent[a] = b;
}

// Function to sort edges in ascending order based on weight
void sortEdges(int edges[E][3])
{
    // Bubble sort using edge weight (3rd column)
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                // Swap entire edge (source, destination, weight)
                for (int k = 0; k < 3; k++)
                {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }
}

// Function implementing Kruskal's Minimum Spanning Tree algorithm
void kruskal(int edges[E][3])
{
    // Step 1: Sort all edges by increasing weight
    sortEdges(edges);

    // Step 2: Initialize each vertex as its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int count = 0; // Number of edges included in MST
    int cost = 0;  // Total weight of MST

    printf("Selected Edges:\n");

    // Step 3: Iterate through sorted edges
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        // Include edge only if it doesn't form a cycle
        if (findLeader(u) != findLeader(v))
        {
            printf("%d -- %d (Weight: %d)\n", u, v, w);

            mergeSets(u, v); // Perform union of sets
            cost += w;
            count++;
        }

        // Stop when MST contains (V - 1) edges
        if (count == V - 1)
            break;
    }

    // Display total cost of MST
    printf("Total Cost: %d\n", cost);
}

int main()
{
    // Edge list format: {source, destination, weight}
    int edges[E][3] = {
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5},
        {1, 3, 3}, {2, 4, 4}, {3, 4, 2}
    };

    // Execute Kruskal's Algorithm
    kruskal(edges);

    return 0;
}
