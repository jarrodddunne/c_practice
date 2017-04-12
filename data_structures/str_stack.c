#include <stdio.h>
#include <stdlib.h>

struct node {
    char *word;
    struct node *next;
};

struct stack {
    struct node *head;
    struct node *tail;
};

struct stack *mk_stack();
struct node *nalloc(void);
void push(struct stack *s, char *word);
void print_stack(struct stack *s);
char *pop(struct stack *s);

main() {
    struct stack *s = mk_stack();
    push(s, "hi");
    push(s, "hello");
    push(s, "how are you");
    print_stack(s);
    printf("%s\n", pop(s));
    print_stack(s);
    return 0;
}

struct node *nalloc(void) {
    return (struct node *) malloc(sizeof(struct node));
}

struct stack *mk_stack() {
    return (struct stack *) malloc(sizeof(struct stack));
}

void push(struct stack *s, char *word) {
    if (s->head == NULL) {
        s->head = nalloc();
        s->tail = s->head;
        s->head->word = word;
    } else {
        struct node *next = nalloc();
        next->word = word;
        next->next = s->head;
        s->head = next;
    }
}

char *pop(struct stack *s) {
    if (s->head == NULL) {
        return '\0';
    } else {
        char *ret = s->head->word;
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
        printf("%s, ", n->word);
        n = n->next;
    }
    printf("\n");
}
