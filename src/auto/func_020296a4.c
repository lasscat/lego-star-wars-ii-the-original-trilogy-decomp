/* Action request handler: if the target object (arg1) has the flagged part and
 * is not blocked, a bit in arg2 selects a request code (2->3, 0xc->4, 0x10->6,
 * 0x20->5) stored via func_0202969c; the first three also turn the object to
 * face the position at arg0+0x64 (angle from func_020985d8 of the x/z offset).
 * Returns 1 if a request was handled, else 0. Request meaning not proved.
 */
#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    Fx qx;
    Fx qz;
} Q2;

typedef struct {
    Fx dx;
    Fx dy;
    Fx dz;
} D3;

extern s16 func_020985d8(s32, s32);
extern void func_02004b78(s32, s32);
extern void func_02007268(void *);
extern void func_0202969c(void *, s8);
extern void func_0204a5f8(void *, u16 *);
extern u32 data_02104d90;

static inline void face_to(void *obj, V3 *b, Q2 *q, D3 *l, u16 *ang) {
    s32 v0;
    s32 v1;
    s32 v2;

    v2      = b->z - M2C_FIELD(obj, s32 *, 0xb8);
    v1      = b->y - M2C_FIELD(obj, s32 *, 0xb4);
    v0      = b->x - M2C_FIELD(obj, s32 *, 0xb0);
    l->dz.v = v2;
    l->dy.v = v1;
    l->dx.v = v0;
    l->dx.v = v0; // FAKE: repeated stores keep the original store order
    l->dy.v = v1; // FAKE: repeated stores keep the original store order
    l->dz.v = v2; // FAKE: repeated stores keep the original store order
    q->qz   = l->dz;
    q->qx   = l->dx;
    *ang    = func_020985d8(l->dx.v, l->dz.v);
    func_0204a5f8((u8 *) obj + 0x5ce, ang);
}

s32 func_020296a4(V3 *arg0, void *arg1, u32 arg2) {
    struct {
        Q2 q[3];
        D3 d[3];
    } loc;
    u16 a1, a2, a3;
    void *p = M2C_FIELD(arg1, void **, 0x5f8);

    if (p == NULL || !(M2C_FIELD(p, u8 *, 0xc) & 2) || M2C_FIELD(arg1, u8 *, 0x5d6) != 0 || (data_02104d90 & 1)) {
        return 0;
    }
    if (arg2 & 2) {
        func_0202969c(arg0, 3);
        func_02004b78((s32) arg1, 0xb);
        face_to(arg1, (V3 *) ((u8 *) arg0 + 0x64), &loc.q[2], &loc.d[2], &a1);
    } else if (arg2 & 0xc) {
        func_0202969c(arg0, 4);
        func_02004b78((s32) arg1, 0xb);
        face_to(arg1, (V3 *) ((u8 *) arg0 + 0x64), &loc.q[1], &loc.d[1], &a2);
    } else if (arg2 & 0x10) {
        func_0202969c(arg0, 6);
        func_02004b78((s32) arg1, 0x2e);
        face_to(arg1, (V3 *) ((u8 *) arg0 + 0x64), &loc.q[0], &loc.d[0], &a3);
    } else if (arg2 & 0x20) {
        if (M2C_FIELD(arg1, s32 *, 0x6ac) != 0) {
            func_0202969c(arg0, 5);
            func_02007268(arg1);
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    return 1;
}
