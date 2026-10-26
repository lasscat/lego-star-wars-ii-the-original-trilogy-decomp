#include "m2c.h"

typedef struct Link {
    struct Link **head;
    struct Link *next;
} Link;

typedef struct Owner {
    u32 f0;
    Link *head;
} Owner;

typedef struct Obj {
    u8 pad0[8];
    s32 f08;
    u8 pad0C[0x50];
    void **f5C;
    void **f60;
    u8 pad64[8];
    Link link;
    u32 f74;
    u32 f78;
    u8 pad7C[0x10];
    u8 f8C;
    u8 f8D;
    u8 f8E;
} Obj;

extern void func_0202d790(Link *, u8 *);
extern s32 func_02053b14(s32 *);
extern void func_0208b76c(Obj *, u8, u32);

static inline Owner *link_owner(Link *l) {
    Owner *o = (Owner *) l->head;
    if (o != NULL) {
        o = (Owner *) ((u8 *) o - 4);
    }
    return o;
}

static inline void link_unlink(Link *l) {
    Link *cur;
    Link **p = l->head;
    if (p != NULL) {
        cur = *p;
        while (cur != l) {
            p   = &cur->next;
            cur = cur->next;
        }
        *p = l->next;
    }
}

static inline void link_set(Link *l, Owner *owner) {
    Link **nh = (Link **) owner;
    if (owner != NULL) {
        nh = &owner->head;
    }
    link_unlink(l);
    if (nh != NULL) {
        l->head = nh;
        l->next = *nh;
        *nh     = l;
    } else {
        l->head = NULL;
        l->next = NULL;
    }
}

void func_0208b54c(Obj *self, u8 *arg1) {
    Link tmp;
    s32 base;
    s16 *q;
    u32 i;

    if (self->f78 & 0x14) {
        return;
    }
    if (arg1 == NULL) {
        link_set(&self->link, NULL);
        base = func_02053b14(&self->f08);
        q    = (s16 *) (base + 0x5a0);
        q -= ((u32) self->f8D >> 1) * 2;
        for (i = 0; i < self->f8D; i++) {
            q[0]    = 0x40;
            q[1]    = 0x40;
            q[0x20] = 0x40;
            q[0x21] = 0x40;
            q += 2;
        }
        if (self->f5C != NULL) {
            ((void (*)(void *))(*(void ***) self->f5C)[1])(self->f5C);
        }
        self->f5C = NULL;
        if (self->f60 != NULL) {
            ((void (*)(void *))(*(void ***) self->f60)[1])(self->f60);
        }
        self->f60 = NULL;
        self->f78 &= ~8;
    } else {
        func_0202d790(&tmp, arg1);
        link_set(&self->link, link_owner(&tmp));
        link_unlink(&tmp);
        self->f8D = *(s16 *) ((u8 *) link_owner(&self->link) + 0x6b8);
        self->f8C = 0xff;
        self->f78 |= 8;
        func_0208b76c(self, arg1[0x6bb], 1);
    }
    self->f8E = 0xff;
    self->f8C = 0xff;
}
