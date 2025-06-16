#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int lo, int hi) {
    int pivot = arr[lo];  // pivot is the first element
    int first = lo;
    int last = hi;
    int temp;

    while (first < last) {
        // Find an element greater than the pivot
        while (arr[first] <= pivot && first < hi) {
            first++;
        }
        // Find an element smaller than or equal to the pivot
        while (arr[last] > pivot) {
            last--;
        }

        // Swap if first < last
        if (first < last) {
            temp = arr[first];
            arr[first] = arr[last];
            arr[last] = temp;
        }
    }

    // Swap the pivot with the last element
    temp = arr[lo];
    arr[lo] = arr[last];
    arr[last] = temp;

    return last;  // Return the pivot index
}

void quicksort(int arr[], int lo, int hi) {
    if (lo < hi) {
        // Partition the array and get the pivot index
        int pivot = partition(arr, lo, hi);

        // Recursively sort the left and right parts
        quicksort(arr, lo, pivot - 1);  // Left part
        quicksort(arr, pivot + 1, hi);  // Right part
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

void inputArray(int arr[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for the array
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    inputArray(arr, n);

    printf("Array before sort: ");
    display(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Array after sort: ");
    display(arr, n);

    free(arr); // Free the allocated memory
    return 0;
}

/*
Enter the number of elements in the array: 5
Enter 5 elements:
9 11 4 6 7
Array before sort:  9  11  4  6  7 
Array after sort:  4  6  7  9  11 
*/