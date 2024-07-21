#include <stdio.h>

// Function prototypes
void selectionSort(int arr[], int n);
int smallest(int arr[], int i, int n);
void swap(int *a, int *b);

int main() {
    // Sample input array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using Selection Sort
    selectionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Function to implement Selection Sort
void selectionSort(int arr[], int n) {
    int pos;

    for (int i = 0; i < n - 1; i++) {
        pos = smallest(arr, i, n);
        swap(&arr[i], &arr[pos]);
        // Debug print after each swap
        printf("Array after swapping index %d and %d: ", i, pos);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Function to find the smallest element in the array from index i to n
int smallest(int arr[], int i, int n) {
    int small = arr[i];
    int pos = i;

    for (int j = i + 1; j < n; j++) {
        if (small > arr[j]) {
            small = arr[j];
            pos = j;
        }
    }

    return pos;
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
