#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct stack {
    struct node *head;
    struct node *tail;
};

struct stack *mk_stack();
struct node *nalloc(void);
void push(struct stack *s, int val);
void print_stack(struct stack *s);
int pop(struct stack *s);

main() {
    struct stack *s = mk_stack(); 
    push(s, 10);
    push(s, 11);
    push(s, 12);
    print_stack(s);
    printf("%d\n", pop(s));
    print_stack(s);
    return 0;
}

struct node *nalloc(void) {
    return (struct node *) malloc(sizeof(struct node));
}

struct stack *mk_stack() {
    return (struct stack *) malloc(sizeof(struct stack));
}

void push(struct stack *s, int val) {
    if (s->head == NULL) {
        s->head = nalloc();
        s->tail = s->head;
        s->head->val = val;
    } else {
        struct node *next = nalloc();
        next->val = val;
        next->next = s->head;
        s->head = next;
    }
}

int pop(struct stack *s) {
    if (s->head == NULL) {
        return -1;
    } else {
        int ret = s->head->val;
        s->head = s->head->next;
        return ret;
    }
}

void print_stack(struct stack *s) {
    if (s->head == NULL) {
        printf("\\0");
    }
    struct node *n = s->head;
    while (n != NULL) {
        printf("%d, ", n->val);
        n = n->next;
    }
    printf("\n");
}
