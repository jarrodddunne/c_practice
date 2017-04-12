#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *add(struct node *head, int n);
struct node *nalloc(void);

main() {
    struct node *head = nalloc();
    head->val = 1;

    head = add(head, 2);
    printf("%d\n", head->next->val);
    return 0;
}

struct node *nalloc(void) {
    return (struct node *) malloc(sizeof(struct node));
}

struct node *add(struct node *head, int n) {
    if (head == NULL) {
        struct node *new = nalloc();
        new->val = n;
        return new;
    } else {
        if (head->val > n) {
            struct node *next = nalloc();
            next->val = head->val;
            head->val = n;
            return next;
        } else {
            head->next = add(head->next, n);
            return head;
        }
    }
}
