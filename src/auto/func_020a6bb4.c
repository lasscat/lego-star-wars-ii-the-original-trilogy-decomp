#include "m2c.h"

typedef struct {
    s16 x, y, z;
} Pt16;

typedef struct {
    s32 x, y, z;
} Vec3;

Pt16 *func_02067b48(void *, s32);

void func_020a6bb4(void *self, void *list, Vec3 *o1, Vec3 *o2, Vec3 *o3, u8 idx1, u8 idx2) {
    Pt16 *p1;
    Pt16 *p2;
    Vec3 t;
    Vec3 u;
    Vec3 w;
    Vec3 *pt;
    Vec3 *pu;
    s32 a, b, c;
    s32 u0, u1, u2;
    s32 w0, w1, w2;

    p1 = func_02067b48(list, idx1);
    p2 = func_02067b48(list, idx2);

    c   = p1->z << 12;
    b   = p1->y << 12;
    a   = p1->x << 12;
    t.x = a;
    t.y = b;
    t.z = c;
    pt  = &t;
    if (o1 != pt) {
        o1->x = pt->x;
        o1->y = pt->y;
        o1->z = pt->z;
    }

    u2  = p2->z << 12;
    u1  = p2->y << 12;
    u0  = p2->x << 12;
    u.x = u0;
    u.y = u1;
    u.z = u2;
    pu  = &u;
    if (o2 != pu) {
        o2->x = pu->x;
        o2->y = pu->y;
        o2->z = pu->z;
    }

    w2  = o2->z - o1->z;
    w1  = o2->y - o1->y;
    w0  = o2->x - o1->x;
    w.x = w0;
    w.y = w1;
    w.z = w2;
    if (o3 != &w) {
        o3->x = w0;
        o3->y = w1;
        o3->z = w2;
    }
}
