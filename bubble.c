#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000

void bubbleSort(int *vec, int n);
int assertSorted(int *vec, int n);

int main() {
    int *vec = malloc(sizeof(int)*N);
    int i = 0;

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        vec[i] = rand();
    }

    bubbleSort(vec, N);

    if (assertSorted(vec, N)) {
        free(vec);
        return 0;
    }

    free(vec);
    printf("something went wrong!\n");
    return 1;
}

void bubbleSort(int *vec, int n) {
    int swapped = 0;

    do {
        int i;
        swapped = 0;

        for (i = 1; i < n; i++) {
            if (vec[i-1] > vec[i]) {
                int tmp = vec[i-1];
                vec[i-1] = vec[i];
                vec[i] = tmp;
                swapped = 1;
            }
        }

    } while (swapped);
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