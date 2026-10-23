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

extern M2C_UNK data_020fcd18;
extern M2C_UNK data_020fe438;

void func_0200af88(s8 *arg0, s8 arg1);
void func_0204c594(Obj *o, Vec3 *src);
void func_02009770(void *arg0, Vec3 *arg1, Obj *arg2, Obj *arg3);

void func_0200a158(void *arg0, Obj *arg1, Obj *arg2, Obj *arg3) {
    Obj o;
    Vec3 v;
    s32 sx;
    s32 sy;
    s32 sz;

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
    o.vptr   = &data_020fe438;
    o.b0     = 0;
    o.b1     = 0;
    o.b2     = 0;
    o.f24[1] = 5;
    if (&o.p0 != &arg2->p0) {
        o.p0 = arg2->p0;
        o.p1 = arg2->p1;
        o.p2 = arg2->p2;
    }

    sx  = arg1->b0 + arg2->b0;
    sz  = arg1->b2 + arg2->b2;
    sy  = arg1->b1 + arg2->b1;
    v.x = sx;
    v.y = sy;
    v.z = sz;
    func_0204c594(&o, &v);
    func_02009770(arg0, (Vec3 *) &arg1->p0, arg3, &o);
}
