#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 v;
} Scalar;

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
    s16 h0;
    s16 h1;
    s16 h2;
    s32 w;
} Obj;

typedef struct {
    s32 f00;
    s32 p0;
    s32 p1;
    s32 p2;
    s32 pad[8];
    s32 k;
} Src;

extern M2C_UNK data_020fcd18;
extern M2C_UNK data_020fe4a8;

void func_0200af88(s8 *arg0, s8 arg1);
void func_0204f760(Obj *o, Scalar s);
void func_0200940c(void *arg0, s32 *arg1, Vec3 v, Obj *o);

void func_0200a070(void *arg0, Src *arg1, Src *arg2, Vec3 *arg3) {
    Obj o;
    Scalar s;

    o.vptr = &data_020fcd18;
    o.p0   = 0;
    o.p1   = 0;
    o.p2   = 0;
    o.f10  = 0;
    o.a0   = 0;
    o.a1   = 0;
    o.a2   = 0;
    o.sum  = 0;
    func_0200af88((s8 *) &o.f24[0], -1);
    o.f24[2] = 0;
    o.vptr   = &data_020fe4a8;
    o.h0     = 0;
    o.h1     = 0;
    o.h2     = 0;
    o.w      = 0;
    o.f24[1] = 0;
    if (&o.p0 != &arg2->p0) {
        o.p0 = arg2->p0;
        o.p1 = arg2->p1;
        o.p2 = arg2->p2;
    }

    s.v = arg1->k + arg2->k;
    func_0204f760(&o, s);
    func_0200940c(arg0, &arg1->p0, *arg3, &o);
}
