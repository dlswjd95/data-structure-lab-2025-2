#include <stdio.h>

void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

int main() {
    int arr[] = { 5, 2, 9, 1, 5, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, size - 1);

    printf("정렬된 배열: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (1) {
        while (left <= right && arr[left] <= pivot) left++;
        while (left <= right && arr[right] >= pivot) right--;

        if (left > right) break;

        swap(&arr[left], &arr[right]);
    }

    swap(&arr[low], &arr[right]);
    return right;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
