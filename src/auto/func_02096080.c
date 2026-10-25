#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    u8 pad0[0x24];
    Vec3 pos;
    Vec3 scale;
    Vec3s rot;
    s16 padr;
    u8 f1;
    u8 f2;
} Params;

typedef struct {
    u8 pad0[0xb0];
    Vec3 pos;
    u8 pad1[0xd1 - 0xbc];
    u8 fd1;
} Spawned;

typedef struct {
    u8 pad0[0x600 + 0xf0];
    u16 f6f0;
} Entry;

typedef struct {
    u8 pad0[0x3b];
    u8 f3b;
} Owner;

typedef struct {
    u8 pad0[0x6];
    u8 f6;
    u8 pad1;
    s32 f8;
    u8 pad2[0x42 - 0xc];
    u8 f42;
    u8 pad3;
    Vec3 pos;
} Mgr;

typedef struct {
    u8 pad0[0x41];
    s8 f41;
} Slot;

typedef struct {
    u8 pad0[0xad0];
    Slot *fad0;
} Big;

extern Entry *data_02109358[];
extern u32 data_027e02a8;
extern Mgr *data_02107860;
extern Big data_02106d90;
extern u8 data_0210794c;

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

void func_02006220(Entry *, s32);
void *func_0205e80c(s32, s32, s32);
Spawned *func_020029c4(Spawned *, s32, s32, s32, Params *);
void func_0209bce0(Mgr *, s32, s32);
void func_0209bd50(Mgr *, s32);
void func_020b04f0(void *, s32, void *, s32);

void func_02096080(Owner *self, Entry *arg1) {
    Vec3 v;
    Params b;
    Spawned *sp;
    Mgr **pp;
    Mgr *m;
    Entry *e;

    e = data_02109358[self->f3b];
    if (arg1 != e) {
        return;
    }
    if ((data_027e02a8 & 0x40) == 0) {
        if (e->f6f0 != 0xea) {
            return;
        }
        func_02006220(e, 0);
        sp = func_0205e80c(0x6f8, 0, 4);
        if (sp != 0) {
            b.pos.x   = 0;
            b.pos.y   = 0;
            b.pos.z   = 0;
            b.scale.x = 0x1000;
            b.scale.y = 0x1000;
            b.scale.z = 0x1000;
            b.rot.x   = 0;
            b.rot.y   = 0;
            b.rot.z   = 0;
            b.f1      = 1;
            b.f2      = 1;
            sp        = func_020029c4(sp, 2, 0x17, 0, &b);
        }
        pp  = &data_02107860; // FAKE: cached address of the manager pointer (keeps its literal in a callee-saved register)
        m   = *pp;
        v.x = 0;
        v.y = 0;
        v.z = 0;
        vec_set(&v, &m->pos);
        if (vec_ne(&sp->pos, &v)) {
            vec_set(&sp->pos, &v);
            sp->fd1 = 1;
        }
        func_0209bce0(*pp, self->f3b, 5);
        (*pp)->f6  = 1;
        (*pp)->f8  = 0;
        (*pp)->f42 = 0;
        func_0209bd50(*pp, -1);
    } else {
        s8 c = data_02106d90.fad0->f41;
        if (c == -1) {
            return;
        }
        if (c != self->f3b) {
            return;
        }
        func_020b04f0(&data_0210794c, 0x1d, 0, 0xff);
    }
}
