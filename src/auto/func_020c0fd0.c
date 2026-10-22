#include "m2c.h"

typedef struct Node Node;

struct Node {
    u32 unk0;
    u32 unk4;
    u32 id;
    u32 f0c;
    u32 f10;
    u8 f14;
    u8 pad[0x6c - 0x15];
    Node *next;
    Node *prev;
};

typedef struct {
    u8 pad[0x7b4];
    u32 count;
    Node *head;
    Node *tail;
    Node *free;
} List;

extern void func_020c0950(Node *node, u32 arg);

void *func_020c0fd0(List *list, u32 id, u32 arg2, u8 arg3) {
    Node *node = (list->count != 0) ? list->head : list->tail;
    Node *tail = list->tail;

    while (node != tail) {
        if (id == node->id) {
            goto found;
        }
        node = node->next;
    }
    node = 0;
found:
    if (node != 0) {
        return node;
    }
    node       = list->free;
    list->free = node->next;
    if (tail->prev != 0) {
        tail->prev->next = node;
    }
    node->prev = tail->prev;
    node->next = tail;
    tail->prev = node;
    if (tail == list->head || list->count == 0) {
        node->prev = list->tail;
        list->head = node;
    }
    list->count++;
    node->id  = id;
    node->f14 = arg3;
    node->f0c = 0;
    node->f10 = 0;
    func_020c0950(node, arg2);
    return node;
}
