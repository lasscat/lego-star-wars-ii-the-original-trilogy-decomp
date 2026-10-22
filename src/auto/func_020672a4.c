#include "m2c.h"

extern void *func_020e4600(s32, s32, s32, s32, void *, s32);
extern void func_02067a90(void *, s32, s32);
extern void func_02067a80(void *);

typedef struct {
    u8 pad_0[8];
    u8 *f8;
    u8 pad_c[0xe];
    u16 f1a;
} ObjA;

typedef struct {
    u8 pad_0[0xc];
    u8 *f0c;
} ListA;

typedef struct {
    u8 pad_0[8];
    u16 off;
    u8 pad_a[6];
    u16 tbl[1];
} ThingA;

void func_020672a4(ObjA *a0, ListA *a1, ThingA *a2) {
    u16 count;
    u8 *p;
    u16 *tbl;
    u8 *q;
    u32 i;

    count = a0->f1a;
    if (count == 0) {
        return;
    }
    p = a1->f0c;
    if (p != 0) {
        p = (u8 *) func_020e4600((s32) p, count, 8, 0, (void *) func_02067a80, 0);
    }
    a0->f8  = p;
    a1->f0c = a1->f0c + (a0->f1a * 8 + 8);

    tbl = (u16 *) ((u8 *) a2 + 0x10 + a2->off);
    q   = (u8 *) tbl + a0->f1a * 2;
    for (i = 0; i < a0->f1a; i++) {
        func_02067a90(a0->f8 + i * 8, q, (u8 *) tbl + tbl[i]);
        q += *q + 1;
    }
}
