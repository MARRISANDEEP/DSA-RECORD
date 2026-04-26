#include <stdio.h>

// Structure representing an item with weight, value, and ratio
struct Item
{
    int weight;   // Stores weight of the item
    int value;    // Stores value (profit) of the item
    float ppw;    // Stores profit per unit weight (value / weight)
};

// Function to sort items in descending order of profit-to-weight ratio
void sort(struct Item items[], int n)
{
    struct Item temp;

    // Bubble sort to arrange items based on highest ratio first
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ppw < items[j + 1].ppw)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    float capacity;

    // Read number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Check for valid number of items
    if (n <= 0)
        return 1;

    struct Item items[n];

    // Input weight and value for each item
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Compute value-to-weight ratio
        items[i].ppw = (float)items[i].value / items[i].weight;
    }

    // Input maximum capacity of the knapsack
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items by decreasing profit per weight
    sort(items, n);

    float totalProfit = 0.0;

    // Apply greedy approach for Fractional Knapsack
    for (int i = 0; i < n; i++)
    {
        // If entire item can be included
        if (capacity >= items[i].weight)
        {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            // Include fraction of the item to fill remaining capacity
            totalProfit += items[i].ppw * capacity;
            break; // Knapsack is completely filled
        }
    }

    // Print final maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
