#include<stdio.h>

int partition(int arr[], int lo, int hi) {
    int pivot = arr[lo];  // pivot is the first element
    int first = lo;
    int last = hi;
    int temp;

    while(first < last) {
        // Find an element greater than the pivot
        while(arr[first] <= pivot && first < hi) {
            first++;
        }
        // Find an element smaller than or equal to the pivot
        while(arr[last] > pivot) {
            last--;
        }

        // Swap if first < last
        if(first < last) {
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
    if(lo < hi) {
        // Partition the array and get the pivot index
        int pivot = partition(arr, lo, hi);

        // Recursively sort the left and right parts
        quicksort(arr, lo, pivot - 1);  // Left part
        quicksort(arr, pivot + 1, hi);  // Right part
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 11, 4, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sort: ");
    display(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Array after sort: ");
    display(arr, n);

    return 0;
}