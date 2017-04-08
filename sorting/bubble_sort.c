#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int data[], int size);
void swap(int data[], int i, int j);

main() {
    int SIZE = 100000;
    int MAX_VAL = 1000000;
    int data[SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; ++i) {
        data[i] = rand() % MAX_VAL;
    }
    bubble_sort(data, SIZE);
    for (int i = 0; i < SIZE; ++i)
        printf("%d\n", data[i]);
    return 0;
} 

void swap(int data[], int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

void bubble_sort(int data[], int size) {
    int swaps = 1;
    while (swaps != 0) {
        swaps = 0;
        for (int i = 1; i < size; ++i) {
            if (data[i] < data[i-1]) {
                swap(data, i-1, i);
                swaps += 1;
            }
        }
    }
}
