#include "m2c.h"

enum {
    RB_RED = 1,
};

typedef struct RbNode {
    struct RbNode *left;
    struct RbNode *right;
    u32 parent_color; /* parent pointer, bit 0 = red */
} RbNode;

extern void func_0205bcbc(void *, void **);
extern void func_0205bd38(void *, void **);

static inline RbNode *parent_of(RbNode *n) {
    return (RbNode *) (n->parent_color & ~RB_RED);
}

static inline s32 is_red(RbNode *n) {
    return (n->parent_color & RB_RED) ? 1 : 0;
}

/* Red-black tree insert fixup: x is the newly inserted node, root is the tree
   root (passed by address to the rotations func_0205bcbc / func_0205bd38). */
void func_0205b644(RbNode *x, RbNode *root, ...) {
    RbNode *p;
    RbNode *g;
    RbNode *u;

    x->parent_color |= RB_RED;
    // FAKE: no-op re-read of root through its address keeps the loop test's root load separate from the final one
    while (x != *(RbNode **) &root && is_red(parent_of(x)) == 1) {
        p = parent_of(x);
        g = parent_of(p);
        if (p == g->left) {
            u = g->right;
            if (u != 0 && is_red(u) == 1) {
                p->parent_color &= ~RB_RED;
                u->parent_color &= ~RB_RED;
                x = parent_of(parent_of(x));
                x->parent_color |= RB_RED;
            } else {
                if (x == p->right) {
                    x = p;
                    func_0205bcbc(x, (void **) &root);
                }
                parent_of(x)->parent_color &= ~RB_RED;
                parent_of(parent_of(x))->parent_color |= RB_RED;
                func_0205bd38(parent_of(parent_of(x)), (void **) &root);
            }
        } else {
            u = g->left;
            if (u != 0 && is_red(u) == 1) {
                p->parent_color &= ~RB_RED;
                u->parent_color &= ~RB_RED;
                x = parent_of(parent_of(x));
                x->parent_color |= RB_RED;
            } else {
                if (x == p->left) {
                    x = p;
                    func_0205bd38(x, (void **) &root);
                }
                parent_of(x)->parent_color &= ~RB_RED;
                parent_of(parent_of(x))->parent_color |= RB_RED;
                func_0205bcbc(parent_of(parent_of(x)), (void **) &root);
            }
        }
    }
    root->parent_color &= ~RB_RED;
}
