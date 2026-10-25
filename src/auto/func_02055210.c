#include "m2c.h"

typedef struct Node {
    void *data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Link {
    Node *item;
    struct Link *next;
} Link;

typedef struct Owner {
    u8 pad[0x5c];
    Link *head;
} Owner;

extern void func_0205e068(void *pool, void *item);
extern void func_0205e084(void *pool, void *head, void *tail, s32 count);

void func_02055210(void *pool, Owner *owner) {
    Link *link;
    Link *last;
    s32 count;
    Node *item;
    Node *prev;
    Node *next;

    last  = NULL;
    count = 0;
    for (link = owner->head; link != NULL; link = link->next) {
        item = link->item;
        prev = item->prev;
        if ((u32) prev & 0x80000000) {
            next                                  = item->next;
            *(Node **) ((u32) prev & ~0x80000000) = next;
            if (next != NULL) {
                next->prev = item->prev;
            }
        } else {
            if (prev != NULL) {
                prev->next = item->next;
            }
            next = item->next;
            if (next != NULL) {
                next->prev = item->prev;
            }
        }
        func_0205e068(pool, item);
        last = link;
        count++;
    }
    if (owner->head != NULL) {
        func_0205e084(pool, owner->head, last, count);
        owner->head = NULL;
    }
}
