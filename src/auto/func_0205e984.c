#include "m2c.h"

typedef struct {
    u8 pad[8];
    u32 f8;
    u8 pad2[0x40];
    s32 f4c;
    s32 f50;
} Obj;

typedef struct {
    Obj **f0;
    u16 pad[1];
    u16 f6;
} A0;

typedef struct {
    u8 pad[6];
    s16 f6;
    s16 f8;
    u8 fa;
    u8 fb;
} A1;

extern void *func_0205e80c(s32, s32, s32);
extern void *func_0201abbc(void *, void *);
extern void func_02060cd0(void *, u8, s32);
extern void clearDataAndInstructionCache(void *, void *);
extern void func_0201b318(void *, u8);

void func_0205e984(A0 *a0, A1 *a1, s32 a2, void *a3) {
    Obj *p;
    u8 fb;

    p = func_0205e80c(0x80, 0, 4);
    if (p) {
        p = func_0201abbc(p, a3);
    }
    a0->f0[a2] = p;
    fb         = a1->fb;
    func_02060cd0(a0->f0[a2], fb, (a0->f0[a2]->f8 & 0x80000000) ? 0 : 1);
    clearDataAndInstructionCache(a0->f0[a2], a1);
    func_0201b318(a0->f0[a2], a1->fa);
    a0->f0[a2]->f4c = a1->f6 << 12;
    a0->f0[a2]->f50 = a1->f8 << 12;
    a0->f6          = a0->f6 + 1;
}
