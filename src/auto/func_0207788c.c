#include "m2c.h"

typedef struct Sprite {
    u8 pad0[8];
    u32 flags;
    u8 padC[8];
    u32 pad14 : 12;
    u32 palette : 4;
    u32 pad14b : 16;
    u8 b18;
    u8 b19;
} Sprite;

typedef struct Obj {
    u8 pad0[0xD0];
    u8 tableIdx;
    u8 padD1[0x23];
    Sprite *sprites[7];
    u8 padG[0x130 - 0x110];
    s8 ids[7];
} Obj;

typedef struct Ent {
    u8 pad0[0x53];
    u8 pal;
    u8 pad54[0x4E];
    s16 x;
    s16 y;
} Ent;

extern u32 data_020fed4c[];
extern u8 data_020ee580[];
extern u8 data_020ee2c8[];
extern u8 data_02104d90[];

void func_0201c1e4(void *, s32, s32);
s32 func_0208671c(void *, s32);
void clearDataAndInstructionCache(void *, void *);

void func_0207788c(Obj *arg0) {
    u8 *table;
    u32 i;
    s32 n;
    Ent *e;
    Sprite *spr;

    n     = 3;
    table = (u8 *) data_020fed4c[arg0->tableIdx];
    e     = (Ent *) data_020ee580;
    for (i = 0; i < 7; i++, e = (Ent *) ((u8 *) e + 12)) {
        func_0201c1e4(arg0->sprites[i], e->x, e->y);
        if (func_0208671c(data_02104d90, arg0->ids[i] + 0x16)) {
            arg0->sprites[i]->palette = e->pal;
            clearDataAndInstructionCache(arg0->sprites[i], data_020ee2c8 + 6);
            arg0->sprites[i]->flags |= 8;
            spr      = arg0->sprites[i];
            spr->b19 = spr->b18 = n;
        } else {
            arg0->sprites[i]->palette = e->pal;
            clearDataAndInstructionCache(arg0->sprites[i], table + arg0->ids[i] * 6);
            arg0->sprites[i]->flags &= ~8;
        }
    }
}
