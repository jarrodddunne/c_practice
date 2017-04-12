#include <stdio.h>
#include <stdlib.h>

struct node {
    char *word;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

struct queue *mk_queue();
struct node *nalloc(void);
void push(struct queue *q, char *word);
void print_queue(struct queue *q);
char *pop(struct queue *q);

main() {
    struct queue *q = mk_queue();
    push(q, "hi");
    push(q, "hello");
    print_queue(q);
    printf("%s\n", pop(q));
    print_queue(q);
    return 0;
}

struct node *nalloc(void) {
    return (struct node *) malloc(sizeof(struct node));
}

struct queue *mk_queue() {
    return (struct queue *) malloc(sizeof(struct queue));
}

void push(struct queue *q, char *word) {
    if (q->head == NULL) {
        q->head = nalloc();
        q->tail = q->head;
        q->head->word = word;
    } else {
        struct node *next = nalloc();
        next->word = word;
        q->tail->next = next;
        q->tail = next;
    }
}

char *pop(struct queue *q) {
    if (q->head == NULL) {
        return '\0';
    } else {
        char *ret = q->head->word;
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
        printf("%s, ", n->word);
        n = n->next;
    }
    printf("\n");
}
