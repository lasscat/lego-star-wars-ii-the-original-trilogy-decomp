#include "m2c.h"

typedef struct Vec3 {
    s32 x, y, z;
} Vec3;

typedef struct H16 {
    u16 v;
} H16;

typedef struct Rot3 {
    H16 x, y, z, w;
} Rot3;

static inline u16 cp(H16 h) {
    return h.v;
}

typedef struct Obj {
    u8 pad0[0x4C];
    void *ptrs[4];
    u8 pad1[0x68 - 0x5C];
    void *mgr;
} Obj;

typedef struct Part {
    u8 pad0[0xB0];
    Vec3 pos;
    u8 pad1[0xC8 - 0xBC];
    Rot3 rot;
    u8 pad2[0xD0 - 0xCE - 2];
    u8 rotDirty;
    u8 posDirty;
} Part;

typedef struct Src {
    s16 x, y, z, ang;
} Src;

u16 func_02090678(void *);
Src **func_02090668(void *, s32, s32);
void func_02010af0(void *);

static inline int vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline int rot_eq(const Rot3 *a, const Rot3 *b) {
    return a->x.v == cp(b->x) && a->y.v == cp(b->y) && a->z.v == cp(b->z);
}

static inline void rot_set(Rot3 *d, const Rot3 *s) {
    d->x.v = cp(s->x);
    d->y.v = cp(s->y);
    d->z.v = cp(s->z);
}

static inline void vec_from16(Vec3 *d, Src **p) {
    s32 z = (*p)->z << 12;
    s32 y = (*p)->y << 12;
    d->x  = (*p)->x << 12;
    d->z  = z;
    d->y  = y;
}

static inline void part_sync(Part *p) {
    *(u16 *) ((u8 *) p + 0x6B4) = cp(p->rot.y);
}

void func_02091310(Obj *arg0, s32 arg1) {
    u32 i;

    if (func_02090678(arg0->mgr) == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        Part *part = (Part *) arg0->ptrs[i];
        Src **sp;
        if (part == NULL) {
            continue;
        }
        sp = func_02090668(arg0->mgr, arg1, i);
        if (sp == NULL) {
            continue;
        }
        {
            s32 ang;
            Vec3 v;
            Rot3 r;
            vec_from16(&v, sp);
            if (vec_ne(&part->pos, &v)) {
                vec_set(&part->pos, &v);
                part->posDirty = 1;
            }
            ang                      = (*sp)->ang;
            *(volatile u16 *) &r.x.v = 0; // FAKE: local volatile cast blocks store-to-load forwarding of r.x
            r.y.v                    = (s32) (((s64) ang * 0x28BE60DB9391LL + 0x080000000000LL) >> 44);
            r.z.v                    = 0;
            if (!rot_eq(&r, &part->rot)) {
                rot_set(&part->rot, &r);
                part->rotDirty = 1;
            }
            part_sync(part);
            func_02010af0(part);
        }
    }
}
