#include "m2c.h"

extern u32 data_020fd2c8[];

typedef struct S S;

typedef struct Obj {
    u32 *vtable;
    u8 pad004[0xD8];
    S *unkDC;
    u8 pad0E0[0xDC];
    u8 unk1BC;
    u8 pad1BD[0x5B];
    u32 unk218;
    u32 unk21C;
    u16 f220;
    u16 f222;
    u16 f224;
    u8 pad226[2];
} Obj;

typedef struct S {
    u8 pad000[0xE];
    u16 unkE;
} S;

typedef struct A3 {
    u8 pad000[0x3E];
    u16 unk3E;
} A3;

void func_02011384(void *a0, u32 a1, u32 a2, void *a3);

Obj *func_0201dbdc(Obj *this, u32 a1, u32 a2, A3 *a3) {
    S *s;
    u32 *tab;
    u8 *p;
    u8 *t;
    u16 idx;
    u16 val;
    u32 *q;
    u32 w;

    func_02011384(this, a1, a2, a3);
    this->vtable = data_020fd2c8;
    this->f220   = a3->unk3E;
    this->f222   = 0;
    this->f224   = 0;
    this->unk1BC = 0;

    s            = this->unkDC;
    tab          = (u32 *) ((u8 *) s + s->unkE);
    p            = (u8 *) s + tab[3];
    t            = p + 0x40;
    idx          = *(u16 *) (t + 6);
    val          = *(u16 *) (t + idx);
    q            = (u32 *) (t + idx + (val << 1));
    w            = q[1];
    this->unk218 = (u32) (t + w);
    this->unk21C = this->unk218 + 0x10;
    return this;
}
