#include "m2c.h"

typedef struct {
    u16 v;
} HalfVal;

typedef struct {
    s32 v;
} UnkVal;

extern void func_0201807c(void *, void *, void *, s32);

typedef struct {
    u8 pad0[0xc];
    u16 kind;
    u8 pad1[0x84 - 0xe];
    s32 f84;
    u8 pad2[0xb0 - 0x88];
    s32 pos[3];
} Obj;

typedef struct {
    Obj *obj;
    s32 dist;
} Entry;

typedef struct {
    u8 pad0[0xb0];
    s32 pos[3];
    u8 pad1[0x6f8 - 0xbc];
    Entry ents[(0x7fc - 0x6f8) / 8];
    u32 pad2;
    u32 count;
} Ctx;

Obj *func_0200ec08(Ctx *a0, HalfVal a1, HalfVal a2, UnkVal a3, UnkVal a4) {
    u32 i;
    u32 n = a0->count;
    for (i = 0; i < n; i++) {
        Obj *obj = a0->ents[i].obj;
        s32 sq   = (s32) (((s64) a3.v * a3.v + 0x800) >> 12);
        s32 dist = a0->ents[i].dist;
        u16 ang;
        if ((obj->kind == 4 && obj->f84 == 0x10) || obj->kind != 1) {
            if (a0->ents[i].dist < sq) {
                s32 z1 = obj->pos[1];
                s32 z0 = a0->pos[1];
                if (z0 - z1 < a4.v && z1 - z0 < a4.v) {
                    s32 df;
                    func_0201807c(&ang, a0, obj->pos, 0);
                    df = (s16) (u16) (ang - a1.v);
                    if (df < 0) {
                        df = -df;
                    }
                    if ((u16) df < a2.v) {
                        return obj;
                    }
                }
            }
        }
        if (sq > dist) {
            break;
        }
    }
    return 0;
}
