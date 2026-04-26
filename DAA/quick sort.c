#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integer values using pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array around a pivot
// Elements smaller than pivot go left, larger go right
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];   // Select last element as pivot
    int i = low - 1;         // Tracks position for smaller elements

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Place pivot in its correct sorted position
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Function to perform QuickSort using randomized pivot selection
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Choose a random pivot and move it to the end
        int randomIndex = low + rand() % (high - low + 1);
        swap(&arr[randomIndex], &arr[high]);

        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    // Initialize random seed for pivot selection
    srand(time(NULL));

    printf("Enter number of elements: ");

    // Validate input
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    int numbersToSort[n];

    // Read array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbersToSort[i]);
    }

    // Apply QuickSort algorithm
    quickSort(numbersToSort, 0, n - 1);

    // Print sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbersToSort[i]);
    }

    return 0;
}
