#include <stdio.h>

#define MAXN 15          // Maximum number of cities allowed
#define INF 999999       // Represents a very large value (infinity)

int n;
int d[MAXN][MAXN];       // Cost matrix: cost from city i to city j
int dp[MAXN][1 << MAXN]; // DP table for memoization

// Function to compute minimum travel cost
// i → current city
// S → set of remaining cities to visit (bitmask)
int g(int i, int S)
{
    // If no cities left, return cost to go back to starting city (0)
    if (S == 0)
        return d[i][0];

    // Return stored result if already computed
    if (dp[i][S] != -1)
        return dp[i][S];

    int minCost = INF;

    // Try visiting each city present in set S
    for (int k = 0; k < n; k++)
    {
        // Check if city k is included in the set
        if (S & (1 << k))
        {
            // Compute cost of choosing city k next
            int cost = d[i][k] + g(k, S & ~(1 << k));

            // Update minimum cost if needed
            if (cost < minCost)
            {
                minCost = cost;
            }
        }
    }

    // Store result in DP table and return it
    return dp[i][S] = minCost;
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d", &n);

    // Input the cost matrix
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    // Initialize DP table with -1 (indicates uncomputed values)
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            dp[i][mask] = -1;

    // Start from city 0 and visit all other cities
    int result = g(0, (1 << n) - 2);

    // Display minimum travel cost
    printf("Minimum travelling cost = %d\n", result);

    return 0;
}
