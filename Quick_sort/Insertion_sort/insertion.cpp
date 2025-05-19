#include <stdio.h>

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int current_value = arr[i];
        int position = i;

        while (position > 0 && arr[position - 1] > current_value) {
            arr[position] = arr[position - 1];
            position--;
        }

        arr[position] = current_value;
    }
}

int main() {
    int arr[] = { 9, 5, 1, 4, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, size);

    printf("정렬된 배열: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
