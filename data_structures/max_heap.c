#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct dyn_arr {
    int size;
    int num_vals;
    int *arr; 
};

void heap_bottom_up(struct dyn_arr *da);
struct dyn_arr *dalloc(void);
void swap(int *arr, int loc1, int loc2);
int left(int loc);
int right(int loc);
int parent(int loc);
void resize(struct dyn_arr *da);
void insert(struct dyn_arr *da, int val);

main() {
    struct dyn_arr *da = dalloc();
    da->size = 7;
    da->num_vals = 6;
    da->arr = (int *) malloc(sizeof(int) * 7);
    int a[] = {-1, 2, 9, 7, 6, 5, 8}; 
    for (int i = 0; i < 7; ++i) {
        da->arr[i] = a[i];
    }
    heap_bottom_up(da);
    for (int i = 0; i < da->size; i++) {
        printf("%d ", da->arr[i]);
    }
}

void heap_bottom_up(struct dyn_arr *da) {
    int n = da->num_vals;
    for(int i = n / 2; i > 0; --i) {
        int k = i;
        int v = da->arr[k];
        int heap = 0;
        while (heap == 0 && 2 * k <= n) {
            int j = 2 * k;
            if (j < n)
                if (da->arr[j] < da->arr[j+1])
                    ++j;
            if (v >= da->arr[j])
                heap = 1;
            else {
                da->arr[k] = da->arr[j];
                k = j;
            }
        }
        da->arr[k] = v;
    }
}


struct dyn_arr *dalloc(void) {
    return (struct dyn_arr *) malloc(sizeof(struct dyn_arr));
}

void swap(int *arr, int loc1, int loc2) {
    int tmp = arr[loc1];
    arr[loc1] = arr[loc1];
    arr[loc2] = tmp;
}

int left(int loc) {
    return loc * 2;
}

int right(int loc) {
    return loc * 2 + 1;
}

int parent(int loc) {
    return loc / 2;
}

void resize(struct dyn_arr *da) {
    int old_size = da->size;
    int new_size = old_size * 2;
    int *new_arr = malloc(sizeof(int) * new_size);
    for (int i = 0; i < new_size; ++i) {
        if (i < old_size) {
            new_arr[i] = da->arr[i];
        } else {
            new_arr[i] = 0;
        }
    }
    da->arr = new_arr;
    da->size = new_size;
}

void insert(struct dyn_arr *da, int val) {
    if (da->num_vals >= da->size)
        resize(da);
    int loc = da->num_vals + 1;
    da->arr[loc] = val;
    while (loc > 1 && da->arr[parent(loc)] < da->arr[loc]) {
        swap(da->arr, loc, parent(loc));
        loc = parent(loc);
    }
}
