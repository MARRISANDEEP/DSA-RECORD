#include <stdio.h>

// Function that applies the Best Fit bin packing strategy
void bestFit(int items[], int n, int capacity) 
{ 
    printf("\nBest Fit Algorithm\n"); 
    
    int bin[n]; // Array to store remaining space in each bin
    int binCount = 0; // Number of bins currently used
    
    // Initialize all bins to full capacity
    for (int i = 0; i < n; i++) 
        bin[i] = capacity; 
    
    // Loop through each item
    for (int i = 0; i < n; i++) 
    { 
        int bestIndex = -1; // Stores index of the best bin for current item
        int minSpace = capacity + 1; // Tracks smallest leftover space
        
        // Check all existing bins to find the best fit
        for (int j = 0; j < binCount; j++) 
        { 
            // Choose the bin where leftover space is minimum after placing item
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
            { 
                bestIndex = j; 
                minSpace = bin[j] - items[i]; 
            } 
        } 
        
        // If a suitable bin is found, place the item there
        if (bestIndex != -1) 
        { 
            bin[bestIndex] -= items[i]; 
            printf("Item %d (weight: %d) placed in Bin %d\n",
                   i + 1, items[i], bestIndex + 1);
        } 
        // If no suitable bin exists, create a new bin
        else 
        { 
            bin[binCount] -= items[i]; 
            printf("Item %d (weight: %d) placed in Bin %d\n",
                   i + 1, items[i], binCount + 1);
            binCount++; 
        } 
    } 
    
    // Output total number of bins used
    printf("Total bins used = %d\n", binCount); 
} 

int main()
{
    int n, capacity; 
    
    // Read number of items from user
    printf("Enter number of items: "); 
    scanf("%d", &n); 
    
    // Declare array to store item sizes
    int items[n]; 
    
    // Read bin capacity
    printf("Enter bin capacity: "); 
    scanf("%d", &capacity); 
    
    printf("Enter item sizes:\n"); 
    
    // Input item sizes with validation
    for (int i = 0; i < n; i++) 
    { 
        int itemSize; 
        printf("Item %d: ", i + 1); 
        scanf("%d", &itemSize); 
        
        // Ensure item size does not exceed bin capacity
        if (itemSize <= capacity) 
        { 
            items[i] = itemSize; 
        } 
        else 
        { 
            printf("Item size exceeds bin capacity. Please enter again.\n");
            i--; // Repeat input for same item
        } 
    } 
    
    // Execute Best Fit algorithm
    bestFit(items, n, capacity); 
    
    return 0; 
}
