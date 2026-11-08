#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;
typedef struct {
    u16 v;
} Ang;
typedef struct {
    Ang x, y, z;
} Rot3;

typedef struct {
    u8 pad0[4];
    u8 sub[8];
    Vec3 *src;
    s32 *dst;
    u8 pad14[4];
    u16 flags;
    u8 pad1a[6];
    u8 draw[4];
} Model;

typedef struct {
    Vec3 scale;
    Rot3 rot;
    u16 rotDirty;
    Model *model;
    u8 pad18[11];
    u8 visible;
    u8 noFog;
    s8 blob;
    u16 pad26;
} Slot;

typedef struct {
    u8 pad[0x30];
    u8 b30;
    u8 b31;
    u8 b32;
    u8 pad33[5];
} Blob;

typedef struct {
    u8 pad0[0x1ae];
    u8 alpha;
    u8 pad1af[0x1bc - 0x1af];
    Slot slots[12];
    Blob blobs[10];
} Actor;

typedef struct {
    u8 pad[0x56];
    u16 v56;
} Data874;

extern Data874 data_027e0874;

void func_0200c66c(void *);
void func_02010644(void *);
void func_0200c38c(void *);
void NNS_G3dGeBufferOP_N(s32, void *, s32);
void func_01ffa6f8(void *, const void *);
s32 func_020ab958(void *);
void NNS_G3dDraw(void *);

static inline int ang_eq(const Ang *a, Ang b) {
    return a->v == b.v;
}

static inline Ang *ang_init(Ang *t, u16 v) {
    t->v = v;
    return t;
}

static inline Vec3 *v3_set(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

static inline int vec_ne(const Vec3 *a, const Vec3 *b) {
    int r;
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

void func_0200c440(Actor *self) {
    u32 i;
    func_0200c66c(self);
    func_02010644(self);
    func_0200c38c(self);
    for (i = 0; i < 12; i++) {
        u32 id;
        u32 f;
        u32 cmd;

        {
            s32 bi = self->slots[i].blob;
            if (bi == -1) {
                continue;
            }
            if (self->blobs[bi].b31 == 0 || self->blobs[bi].b30 == 0 || self->slots[i].model == 0 ||
                self->slots[i].visible == 0) {
                continue;
            }
            id = self->blobs[bi].b32;
        }

        NNS_G3dGeBufferOP_N(0x14, &id, 1);
        if (self->slots[i].rotDirty != 0) {
            s32 mtx[9];
            func_01ffa6f8(mtx, &self->slots[i].rot);
            NNS_G3dGeBufferOP_N(0x1a, mtx, 9);
            {
                Ang zx, zy, zz;
                int zero = ang_eq(&self->slots[i].rot.x, *ang_init(&zx, 0)) &&
                           ang_eq(&self->slots[i].rot.y, *ang_init(&zy, 0)) &&
                           ang_eq(&self->slots[i].rot.z, *ang_init(&zz, 0));
                if (zero) {
                    self->slots[i].rotDirty = 0;
                }
            }
        }
        {
            Vec3 *scale = &self->slots[i].scale;
            Vec3 one;
            if (vec_ne(scale, v3_set(&one, 0x1000, 0x1000, 0x1000))) {
                Vec3 sc;
                v3_set(&sc, scale->x, scale->y, scale->z);
                NNS_G3dGeBufferOP_N(0x1b, &sc, 3);
            }
        }
        if (self->slots[i].model->flags & 1) {
            Model *m  = self->slots[i].model;
            s32 *dst  = m->dst;
            Vec3 *src = m->src;
            dst[2]    = src->x;
            dst[6]    = src->y;
            dst[11]   = src->z;
            func_020ab958(m->sub);
        }
        f = 0x8000;
        if (self->slots[i].noFog != 0) {
            f = 0;
        }
        cmd = (data_027e0874.v56 << 24) | (f | 0x8f) | (self->alpha << 16);
        NNS_G3dGeBufferOP_N(0x29, &cmd, 1);
        NNS_G3dDraw(self->slots[i].model->draw);
    }
}
