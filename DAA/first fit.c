#include <stdio.h>

// Function to apply First Fit bin packing algorithm
void firstFit(int items[], int n, int capacity)
{
    int bin[n];
    int binCount = 0;   // Tracks how many bins are currently in use

    // Initialize each bin with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Iterate through each item
    for (int i = 0; i < n; i++)
    {
        int placed = 0;   // Flag to check if current item is placed

        // Try placing item in already used bins
        for (int j = 0; j < binCount; j++)
        {
            // If item fits in this bin
            if (bin[j] >= items[i])
            {
                bin[j] -= items[i];   // Reduce available space
                printf("Item %d with weight %d placed in bin %d\n", i + 1, items[i], j + 1);
                placed = 1;
                break;   // Stop after placing in first suitable bin
            }
        }

        // If item doesn't fit in any existing bin, open a new bin
        if (!placed)
        {
            bin[binCount] = capacity - items[i];
            printf("Item %d with weight %d placed in bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;
        }
    }

    // Display total bins used
    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity;
    int items[100];

    // Read number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Read bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    // Input item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);

        // Ensure item size does not exceed bin capacity
        if (items[i] > capacity)
        {
            printf("Item size exceeds bin capacity. Please enter again.\n");
            i--;   // Repeat input for this item
        }
    }

    // Call First Fit function
    firstFit(items, n, capacity);

    return 0;
}
