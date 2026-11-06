#include "m2c.h"

enum {
    RB_RED = 1,
};

typedef struct RbNode {
    struct RbNode *left;
    struct RbNode *right;
    u32 parent_color; /* parent pointer, bit 0 = red */
} RbNode;

typedef struct RbTree {
    RbNode *root;
} RbTree;

extern void func_0205b5d8(s32 *);
extern void func_0205bcbc(void *, void **);
extern void func_0205bd38(void *, void **);

static inline RbNode *parent_of(const RbNode *n) {
    return (RbNode *) (n->parent_color & ~RB_RED);
}

static inline s32 is_red(const RbNode *n) {
    return (n->parent_color & RB_RED) ? 1 : 0;
}

static inline void set_parent(RbNode *n, const RbNode *p) {
    n->parent_color = (u32) p | (n->parent_color & RB_RED);
}

static inline void set_black(RbNode *n) {
    n->parent_color = (u32) parent_of(n);
}

static inline void set_red(RbNode *n) {
    n->parent_color |= RB_RED;
}

/* Red-black tree erase: unlinks z (splicing out y = z or its in-order
 * successor), then rebalances from x when a black node was removed, using
 * func_0205bcbc (rotate left) and func_0205bd38 (its mirror), which update
 * tree.root through its address. Returns z's in-order successor, found by
 * func_0205b5d8 before any link changes. */
RbNode *func_0205b850(RbNode *z, RbTree tree) {
    RbNode *next = z;
    RbNode *y;
    RbNode *x;
    RbNode *xp;
    RbNode *p;
    RbNode *w;
    RbNode *c;
    s32 xleft;
    s32 fix;

    func_0205b5d8((s32 *) &next);
    y = z;
    if (z->left != 0 && z->right != 0) {
        y = next;
    }
    x = y->left;
    if (x == 0) {
        x = y->right;
    }
    xp = parent_of(y);
    if (x != 0) {
        set_parent(x, xp);
    }
    p = parent_of(y);
    if (y == p->left) {
        p->left = x;
        xleft   = 1;
    } else {
        p->right = x;
        xleft    = 0;
    }
    fix = is_red(y) == 0 ? 1 : 0;
    if (y != z) {
        set_parent(y, parent_of(z));
        p = parent_of(y);
        if (z == p->left) {
            p->left = y;
        } else {
            p->right = y;
        }
        c       = z->left;
        y->left = c;
        if (c == 0) {
            xp = y;
        } else {
            set_parent(c, y);
        }
        c        = z->right;
        y->right = c;
        if (c == 0) {
            xp = y;
        } else {
            set_parent(c, y);
        }
        if (is_red(z)) {
            set_red(y);
        } else {
            set_black(y);
        }
        if (tree.root == z) {
            tree.root = y;
        }
    } else if (x == 0 && z == tree.root) {
        fix = 0;
    }
    if (fix) {
        while (x != tree.root && (x == 0 || is_red(x) == 0)) {
            if (xleft) {
                w = xp->right;
                if (is_red(w) == 1) {
                    set_black(w);
                    set_red(xp);
                    func_0205bcbc(xp, (void **) &tree.root);
                    w = xp->right;
                }
                if ((w->left == 0 || is_red(w->left) == 0) && (w->right == 0 || is_red(w->right) == 0)) {
                    set_red(w);
                    x     = xp;
                    xp    = parent_of(xp);
                    xleft = x == xp->left;
                } else {
                    if (w->right == 0 || is_red(w->right) == 0) {
                        set_black(w->left);
                        set_red(w);
                        func_0205bd38(w, (void **) &tree.root);
                        w = xp->right;
                    }
                    if (is_red(xp)) {
                        set_red(w);
                    } else {
                        set_black(w);
                    }
                    set_black(xp);
                    set_black(w->right);
                    func_0205bcbc(xp, (void **) &tree.root);
                    x = tree.root;
                }
            } else {
                w = xp->left;
                if (is_red(w) == 1) {
                    set_black(w);
                    set_red(xp);
                    func_0205bd38(xp, (void **) &tree.root);
                    w = xp->left;
                }
                if ((w->left == 0 || is_red(w->left) == 0) && (w->right == 0 || is_red(w->right) == 0)) {
                    set_red(w);
                    x     = xp;
                    xp    = parent_of(xp);
                    xleft = x == xp->left;
                } else {
                    if (w->left == 0 || is_red(w->left) == 0) {
                        set_black(w->right);
                        set_red(w);
                        func_0205bcbc(w, (void **) &tree.root);
                        w = xp->left;
                    }
                    if (is_red(xp)) {
                        set_red(w);
                    } else {
                        set_black(w);
                    }
                    set_black(xp);
                    set_black(w->left);
                    func_0205bd38(xp, (void **) &tree.root);
                    x = tree.root;
                }
            }
        }
        if (x != 0) {
            set_black(x);
        }
    }
    return next;
}
