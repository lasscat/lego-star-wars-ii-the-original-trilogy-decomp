#include "m2c.h"

typedef struct Node {
    void *data;
    struct Node *next;
    struct Node *prev;
} Node;

void func_0205e068(void *arg0, void *arg1);
void func_0205e084(void *arg0, s32 arg1, void *arg2, s32 arg3);

void func_02055854(void *arg0, void *arg1) {
    Node *node;
    Node *item;
    Node *last;
    s32 count;
    Node *prev;
    Node *next;

    last  = NULL;
    count = 0;
    for (node = M2C_FIELD(arg1, Node **, 0x28); node != NULL; node = node->next) {
        item = node->data;
        prev = item->prev;
        if ((u32) prev & 0x80000000) {
            next                                 = item->next;
            *(Node **) ((u32) prev & 0x7FFFFFFF) = next;
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
        func_0205e068(arg0, item);
        last = node;
        count++;
    }
    if (M2C_FIELD(arg1, Node **, 0x28) != NULL) {
        func_0205e084(arg0, (s32) M2C_FIELD(arg1, Node **, 0x28), last, count);
        M2C_FIELD(arg1, Node **, 0x28) = NULL;
    }
}
