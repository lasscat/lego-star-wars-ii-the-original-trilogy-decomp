#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad0[0x8];
    u32 flags;
} Node;

typedef struct {
    u8 pad0[0x8];
    u32 flags;
    u8 pad1[0xa4];
    Vec3 pos;
    u8 pad2[0xd1 - 0xbc];
    u8 fd1;
    u8 pad3[0x14e - 0xd2];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} Target;

typedef struct {
    u8 pad0[0x4];
    Vec3 pos;
} Owner;

typedef struct {
    u8 pad0[0x30];
    Owner *f30;
    u8 pad34[0x7c];
    Vec3 pos;
} Holder;

typedef struct {
    u8 pad0[0x4];
    Holder *f4;
    u8 pad8[0x17];
    u8 f1f;
    u8 pad20[0x28];
    Node *f48;
    Target *f4c;
    void *f50;
} Obj;

static inline void vec_copy(Vec3 *d, const Vec3 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline int vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

void func_020b973c(void *);
void func_0202fbbc(Obj *, Node *, s32);

s32 func_020347fc(Obj *this) {
    Vec3 sp;
    Owner *own;
    Target *t;

    if (this->f4c != 0) {
        if (this->f48 != 0 && (this->f48->flags & 0x802) != 0) {
            this->f48 = 0;
        }
        if (this->f4c->b1 == 1) {
            this->f1f = 0x5a;
            this->f4c->flags |= 2;
            this->f4c = 0;
            if (this->f50 != 0) {
                func_020b973c(this->f50);
                this->f50 = 0;
            }
            func_0202fbbc(this, this->f48, 8);
        } else {
            own = this->f4->f30;
            vec_copy(&sp, &this->f4->pos);
            if (own != 0) {
                vec_set(&sp, &own->pos);
            }
            t = this->f4c;
            if (vec_ne(&t->pos, &sp)) {
                vec_set(&t->pos, &sp);
                t->fd1 = 1;
            }
            return this->f48 != 0;
        }
    }
    return 0;
}
