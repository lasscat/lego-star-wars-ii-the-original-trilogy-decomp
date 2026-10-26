#include "m2c.h"

void func_0202958c(void *, void *);                         /* extern */
void func_0202d044(void *, void *);                 /* extern */
void func_0202c800(void *, void *);                 /* extern */
void func_01ff90a8(void *);                         /* extern */

typedef struct Node {
    u8 pad0[8];
    struct Node *next;
} Node;

typedef struct Flags {
    u8 pad0[8];
    s32 flags;
} Flags;

typedef struct Vt {
    void *slots[3];
    void (*slot3)(void *);
} Vt;

typedef struct Obj2 {
    Vt *vt;
    u8 pad[8];
} Obj2;

typedef struct Obj {
    u8 pad0[4];
    u8 *link;
    u8 pad8[0x10];
    Obj2 *child18;
    Obj2 *child1c;
    Flags *info;
    void *x24;
    u8 x28[0x8e];
    u8 b6;
} Obj;

enum {
    INFO_KIND_MASK = 0x803,  /* bits tested to pick the extension-teardown path */
    INFO_KIND_EXT  = 0x1,     /* value of those bits for that path */
    INFO_NO_NOTIFY = 0x800,  /* suppresses the final notify call */
};

/* Link at +4 of a node points 4 bytes past the node start; NULL stays NULL. */
static inline Node *link_to_node(u8 *link) {
    if (link != NULL) {
        link -= 4;
    }
    return (Node *) link;
}

/* Tears down an object: releases its extension, notifies its child (slot 3), then
 * either walks to the last node of its linked list and cleans up, or notifies the
 * second child. Name guessed from callers. */
void func_0202c218(Obj *obj) {
    Node *node;
    Node *next;

    if ((obj->info->flags & INFO_KIND_MASK) == INFO_KIND_EXT) {
        if (obj->b6 != 0) {
            func_0202958c(&obj->x28, obj->info);
        }
        if (obj->x24 != NULL) {
            func_0202d044(obj->x24, obj->info);
        }
    }
    if (obj->child18 != NULL) {
        obj->child18->vt->slot3(obj->child18);
    }
    node = link_to_node(obj->link);
    if (node != NULL) {
        next = node->next;
        while (next != NULL) {
            node = link_to_node((u8 *) next);
            next = node->next;
        }
        func_0202c800(obj, node);
        func_01ff90a8(obj);
        return;
    }
    if ((obj->info->flags & INFO_NO_NOTIFY) != INFO_NO_NOTIFY && obj->child1c != NULL && ((u8 *) obj->child1c)[0xa] != 0) {
        obj->child1c->vt->slot3(obj->child1c);
    }
}
