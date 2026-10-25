#include "m2c.h"

void func_0204a1c4(void *);
void func_02045990(void *);
void func_02045cf0(void *);

typedef struct {
    u8 v;
    u8 pad[0x23];
} Entry;

extern const Entry data_020f6bab[];

typedef struct Link {
    struct Link **head;
    struct Link *next;
} Link;

typedef struct Owner {
    u32 f0;
    Link *head;
} Owner;

typedef struct Ent {
    u8 pad0[8];
    u32 f8;
    u8 padC[0x6B7];
    u8 f6C3;
} Ent;

typedef struct Obj {
    u8 pad0[4];
    Ent *f4;
    u8 pad8[4];
    u8 fC;
    u8 fD;
    u8 padE[6];
    Link link;
} Obj;

static inline void link_set(Link *l, Owner *owner) {
    Link *cur;
    Link **new_head;
    Link **p;

    p        = l->head;
    new_head = owner != NULL ? &owner->head : NULL;
    if (p != NULL) {
        cur = *p;
        if (cur != l) {
            do {
                p   = &cur->next;
                cur = cur->next;
            } while (cur != l);
        }
        *p = l->next;
    }
    if (new_head != NULL) {
        l->head   = new_head;
        l->next   = *new_head;
        *new_head = l;
    } else {
        l->head = NULL;
        l->next = NULL;
    }
}

void func_020458a0(Obj *arg0) {
    u8 val;
    u8 idx;

    idx      = arg0->f4->f6C3;
    arg0->fD = 0;
    val      = data_020f6bab[idx].v;
    arg0->f4->f8 |= 0x200;
    func_0204a1c4((u8 *) arg0->f4 + 0x5CE);
    link_set(&arg0->link, NULL);
    switch (val) {
        case 0:
        case 2:
        case 3:
            func_02045990(arg0);
            break;
        case 1:
            func_02045cf0(arg0);
            break;
        default:
            arg0->fC |= 1;
            break;
    }
}
