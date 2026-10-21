/* Reconstructed from USA ARM9 at 0x0204f014 (472 bytes).
 *
 * Fills the result object: clears it, computes a world position through
 * func_0204da60, optionally offsets it by an attachment node, asks
 * func_01ff9f20 for the visible area and finally copies the result of
 * func_0204ec14 back into the object.
 */
#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct {
    V3 a;
    s32 b;
    s32 c;
    s32 d;
    V3 e;
    s32 f;
} Big;

typedef struct {
    u8 pad[0x26];
    u8 f26;
} Node;

typedef struct {
    u8 pad[0x20];
    Node *f20;
    u8 pad2[0x1C];
    u8 f40;
    u8 f41;
    u8 pad3[0x12];
    u8 *f54;
} A1;

typedef struct {
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 a4;
    s32 a5;
    s32 a6;
} S7;

extern void func_0204da60(V3 *, s32, s32);
extern void func_0204ec14(Big *, A1 *, s32, V3 *, s32, s32, s32, s32, s32, s32);
extern void func_01ff9f20(A1 *, Node *, V3 *, S7 *);

void func_0204f014(Big *out, A1 *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9) {
    V3 v;
    S7 s;
    Big tmp;
    u8 *p;
    s32 flag;

    out->a.x = 0;
    out->a.y = 0;
    out->a.z = 0;
    out->b   = 0;
    out->c   = 0;
    out->d   = 0;
    out->e.x = 0;
    out->e.y = 0;
    out->e.z = 0;
    out->f   = 0;

    func_0204da60(&v, a3, a5);

    flag = 0;
    if (a1->f40 != 0 && a1->f41 != 0) {
        p = a1->f54;
        if (p != 0) {
            p -= 4;
        }
        if (p != 0) {
            flag = 1;
        }
    }
    if (flag != 0) {
        p = a1->f54;
        if (p != 0) {
            p -= 4;
        }
        v.x += M2C_FIELD(p, s32 *, 0x78);
        v.y += M2C_FIELD(p, s32 *, 0x7c);
        v.z += M2C_FIELD(p, s32 *, 0x80);
    }

    s.a0 = 0;
    s.a1 = 0;
    s.a2 = 0;
    s.a3 = 0;
    s.a4 = 0x2000;
    s.a5 = 0;
    s.a6 = 0;

    if (a1->f20 != 0 && a1->f20->f26 != 0) {
        func_01ff9f20(a1, a1->f20, &v, &s);
    }

    if (s.a4 <= 0x1000) {
        out->f = s.a6;
        return;
    }

    func_0204ec14(&tmp, a1, a2, &v, a4, a5, a6, a7, a8, a9);

    if ((s32 *) out != (s32 *) &tmp.a) {
        out->a.x = tmp.a.x;
        out->a.y = tmp.a.y;
        out->a.z = tmp.a.z;
    }
    out->b = tmp.b;
    out->c = tmp.c;
    out->d = tmp.d;
    if ((s32 *) &out->e != (s32 *) &tmp.e) {
        out->e.x = tmp.e.x;
        out->e.y = tmp.e.y;
        out->e.z = tmp.e.z;
    }
    out->f = tmp.f;
}
