#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int *data, int size);
void merge(int *data1, int size1, int data2[], int size2);

main() {
    int SIZE = 100000;
    int MAX_VAL = 100000;
    int data[SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; ++i) {
        data[i] = rand() % MAX_VAL;
    }
    merge_sort(data, SIZE);
    for (int i = 0; i < SIZE; ++i)
        printf("%d\n", data[i]);
    return 0;
} 

void merge(int *data1, int size1, int *data2, int size2) {
    int idx1 = 0;
    int idx2 = 0;
    int new[size1 + size2];

    while (idx1 < size1 && idx2 < size2) {
        if (data1[idx1] < data2[idx2]) {
            new[idx1+idx2] = data1[idx1];
            idx1++;
        } else {
            new[idx1+idx2] = data2[idx2];
            idx2++;
        }
    }
    while (idx1 < size1) {
        new[idx1+idx2] = data1[idx1];
        idx1++;
    }
    while (idx2 < size2) {
        new[idx1+idx2] = data2[idx2];
        idx2++;
    }
    for (int i = 0; i < size1+size2; i++) {
        data1[i] = new[i];
    }
}

void merge_sort(int *data, int size) {
    if (size < 2) {
        return;
    } else {
        int mid = size / 2;
        merge_sort(data, mid);
        merge_sort(&data[mid], size - mid);
        merge(data, mid, &data[mid], size - mid);
    }
}
