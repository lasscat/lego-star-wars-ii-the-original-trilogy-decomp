#include "m2c.h"

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
    s32 b0;
    s32 b1;
} Obj;

extern M2C_UNK data_020fcd18;
extern M2C_UNK data_020fe484;
extern s32 data_020ff9a8;

void func_0200af88(s8 *arg0, s8 arg1);
void func_0204d27c(Obj *o, Scalar s, ...);
void func_0204d250(Obj *o, Scalar s, ...);
void func_02009b88(void *arg0, s32 *arg1, void *arg2, Obj *arg3);

void func_0200a254(void *arg0, Obj *arg1, Obj *arg2, void *arg3) {
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
    o.vptr   = &data_020fe484;
    o.b0     = data_020ff9a8;
    o.b1     = data_020ff9a8;
    o.f24[1] = 3;
    if (&o.p0 != &arg2->p0) {
        o.p0 = arg2->p0;
        o.p1 = arg2->p1;
        o.p2 = arg2->p2;
    }

    s.v = arg1->b0 + arg2->b0;
    func_0204d27c(&o, s);
    s.v = arg1->b1 + arg2->b1;
    func_0204d250(&o, s);
    func_02009b88(arg0, &arg1->p0, arg3, &o);
}
