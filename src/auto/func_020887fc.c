#include "m2c.h"

/*
 * func_020887fc: initialises a large mission/task state structure.
 *
 * Layout of the structure pointed to by the argument (offsets in bytes):
 *   0x0000 360 elements of 0x18 bytes: three cleared words, a cleared word
 *          at +0x0c that is left untouched, then 0xff at +0x10 and 0 at +0x11.
 *   0x21c0 4 elements of 0x40 bytes: six cleared words, three cleared
 *          halfwords at +0x1c/+0x1e/+0x20 and seven byte pairs (0xff, 0)
 *          starting at +0x30.
 *   0x22c0 180 elements of 8 bytes: 0xff at +0 and 0 at +1.
 *   0x2870 two cleared words.
 *   0x290c one cleared halfword.
 *   0x290e 74 halfwords set to 0xffff.
 *   0x29a4 33 cleared words (cleared again after the halfword loop).
 *   0x2a28 8 elements of 8 bytes with a cleared byte at +4.
 */

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
    u32 g0c;
    u32 g10;
    u32 g14;
    u16 g18;
    u16 g1a;
    u16 g1c;
    u16 g1e;
    u16 g20;
    u8 g22[14];
    Pair g30[7];
    u8 g3e[2];
} ElemB;

typedef struct {
    u8 x;
    u8 y;
    u8 pad[6];
} ElemC;

typedef struct {
    u8 pad[4];
    u8 flag;
    u8 pad2[3];
} ElemD;

typedef struct {
    ElemA a[360];
    ElemB b[4];
    ElemC c[180];
    u8 pad1[0x10];
    u32 d[2];
    u8 pad2[0x94];
    u16 e;
    u16 f[74];
    u8 pad3[2];
    u32 g[33];
    ElemD h[8];
} Big;

extern void func_0208896c(void *);

void *func_020887fc(Big *p) {
    ElemA *qa;
    ElemB *qb;
    ElemC *qc;
    ElemD *qd;
    Pair *qp;
    int i;

    qa = p->a;
    do {
        qa->f00 = 0;
        qa->f04 = 0;
        qa->f08 = 0;
        qa->f10 = 0xff;
        qa->f11 = 0;
        qa++;
    } while (qa < p->a + 360);

    qb = p->b;
    do {
        qb->g00 = 0;
        qb->g04 = 0;
        qb->g08 = 0;
        qb->g0c = 0;
        qb->g10 = 0;
        qb->g14 = 0;
        qb->g1c = 0;
        qb->g1e = 0;
        qb->g20 = 0;
        qp      = qb->g30;
        do {
            qp->x = 0xff;
            qp->y = 0;
            qp++;
        } while (qp < qb->g30 + 7);
        qb++;
    } while (qb < p->b + 4);

    qc = p->c;
    do {
        qc->x = 0xff;
        qc->y = 0;
        qc++;
    } while (qc < p->c + 180);

    for (i = 0; i < 2; i++) {
        p->d[i] = 0;
    }

    for (i = 0; i < 33; i++) {
        p->g[i] = 0;
    }

    p->e = 0;
    for (i = 0; i < 74; i++) {
        p->f[i] = 0xffff;
    }

    for (i = 0; i < 33; i++) {
        p->g[i] = 0;
    }

    qd = p->h;
    do {
        qd->flag = 0;
        qd++;
    } while (qd < p->h + 8);

    func_0208896c(p);
    return p;
}
