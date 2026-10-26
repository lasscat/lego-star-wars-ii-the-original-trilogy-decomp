#include "m2c.h"

typedef struct Key {
    u32 a, b, c;
} Key;
typedef struct Item {
    u8 pad_0[4];
    Key key;
    u8 pad_10[0xc];
    u8 kind;
    u8 pad_1d;
    u8 val;
    u8 pad_1f[0xe];
    u8 tag;
} Item;
typedef struct Node {
    Item *item;
    struct Node *next;
} Node;
typedef struct Owner {
    u8 pad[0x804];
    Item *sel;
} Owner;
typedef struct Globals {
    u8 pad_0[4];
    Node *list;
    u8 pad_8[0x60];
    u8 *p68;
    u8 pad_6c[0xe0];
    Owner *owners[4];
} Globals;
extern Globals data_0210930c;
typedef struct Tbl {
    u8 pad[0x430c];
    Key keys[4];
    u8 tags[4];
} Tbl;
extern Tbl data_02104d90;
extern Key data_020ff9b4;

static inline int pair_eq(const Key *x, const Key *y) {
    return x->a == y->a && x->b == y->b;
}

static inline int key_eq(const Key *x, const Key *y) {
    int r = 0;
    if (pair_eq(x, y)) {
        if (x->c == y->c) {
            r = 1;
        }
    }
    return r;
}

static inline int is_current(u8 i) {
    const Key *k = &data_02104d90.keys[i];
    if (data_02104d90.tags[i] == 0xff) {
        if (pair_eq(&data_020ff9b4, k)) {
            if (data_020ff9b4.c == k->c) {
                return 1;
            }
        }
    }
    return 0;
}

extern M2C_UNK *func_020aaeb4(void);
extern void func_0200e738(void *, void *);
extern void func_020675d8(void *, s32);

void func_02057330(void) {
    u8 i;
    for (i = 0; i < 4; i++) {
        Item *it;
        Node *n;
        Owner *owner = *(Owner **) ((u8 *) &data_0210930c + i * 4 + 0x4c);
        u8 tag;
        u32 ka, kb, kc;
        u32 *pa, *pb, *pc;
        u8 *tp;
        if (owner == NULL) {
            continue;
        }
        if (*(u8 *) ((u8 *) func_020aaeb4() + 0x4a) == 0) {
            continue;
        }
        if (*(u8 *) ((u8 *) func_020aaeb4() + 0x25c) != 0) {
            continue;
        }
        tp = (u8 *) &data_02104d90 + i + 0x433c;
        if (data_02104d90.tags[i] == 0xff) {
            if (key_eq(&data_020ff9b4, &data_02104d90.keys[i])) {
                continue;
            }
        }
        n = data_0210930c.list;
        if (n != NULL) {
            pa = (u32 *) ((u8 *) &data_02104d90 + i * 12 + 0x430c);
            pb = (u32 *) ((u8 *) &data_02104d90 + i * 12 + 0x4310);
            pc = (u32 *) ((u8 *) &data_02104d90 + i * 12 + 0x4314);
            do {
                it = n->item;
                if ((s32) it->kind >= 1 && (s32) it->kind <= 4 && *pa == it->key.a && *pb == it->key.b && *pc == it->key.c &&
                    it->tag == *tp) {
                    owner->sel = it;
                    func_0200e738(owner, it);
                    func_020675d8(*(u8 **) (*(u8 **) (*(u8 **) ((u8 *) &data_0210930c + 0x68) + 0x38c) + 4) + 0x28, it->val);
                    break;
                }
                n = n->next;
            } while (n != NULL);
        }
    }
}
