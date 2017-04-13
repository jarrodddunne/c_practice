#include <stdio.h>

#define SIZE 100

int hash_func(char *word);
void set(int map[], char *word, int val);
int get(int map[], char *word);
void print_map(int map[]);

main() {
    int arr[SIZE];
    
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = 0;
    }

    set(arr, "hello", 1);
    set(arr, "how are you", 2);

    printf("hello\t%d\n", get(arr, "hello"));
    printf("how are you\t%d\n", get(arr, "how are you"));
    print_map(arr);
    return 0;
}

int hash_func(char *word) {
    int val = 0;
    int i = 0;
    while (word[i] != '\0') {
        val += (int) word[i];
        ++i;
    }  
    return val % SIZE;
}

void set(int map[], char *word, int val) {
    int hash_val = hash_func(word);
    map[hash_val] = val;
}

int get(int map[], char *word) {
    int hash_val = hash_func(word);
    return map[hash_val];
}

void print_map(int map[]) {
    for (int i = 0; i < SIZE; ++i) {
        printf("%4.0d: %4.0d\n", i, map[i]);
    }
}
