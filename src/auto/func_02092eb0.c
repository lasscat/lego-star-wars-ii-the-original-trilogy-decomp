#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    void *vptr;
    s32 p0;
    s32 p1;
    s32 p2;
    s32 f10;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 sum;
    u8 f24[4];
    s32 b0;
    s32 b1;
    s32 b2;
} Obj;

typedef struct {
    s32 min[3];
    s32 max[3];
} Box;

typedef struct {
    s32 a;
    s32 b;
} Res;

typedef struct {
    u8 pad[0x388];
    s32 v;
} Inner;

typedef struct {
    u8 pad[0x68];
    Inner *in;
} Owner;

extern M2C_UNK data_020fcd18;
extern M2C_UNK data_020fe438;
extern Vec3 data_020ff9b4;

void func_02007f24(s32 *, f64);
void func_0200af88(s8 *arg0, s8 arg1);
void func_0204c594(Obj *o, Vec3 *src);
void func_0204c6e8(Box *, Obj *);
void func_0204c74c(Box *, Vec3 *, Box *);
Res func_01ff9188(s32, Box *, Vec3 *);

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

enum {
    FX_SHIFT     = 12,
    FX_ROUND     = 0x800,
    OBJ_KIND_BOX = 5,
    MIN_OVERLAP  = 0x2000,
};

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + FX_ROUND) >> FX_SHIFT);
}

/* Moves the position arg1 by the displacement arg2. When the owner has a collision world
   (field 0x388 of its sub-object), a box object is built around arg1 and queried through
   func_01ff9188 with arg2; if the result is below MIN_OVERLAP the displacement is scaled by
   that result in 20.12 fixed point (FX_SHIFT) and combined into the offset applied, else arg2
   is applied as is. Without a world arg2 is added directly. */
void func_02092eb0(Owner *arg0, Vec3 *arg1, Vec3 *arg2) {
    Vec3 ext;
    Obj o;
    Box box;
    Vec3 d;
    Vec3 s;
    Vec3 w;
    Vec3 t;
    Res r;
    s32 cx;
    s32 cy;
    s32 cz;
    s32 *p;

    if (arg0->in->v != 0) {
        func_02007f24(&cz, 0.25);
        func_02007f24(&cy, 0.25);
        func_02007f24(&cx, 0.25);
        ext.x  = cx;
        ext.y  = cy;
        ext.z  = cz;
        o.vptr = &data_020fcd18;
        o.p0   = arg1->x;
        o.p1   = arg1->y;
        o.p2   = arg1->z;
        o.f10  = 0;
        o.a0   = 0;
        o.a1   = 0;
        o.a2   = 0;
        o.sum  = 0;
        func_0200af88((s8 *) &o.f24[0], -1);
        o.f24[2] = 0;
        o.vptr   = &data_020fe438;
        o.b0     = 0;
        o.b1     = 0;
        o.b2     = 0;
        o.f24[1] = OBJ_KIND_BOX;
        func_0204c594(&o, &ext);
        p = (s32 *) &box;
        do {
            *p++ = 0;
        } while (p < (s32 *) (&box + 1));
        func_0204c6e8(&box, &o);
        r   = func_01ff9188(arg0->in->v, &box, arg2);
        d.x = arg2->x;
        d.y = arg2->y;
        d.z = arg2->z;
        s.x = data_020ff9b4.x;
        s.y = data_020ff9b4.y;
        s.z = data_020ff9b4.z;
        w.x = s.x;
        w.y = s.y;
        w.z = s.z;
        if (r.b < MIN_OVERLAP) {
            t.x = fx_mul(d.x, r.b);
            t.y = fx_mul(d.y, r.b);
            t.z = fx_mul(d.z, r.b);
            vec_set(&w, &t);
            func_0204c74c(&box, &w, &box);
            s.x += w.x;
            s.y += w.y;
            s.z += w.z;
        } else {
            vec_set(&s, &d);
        }
        arg1->x += s.x;
        arg1->y += s.y;
        arg1->z += s.z;
    } else {
        arg1->x += arg2->x;
        arg1->y += arg2->y;
        arg1->z += arg2->z;
    }
}
