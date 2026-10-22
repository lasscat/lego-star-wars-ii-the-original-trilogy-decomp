#include "m2c.h"

typedef struct {
    u8 pad[8];
    u8 f8;
    u8 f9;
    u8 fA[5];
    u8 ff;
} Item;

typedef struct {
    void *f00;
    void *f04;
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    u8 f24;
    s8 f25;
    u8 f26;
    u8 f27;
    u16 f28;
    u16 f2a;
    u16 f2c;
    u8 f2e;
    u8 f2f;
    s32 f30;
} Obj;

extern void *func_0205e824(s32);
extern void func_0200af88(u8 *, s32);
extern void func_0205ca98(void *, void *, void *);
extern u32 data_020fcd18[];
extern u32 data_020fe4a8[];

void func_0205c9e4(void **a0, Item *a1, void *a2) {
    s32 idx;
    Obj *p;

    idx = a1->ff - 2;
    if (a0[idx] == 0) {
        p = func_0205e824(0x34);
        if (p) {
            p->f00 = data_020fcd18;
            p->f04 = 0;
            p->f08 = 0;
            p->f0c = 0;
            p->f10 = 0;
            p->f14 = 0;
            p->f18 = 0;
            p->f1c = 0;
            p->f20 = 0;
            func_0200af88(&p->f24, p->f20 - 1);
            p->f25 = -1;
            p->f26 = 0;
            p->f00 = data_020fe4a8;
            p->f28 = 0;
            p->f2a = 0;
            p->f2c = 0;
            p->f30 = 0;
            p->f25 = 0;
        }
        a0[idx] = p;
    }
    func_0205ca98(a0, a1, a2);
}
