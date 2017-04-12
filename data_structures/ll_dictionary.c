#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    int key;
    struct node *next;
};

void print_dict(struct node *head);
void set(struct node *head, int key, int val);
int get(struct node *head, int key);
void del(struct node *head, int key);
struct node *nalloc(void);
struct node *mkdict(void);

main() {
    struct node *head = mkdict();

    for (int i = 0; i < 10; ++i) {
        set(head, i, 10*i);
        print_dict(head);
    }
    return 0;
}

void print_dict(struct node *head) {
    if (head == NULL) {
        printf(" \\0\n");
    } else {
        printf("(%d, %d), ", head->key, head->val);
        print_dict(head->next);
    }
}

struct node *mkdict(void) {
    struct node *dict = nalloc();
    dict->key = -1;
    dict->val = -1;
    return dict;
}

struct node *nalloc(void) {
    return (struct node *) malloc(sizeof(struct node));
}

void set(struct node *head, int key, int val) {
    if (head == NULL) {
        head = nalloc();
        head->key = key;
        head->val = val;
    } else if (head->key == key) {
        head->val = val;
    } else if (head->next == NULL) {
        head->next = nalloc();
        head->next->key = key;
        head->next->val = val;
    } else {
        set(head->next, key, val);
    }
}

int get(struct node *head, int key) {
    if (head == NULL) {
        printf("KEY %d NOT IN DICTIONARY", key);
        return -1;
    } else if (head->key == key) {
        return head->val;
    } else {
        return get(head->next, key);
    }
}
