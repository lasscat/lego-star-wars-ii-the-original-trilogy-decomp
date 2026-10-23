#include "m2c.h"

typedef struct {
    u8 pad0[0x74];
    s32 *f74;
    u8 pad1[0x28];
    u16 *fa0;
    u8 pad2[0x0d];
    u8 fb1;
} Obj;

void func_0209f948(Obj *o, s32 val, ...) {
    s32 t;
    u16 v;
    u32 lim;

    *o->f74 = *(s32 *) &val;
    if (o->fa0 == 0) {
        return;
    }
    o->fb1 = 0;
    t      = *o->f74;
    v      = *(u16 *) ((u8 *) o->fa0 + (s16) o->fb1 * 6);
    lim    = (u32) (t >> 12);
    if (v >= lim) {
        return;
    }
    for (;;) {
        o->fb1++;
        v = *(u16 *) ((u8 *) o->fa0 + o->fb1 * 6);
        if (lim <= v) {
            break;
        }
    }
}
