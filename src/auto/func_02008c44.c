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
    s8 f24[4];
    s32 b0;
    s32 b1;
    s32 b2;
} Obj;

extern M2C_UNK data_020fcd18;
extern M2C_UNK data_020fe438;
extern s32 data_020ff9b4[3];

void func_0200af88(s8 *arg0, s8 arg1);
void func_0204c594(Obj *o, Vec3 *src);
void func_0200a070(void *out, Obj *a1, Obj *a2, Obj *a3);
void func_0200a254(void *out, Obj *a1, Obj *a2, Obj *a3);
void func_0200a158(void *out, Obj *a1, Obj *a2, Obj *a3);
void func_0200a3fc(void *out, Obj *a1, Obj *a2, Obj *a3);

void func_02008c44(Vec3 *out, Obj *a1, Obj *a2, Obj *a3) {
    Obj o1;
    Vec3 v1;
    Obj o2;
    Vec3 v2;
    s32 sx;
    s32 sy;
    s32 sz;
    switch (a1->f24[1]) {
        case 0:
            switch (a2->f24[1]) {
                case 0:
                    func_0200a070(out, a1, a2, a3);
                    return;
                case 3:
                case 5:
                case 11:
                    break;
            }
            break;
        case 3:
            switch (a2->f24[1]) {
                case 0:
                    break;
                case 3:
                    func_0200a254(out, a1, a2, a3);
                    return;
                case 5:
                    o1.vptr = &data_020fcd18;
                    o1.p0   = 0;
                    o1.p1   = 0;
                    o1.p2   = 0;
                    o1.f10  = 0;
                    o1.a0   = 0;
                    o1.a1   = 0;
                    o1.a2   = 0;
                    o1.sum  = 0;
                    func_0200af88((s8 *) &o1.f24[0], -1);
                    o1.f24[2] = 0;
                    o1.vptr   = &data_020fe438;
                    o1.b0     = 0;
                    o1.b1     = 0;
                    o1.b2     = 0;
                    o1.f24[1] = 5;
                    if (&o1.p0 != &a1->p0) {
                        o1.p0 = a1->p0;
                        o1.p1 = a1->p1;
                        o1.p2 = a1->p2;
                    }
                    sx   = a1->b1;
                    sy   = a1->b0;
                    sz   = a1->b1;
                    v1.x = sx;
                    v1.y = sy;
                    v1.z = sz;
                    func_0204c594(&o1, &v1);
                    func_0200a158(out, &o1, a2, a3);
                    return;
                case 11:
                    func_0200a3fc(out, a2, a1, a3);
                    return;
            }
            break;
        case 5:
            switch (a2->f24[1]) {
                case 0:
                    break;
                case 3:
                    o2.vptr = &data_020fcd18;
                    o2.p0   = 0;
                    o2.p1   = 0;
                    o2.p2   = 0;
                    o2.f10  = 0;
                    o2.a0   = 0;
                    o2.a1   = 0;
                    o2.a2   = 0;
                    o2.sum  = 0;
                    func_0200af88((s8 *) &o2.f24[0], -1);
                    o2.f24[2] = 0;
                    o2.vptr   = &data_020fe438;
                    o2.b0     = 0;
                    o2.b1     = 0;
                    o2.b2     = 0;
                    o2.f24[1] = 5;
                    if (&o2.p0 != &a2->p0) {
                        o2.p0 = a2->p0;
                        o2.p1 = a2->p1;
                        o2.p2 = a2->p2;
                    }
                    sx   = a2->b1;
                    sy   = a2->b0;
                    sz   = a2->b1;
                    v2.x = sx;
                    v2.y = sy;
                    v2.z = sz;
                    func_0204c594(&o2, &v2);
                    func_0200a158(out, a1, &o2, a3);
                    return;
                case 5:
                    func_0200a158(out, a1, a2, a3);
                    return;
                case 11:
                    break;
            }
            break;
        case 11:
            switch (a2->f24[1]) {
                case 0:
                    break;
                case 3:
                    func_0200a3fc(out, a1, a2, a3);
                    return;
                case 5:
                case 11:
                    break;
            }
            break;
    }
    out->x = data_020ff9b4[0];
    out->y = data_020ff9b4[1];
    out->z = data_020ff9b4[2];
}
