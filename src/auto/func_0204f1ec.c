/* Reconstructed from USA ARM9 at 0x0204f1ec (432 bytes).
 *
 * Constructor-like routine: it clears the whole object, fills a small
 * control struct through func_01ff9f20, bails out when that failed and
 * otherwise copies the result of func_0204dbd8 back into the object.
 *
 * The three V3 groups are copied with the "source address != destination
 * address" test the original compiler emitted for them.
 */
#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct {
    s32 s;
    V3 v;
} Pair;

typedef struct {
    V3 a;
    s32 b;
    s32 c;
    s32 d;
    Pair p[3];
} Big;

typedef struct {
    u8 pad[0x26];
    u8 f26;
} Node;

typedef struct {
    u8 pad[0x20];
    Node *f20;
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

extern void func_01ff9f20(A1 *, Node *, s32, S7 *);
extern void func_0204dbd8(Big *, A1 *, Node *, s32, s32, s32);

void func_0204f1ec(Big *this, A1 *a1, s32 a2, s32 a3, s32 a5) {
    S7 s;
    Big tmp;
    Pair *end;
    Pair *p;

    this->a.x = 0;
    this->a.y = 0;
    this->a.z = 0;
    this->b   = 0;
    this->c   = 0;
    this->d   = 0;
    p         = this->p;
    end       = this->p + 3;
    do {
        p->s   = 0;
        p->v.x = 0;
        p->v.y = 0;
        p->v.z = 0;
        p++;
    } while (p < end);

    s.a0 = 0;
    s.a1 = 0;
    s.a2 = 0;
    s.a3 = 0;
    s.a4 = 0x2000;
    s.a5 = 0;
    s.a6 = 0;

    if (a1->f20 != 0 && a1->f20->f26 != 0) {
        func_01ff9f20(a1, a1->f20, a3, &s);
    }

    if (s.a4 <= 0x1000) {
        this->c = s.a6;
        return;
    }

    func_0204dbd8(&tmp, a1, a1->f20, a2, a3, a5);

    if ((s32 *) this != (s32 *) &tmp.a) {
        this->a.x = tmp.a.x;
        this->a.y = tmp.a.y;
        this->a.z = tmp.a.z;
    }
    this->b      = tmp.b;
    this->c      = tmp.c;
    this->d      = tmp.d;
    this->p[0].s = tmp.p[0].s;
    if ((s32 *) &this->p[0].v != (s32 *) &tmp.p[0].v) {
        this->p[0].v.x = tmp.p[0].v.x;
        this->p[0].v.y = tmp.p[0].v.y;
        this->p[0].v.z = tmp.p[0].v.z;
    }
    this->p[1].s = tmp.p[1].s;
    if ((s32 *) &this->p[1].v != (s32 *) &tmp.p[1].v) {
        this->p[1].v.x = tmp.p[1].v.x;
        this->p[1].v.y = tmp.p[1].v.y;
        this->p[1].v.z = tmp.p[1].v.z;
    }
    this->p[2].s = tmp.p[2].s;
    if ((s32 *) &this->p[2].v != (s32 *) &tmp.p[2].v) {
        this->p[2].v.x = tmp.p[2].v.x;
        this->p[2].v.y = tmp.p[2].v.y;
        this->p[2].v.z = tmp.p[2].v.z;
    }
}
