#include "m2c.h"

extern void func_0202d790(void *, char *);
extern void func_020367b8(void *, char *);

extern s32 data_020fdbc4[];
extern s32 data_020fdf58[];

typedef struct Obj {
    volatile s32 *vptr;
    s32 f04;
    u8 f08[4];
    u8 f0c;
    u8 f0d;
    u16 f0e;
    s32 f10[2];
    s32 f18[2];
    u8 f20;
    u8 f21;
    u8 f22;
} Obj;

typedef struct {
    s32 *head;
    s32 *y;
} Pair;

s32 func_0203668c(Obj *o, s32 a1, char *a2, char *a3) {
    Pair l2;
    Pair l1;
    s32 *n;
    s32 *r1;
    s32 *q;
    s32 *h;

    o->vptr = data_020fdbc4;
    o->f04  = a1;
    o->f0c  = 0;
    o->f0d  = 0;
    o->vptr = data_020fdf58;
    func_0202d790(&l2, a2);
    n = o->f10;
    h = l2.head;
    if (h != 0) {
        n[0] = (s32) h;
        n[1] = *h;
        *h   = (s32) n;
    } else {
        n[0] = 0;
        n[1] = 0;
    }
    r1 = l2.head;
    if (l2.head != 0) {
        q = *l2.head;
        if (q != (s32 *) &l2.head) {
            do {
                r1 = (s32 *) ((u8 *) q + 4);
                q  = *(s32 *) ((u8 *) q + 4);
            } while (q != (s32 *) &l2.head);
        }
        *r1 = (s32) l2.y;
    }
    func_020367b8(&l1, a3);
    n = o->f18;
    h = l1.head;
    if (h != 0) {
        n[0] = (s32) h;
        n[1] = *h;
        *h   = (s32) n;
    } else {
        n[0] = 0;
        n[1] = 0;
    }
    r1 = l1.head;
    if (l1.head != 0) {
        q = *l1.head;
        if (q != (s32 *) &l1.head) {
            do {
                r1 = (s32 *) ((u8 *) q + 4);
                q  = *(s32 *) ((u8 *) q + 4);
            } while (q != (s32 *) &l1.head);
        }
        *r1 = (s32) l1.y;
    }
    o->f20 = 0;
    o->f21 = 0;
    o->f22 = 0;
    return (s32) o;
}
