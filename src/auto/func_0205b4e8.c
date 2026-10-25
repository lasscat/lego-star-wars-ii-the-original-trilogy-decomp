#include "m2c.h"

extern void func_020e0ad4(const char *);
extern void abort(void);
extern void *func_0205e824(u32);
extern void func_0205e84c(void *);
extern void func_0205b644(void *, s32);

extern char data_020fe57c[];
extern char data_020fe560[];

typedef struct {
    u16 unk_00;
    s32 unk_04;
} Unk0205b4e8Val;

typedef struct Unk0205b4e8Node {
    struct Unk0205b4e8Node *unk_00;
    struct Unk0205b4e8Node *unk_04;
    struct Unk0205b4e8Node *unk_08;
    Unk0205b4e8Val unk_0c;
} Unk0205b4e8Node;

typedef struct {
    s32 unk_00;
    Unk0205b4e8Node *unk_04;
    Unk0205b4e8Node *unk_08;
} Unk0205b4e8Tree;

/* Scope guard that frees the new node unless it was linked in. */
typedef struct {
    u8 unk_00;
    Unk0205b4e8Node *unk_04;
    Unk0205b4e8Node *unk_08;
    Unk0205b4e8Node **unk_0c;
    Unk0205b4e8Node *unk_10;
} Unk0205b4e8Guard;

/* Destructor of the guard: frees the node if it is still held. */
// FAKE: void * parameter (a typed Unk0205b4e8Guard * lets mwcc split the guard into registers); keeps the guard in stack
// memory like the C++ destructor's this
static inline void guard_release(void *guard) {
    Unk0205b4e8Guard *g = guard;
    if (g->unk_10 != 0) {
        func_0205e84c(g->unk_10);
    }
}

Unk0205b4e8Node *func_0205b4e8(Unk0205b4e8Tree *tree, Unk0205b4e8Node *parent, s32 left, s32 first, Unk0205b4e8Val *val) {
    Unk0205b4e8Guard g;
    Unk0205b4e8Node *node;
    Unk0205b4e8Val *pv;
    Unk0205b4e8Node **pp;

    if (tree->unk_00 == -1) {
        func_020e0ad4(data_020fe57c);
        abort();
    }
    node = func_0205e824(0x14);
    if (node == 0) {
        func_020e0ad4(data_020fe560);
        abort();
    }
    g.unk_00 = 0;
    g.unk_04 = node;
    g.unk_08 = node;
    g.unk_0c = &tree->unk_04;
    g.unk_10 = node;
    pv       = &node->unk_0c;
    // FAKE: always true; the null test a C++ placement-new expression (non-throwing operator new) performs
    if (pv != 0) {
        pv->unk_00 = val->unk_00;
        pv->unk_04 = val->unk_04;
    }
    node->unk_04 = 0;
    g.unk_10     = 0;
    node->unk_00 = 0;
    pp           = &node->unk_08;
    // FAKE: always true; the null test a C++ placement-new expression (non-throwing operator new) performs
    if (pp != 0) {
        *pp = parent;
    }
    if (left != 0) {
        parent->unk_00 = node;
    } else {
        parent->unk_04 = node;
    }
    tree->unk_00 += 1;
    func_0205b644(node, (s32) tree->unk_04);
    if (first != 0) {
        tree->unk_08 = node;
    }
    guard_release(&g);
    return node;
}
