#include <stdio.h>
#include <stdlib.h>

struct tree {
    int val;
    struct tree *left;
    struct tree *right;
};

struct tree *talloc(void);
void print_tree(struct tree *tree, int carryover);
struct tree *left(struct tree *tree);
struct tree *right(struct tree *tree);
void insert(struct tree *tree, int val);
char *repeat(char *str, int times);

main() {
    struct tree *t = talloc();
    t->val = 5;
    
    int arr[7] = {4,6,7,1,9,8,3};

    for (int i = 0; i < 7; ++i)
        insert(t, arr[i]);

    print_tree(t, 0);
}

char *repeat(char *str, int times) {
    int len = 0;
    while (str[len] != '\0')
        ++len;
    static char* repeated;
    repeated = malloc(len * times * sizeof(char));
    for (int i = 0; i < len * times; ++i)
        repeated[i] = str[i % len];
    return repeated;
}

struct tree *talloc(void) {
    return (struct tree *) malloc(sizeof(struct tree));
}

struct tree *left(struct tree *tree) {
    return tree->left;
}

struct tree *right(struct tree *tree) {
    return tree->right;
}

void print_tree(struct tree *tree, int carryover) {
    if (tree == NULL) {
        printf("%s", repeat("\t", carryover));
        printf("\\0\n");
    } else {
        printf("%s", repeat("\t", carryover));
        printf("NODE: %d\n", tree->val);
        printf("%s", repeat("\t", carryover+1));
        printf("LEFT: \n");
        print_tree(tree->left, carryover+1);
        printf("%s", repeat("\t", carryover+1));
        printf("RIGHT: \n");
        print_tree(tree->right, carryover+1);
    }
}

void insert(struct tree *tree, int val) {
    if (val < tree->val) {
        if (right(tree) != NULL) {
            insert(tree->right, val);
        } else {
            struct tree *right = talloc();
            right->val = val;
            tree->right = right;
        }
    } else if (val > tree->val) {
        if (left(tree) != NULL) {
            insert(tree->left, val);
        } else {
            struct tree *left = talloc();
            left->val = val;
            tree->left = left;
        }
    }
}
