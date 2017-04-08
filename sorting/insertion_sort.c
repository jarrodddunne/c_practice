#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int data[], int size);
void swap(int data[], int i, int j);

main() {
    int SIZE = 100000;
    int MAX_VAL = 1000000;
    int data[SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; ++i) {
        data[i] = rand() % MAX_VAL;
    }
    insertion_sort(data, SIZE);
    for (int i = 0; i < SIZE; ++i)
        printf("%d\n", data[i]);
    return 0;
} 

void swap(int data[], int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

void insertion_sort(int data[], int size) {
    for (int start  = 0; start < size - 1; ++start) {
        int min_loc = start;
        for (int loc = start; loc < size; ++loc)
            if (data[loc] < data[min_loc])
                min_loc = loc;
        swap(data, start, min_loc);
    }
}
