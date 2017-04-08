#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell_sort(int data[], int size);
void swap(int data[], int i, int j);
int decrease_gap(int gap);
void gap_sort(int data[], int start, int gap, int size);
int intpow(int base, int exp);

main() {
    int SIZE = 100000;
    int MAX_VAL = 1000000;
    int data[SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; ++i) {
        data[i] = rand() % MAX_VAL;
    }
    shell_sort(data, SIZE);
    for (int i = 0; i < SIZE; ++i)
        printf("%d\n", data[i]);
    return 0;
} 

int intpow(int base, int exp) {
    int val = 1;
    for (int i = 0; i < exp; ++i) {
        val *= base;
    }
    return val;
}

void swap(int data[], int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

int decrease_gap(int gap) {
    if (gap == 1) {
        return -1;
    } else {
        gap += 1;
        gap /= 2;
        gap -= 1;
        return gap;
    }
}

void shell_sort(int data[], int size) {
    int val = 0;
    while (intpow(2, val + 1) < size - 1) {
        val += 1;
    }
    int gap = intpow(2, val + 1); 
    while (gap >= 1) {
        for (int i = gap; i < size; i += 1) {
            int tmp = data[i];
            int j = 0;
            for (j = i; j >= gap && data[j-gap] > tmp; j -= gap) {
                data[j] = data[j-gap];
            }
            data[j] = tmp;
        }
        gap = decrease_gap(gap);
    }
}
