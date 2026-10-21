#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 f10;
    Vec3 a;
    s32 sum;
    s32 f24;
    Vec3 b;
} Obj;

void func_0204c594(Obj *o, Vec3 *src) {
    if (&o->b != src) {
        o->b.x = src->x;
        o->b.y = src->y;
        o->b.z = src->z;
    }
    if (&o->a != &o->b) {
        o->a.x = o->b.x;
        o->a.y = o->b.y;
        o->a.z = o->b.z;
    }
    {
        s32 t;
        t      = o->b.x + o->b.y;
        o->sum = t + o->b.z;
    }
}
