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

struct queue *new_queue(void);
struct node *nalloc(void);
void print_queue(struct queue *q);
void push(struct queue *q, char word[]);

main() {
    struct queue *q = new_queue();
    q->head = nalloc();
    q->head->word = "start";
    q->tail = q->head;
    print_queue(q);
    push(q, "hello");
    print_queue(q);
    return 0;
}

struct node *nalloc(void) {
    return (struct node *) malloc(sizeof(struct node));
}

struct queue *new_queue() {
    struct queue *q = malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void push(struct queue *q, char word[]) {
    if (q->head = NULL) {
        printf("HIL");
        q->head = nalloc();
        q->head->word = word;
        q->tail = q->head;
    } else {
        printf("HELLO");
        q->tail->next = nalloc();
        printf("HI");
        q->tail = q->tail->next;
        q->tail->word = word;
    }
}

void print_queue(struct queue *q) {
    if (q == NULL) {
        printf("end");
    }
    struct node *head = q->head;
    while (head != NULL) {
        printf("%s, ", head->word);
        head = head->next;
    }
}
