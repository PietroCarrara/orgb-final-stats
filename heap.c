#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000

void swap(int *a, int *b);
void maxHeapify(int *arr, int start, int end);
void heapSort(int *arr, int len);
int assertSorted(int *vec, int n);

int main() {
    int *vec = malloc(sizeof(int)*N);
    int i = 0;

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        vec[i] = rand();
    }

    heapSort(vec, N);

    if (assertSorted(vec, N)) {
        free(vec);
        return 0;
    }

    free(vec);
    printf("something went wrong!\n");
    return 1;
}

void maxHeapify(int *arr, int start, int end) {
    int parent = start;
    int child = parent * 2 + 1;
    while (child <= end) {
        if (child + 1 <= end && arr[child] < arr[child + 1])
            child++;
        if (arr[parent] > arr[child])
            return;
        else {
            swap(&arr[parent], &arr[child]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}

void heapSort(int *arr, int len) {
    int i;
    for (i = len / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i, len - 1);
    }
    for (i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, 0, i - 1);
    }
}

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int assertSorted(int *vec, int n) {
    int i;

    for (i = 1; i < n; i++) {
        if (vec[i-1] > vec[i]) {
            printf("vec[%d] > vec[%d]  |  %d > %d\n", i-1, i, vec[i-1], vec[i]);
            return 0;
        }
    }

    return 1;
}