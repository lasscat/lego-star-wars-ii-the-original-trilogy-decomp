#include "m2c.h"

extern void func_0205e624(void *dst, s32 val, u32 len);
extern void func_020891fc(void *elem);
extern void func_02086254(void *p);

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
} Triple;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u8 f10;
    u8 f11;
    u8 f12[6];
} ElemA;

typedef struct {
    u8 x;
    u8 y;
} Pair;

typedef struct {
    u32 g00;
    u32 g04;
    u32 g08;
    Triple t;
    u16 g18;
    u16 g1a;
    u16 g1c;
    u16 g1e;
    u16 g20;
    u16 g22;
    u16 g24;
    u16 g26[5];
    Pair g30[7];
    u8 g3e;
    u8 g3f;
} ElemB;

typedef struct {
    u8 x;
    u8 y;
    u8 pad[2];
    s32 z;
} ElemC;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    s8 f8;
    u8 f9;
} ElemD;

typedef struct {
    u8 pad[4];
    u8 flag;
    u8 pad2[3];
} ElemE;

typedef struct {
    ElemA a[360];
    ElemB b[4];
    ElemC c[180];
    u8 pad1[0x0d];
    u8 f286d;
    u8 f286e;
    u8 f286f;
    u32 d[2];
    u8 pad2a[0x39];
    u8 f28b1[18];
    u8 pad2b[1];
    ElemD arr7[7];
    u8 pad4[2];
    u16 e;
    u16 f[74];
    u8 pad3[2];
    u32 g[33];
    ElemE h[8];
    u8 last;
    u8 pad5[3];
} Big;

extern Triple data_020ff9b4;
extern u8 data_02104d90;

void func_0208896c(Big *p) {
    u32 i;
    u32 i2;
    u32 i3;
    u32 i4;
    u32 i5;
    u8 j;
    u32 k;
    u8 j3;
    s32 n;

    func_0205e624(p, -1, 0x2a6c);
    p->f286d = 0;
    p->f286e = 0;
    p->f286f = 0;
    p->last  = 0;

    for (i = 0; i < 4; i++) {
        p->b[i].g24 = 0x64;
        p->b[i].g3f = 0;
        if (&p->b[i].t != &data_020ff9b4) {
            p->b[i].t.f00 = data_020ff9b4.f00;
            p->b[i].t.f04 = data_020ff9b4.f04;
            p->b[i].t.f08 = data_020ff9b4.f08;
        }
        for (j = 0; j < 7; j++) {
            p->b[i].g30[j].y = 0;
            p->b[i].g30[j].x = 0xff;
        }
        for (k = 0; k < 5; k++) {
            p->b[i].g26[k] = 0xfa;
        }
    }

    for (i2 = 0; i2 < 360; i2++) {
        func_020891fc(&p->a[i2]);
    }

    for (i3 = 0; i3 < 180; i3++) {
        p->c[i3].z = -1;
        p->c[i3].x = 0xff;
        p->c[i3].y = 0;
    }

    for (i4 = 0; i4 < 18; i4++) {
        p->f28b1[i4] = 0;
    }

    for (i5 = 0; i5 < 7; i5++) {
        p->arr7[i5].f9 = 0;
        p->arr7[i5].f2 = 0;
        p->arr7[i5].f0 = 0;
        p->arr7[i5].f8 = -1;
        p->arr7[i5].f6 = 0;
        p->arr7[i5].f4 = 0;
    }

    for (j3 = 0; j3 < 8; j3++) {
        p->h[j3].flag = 0;
    }

    func_02086254(&data_02104d90);

    p->e = 0;
    for (n = 0; n < 74; n++) {
        p->f[n] = 0xffff;
    }
    for (n = 0; n < 33; n++) {
        p->g[n] = 0;
    }
}
