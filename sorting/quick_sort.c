#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int *data, int lo, int hi);
int partition(int *data, int lo, int hi); 
void swap(int *data1, int idx1, int idx2);

main() {
    int SIZE = 100000;
    int MAX_VAL = 100000;
    int data[SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; ++i) {
        data[i] = rand() % MAX_VAL;
    }
    quick_sort(data, 0, SIZE);
    for (int i = 0; i < SIZE; ++i)
        printf("%d\n", data[i]);
    return 0;
} 

void swap(int *data, int idx1, int idx2) {
    int tmp = data[idx1];
    data[idx1] = data[idx2];
    data[idx2] = tmp;
}

int partition(int *data, int lo, int hi) {
    int pivot = data[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; ++j) {
        if (data[j] <= pivot) {
            ++i;
            swap(data, i, j);
        }
    }
    swap(data, i+1, hi);
    return i+1;
}

void quick_sort(int *data, int lo, int hi) { 
    if (lo < hi) {
        int p = partition(data, lo, hi);
        quick_sort(data, lo, p-1);
        quick_sort(data, p+1, hi);
    }
}
