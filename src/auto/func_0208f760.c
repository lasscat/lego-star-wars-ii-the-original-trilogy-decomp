#include "m2c.h"

typedef struct Slot {
    s32 f0;
    s32 f4[6];
    s32 f1c;
    s32 f20;
} Slot;

typedef struct Pair {
    u8 pad[4];
    u8 b4;
    u8 pad2[3];
} Pair;

typedef struct Quad {
    u8 pad[0xC];
    u8 b0;
    u8 b1;
    u8 pad2[2];
} Quad;

typedef struct Obj {
    Slot slots[25];
    s32 g384;
    s32 g388;
    s32 g38c;
    u8 blk[0x38];
    s32 g3c8;
    s32 g3cc;
    s32 g3d0;
    s32 g3d4;
    s32 g3d8[4];
    Pair pairs[8];
    Quad quads[5];
    u8 c478;
    u8 c479;
    u8 c47a;
    u8 c47b;
    u8 c47c;
    u8 pad4;
    u16 h[20];
} Obj;

extern void func_0205d6f8(void *, s32);
extern void func_0205e624(void *, s32, s32);
extern u8 func_02093fd0(s32);
extern void func_0208fd4c(void *);

Obj *func_0208f760(Obj *arg0, u8 arg1, u8 arg2) {
    Slot *p;
    Pair *q;
    Quad *r;
    u16 *h;
    u32 k;

    p = arg0->slots;
    do {
        p->f4[0] = 0;
        p->f4[1] = 0;
        p->f4[2] = 0;
        p->f4[3] = 0;
        p->f4[4] = 0;
        p->f4[5] = 0;
        p++;
    } while (p < (Slot *) &arg0->g384);
    arg0->g384 = 0;
    arg0->g388 = 0;
    arg0->g38c = 0;
    func_0205d6f8(arg0->blk, 0x10);
    arg0->g3c8 = 0;
    q          = arg0->pairs;
    do {
        q->b4 = 0;
        q++;
    } while (q < (Pair *) arg0->quads);
    r = arg0->quads;
    do {
        r->b0 = 0;
        r->b1 = 0;
        r++;
    } while (r < (Quad *) &arg0->c478);
    arg0->c478 = 0;
    arg0->c479 = arg1;
    arg0->c47a = 0x15;
    arg0->c47b = arg2;
    arg0->c47c = 0;
    h          = &arg0->h[0];
    do {
        *h = 0xFFFF;
        h += 2;
    } while (h < &arg0->h[20]);
    func_0205e624(arg0, 0, 0x384);
    for (k = 0; k < 4; k++) {
        arg0->g3d8[k] = 0;
    }
    arg0->g3cc = 0;
    arg0->g3d0 = 0;
    arg0->g3d4 = 0;
    arg0->c47a = func_02093fd0(arg0->c479);
    func_0208fd4c(arg0);
    return arg0;
}
