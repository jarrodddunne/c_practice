#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

struct queue *mk_queue();
struct node *nalloc(void);
void push(struct queue *q, int val);
void print_queue(struct queue *q);
int pop(struct queue *q);

main() {
    struct queue *q = mk_queue();
    push(q, 10);
    push(q, 11);
    print_queue(q);
    printf("%d\n", pop(q));
    print_queue(q);
    return 0;
}

struct node *nalloc(void) {
    return (struct node *) malloc(sizeof(struct node));
}

struct queue *mk_queue() {
    return (struct queue *) malloc(sizeof(struct queue));
}

void push(struct queue *q, int val) {
    if (q->head == NULL) {
        q->head = nalloc();
        q->tail = q->head;
        q->head->val = val;
    } else {
        struct node *next = nalloc();
        next->val = val;
        q->tail->next = next;
        q->tail = next;
    }
}

int pop(struct queue *q) {
    if (q->head == NULL) {
        return -1;
    } else {
        int ret = q->head->val;
        q->head = q->head->next;
        return ret;
    }
}

void print_queue(struct queue *q) {
    if (q->head == NULL) {
        printf("\\0");
    }
    struct node *n = q->head;
    while (n != NULL) {
        printf("%d, ", n->val);
        n = n->next;
    }
}
