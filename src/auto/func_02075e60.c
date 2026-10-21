#include "m2c.h"

extern s32 func_0201b318(s32 *p, s32 v);
extern s32 FX_Sqrt(s32 x);
extern s32 func_020aaeb4(void);
extern void func_020a0eb0(void *dst, void *src);

typedef struct {
    u8 f0 : 2;
    u8 flagB : 1;
    u8 f1 : 1;
    u8 flagA : 1;
    u8 f2 : 3;
    u8 pad2[41];
    u16 v42;
    u16 v44;
} Global;

typedef struct Quad {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Quad;

typedef struct Object {
    void *vptr;
    u32 pad[2];
    s32 *items[4];
    u32 f1c;
    u32 f20;
    u8 f24;
} Object;

extern Global data_021044a4;

void func_02075e60(Object *obj) {
    s32 i;
    s32 a;
    s32 b;
    s32 d2;
    s32 d1;
    s32 v;
    s64 p;
    s64 q;
    u32 sum;
    u16 g42;
    s32 hi;
    u16 g44;
    Quad q4;

    for (i = 0; i < 4; i++) {
        func_0201b318(obj->items[i], 0);
    }
    if (data_021044a4.flagA) {
        obj->f1c = (u32) data_021044a4.v42 << 12;
        obj->f20 = (u32) data_021044a4.v44 << 12;
        a        = 0x7f000 - (s32) obj->f1c;
        b        = 0x54000 - (s32) obj->f20;
        p        = (s64) a * a;
        q        = (s64) b * b;
        sum      = (u32) ((p + 0x800) >> 12) + (u32) ((q + 0x800) >> 12);
        q4.a     = sum;
        q4.b     = sum;
        v        = FX_Sqrt(sum);
        if (v < 0x30000) {
            obj->f24 = 1;
        }
        return;
    } else if (data_021044a4.flagB) {
        if (obj->f24 == 0) {
            return;
        }
        g44 = data_021044a4.v44;
        g42 = data_021044a4.v42;
        hi  = (s32) ((u32) g44 << 12);
        if (hi >= 0x84000) {
            hi = 0x84000;
        } else if (hi <= 0x24000) {
            hi = 0x24000;
        }
        d2 = hi - (s32) obj->f20;
        d1 = ((s32) g42 << 12) - (s32) obj->f1c;
        if (d1 > 0) {
            func_0201b318(obj->items[3], 1);
        }
        if (d1 < 0) {
            func_0201b318(obj->items[2], 1);
        }
        if (d2 < 0) {
            func_0201b318(obj->items[0], 1);
        }
        if (d2 > 0) {
            func_0201b318(obj->items[1], 1);
        }
        q4.c = d1;
        q4.d = d2;
        func_020a0eb0(func_020aaeb4(), &q4.c);
        return;
    } else {
        obj->f24 = 0;
        return;
    }
}
