#include <stdio.h>

void selectionSort(int arr[], int n);
int smallest(int arr[], int i, int n);
void swap(int *a, int *b);

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    selectionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


void selectionSort(int arr[], int n) {
    int pos;

    for (int i = 0; i < n - 1; i++) {
        pos = smallest(arr, i, n);
        swap(&arr[i], &arr[pos]);
        printf("Array after swapping index %d and %d: ", i, pos);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
