#include "m2c.h"

/* A 2 byte aggregate passed by value. mwccarm copies such a struct through
 * the outgoing argument area (below sp), which is the
 * "sub rX, sp, #4 / strh / ldr" sequence of the original code. A plain u16
 * argument is passed in a register without that copy. */
typedef struct {
    u16 v;
} H;

/* One key frame of the blend: a 6 byte record (the value plus four weights). */
typedef struct {
    u16 v;
    volatile u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
} Key;

/* The animation object the keys are computed from (its value is published
 * through the word at offset 0xca). */
typedef struct {
    u8 pad[0xca];
    u16 fca;
} Target;

typedef struct {
    u8 pad0[4];
    Target *f4;
    u8 pad8[0x10];
    volatile u16 f18;
    u8 pad1a[2];
    u8 f1c;
    u8 f1d;
    u8 f1e;
    u8 pad1f[0x35];
    u16 f54;
    volatile u16 f56;
} Obj;

extern void func_020344f0(Obj *, s32);
extern void func_02030038(Obj *);
extern void func_0202ff38(Obj *);
extern void func_0202732c(void *);
extern void func_02027470(void *, Target *, H);
extern void func_02027348(void *, void *);
extern void func_020278ac(void *, Target *);
extern void func_02027388(void *, void *, void *, s32);
extern void func_02030540(Obj *, u8, H);
extern const u32 data_020ed284[12];

void func_02034e24(Obj *this) {
    Key k2c, k26, k20, k1a, k14, ke;
    u8 w[2];
    volatile H vA, v8, v6, v4, v2, v0;

    func_020344f0(this, 0);
    if (this->f1e & 2) {
        func_02030038(this);
        return;
    }
    this->f56 = this->f56 + 1;
    if (this->f56 >= this->f54) {
        func_0202ff38(this);
        this->f56 = 0;
        return;
    }
    w[1] = ((const u8 *) data_020ed284)[3];
    w[0] = ((const u8 *) data_020ed284)[2];
    func_0202732c(&k26);
    func_0202732c(&k2c);
    func_0202732c(&k20);
    if (this->f1c) {
        v0.v = this->f18;
    } else {
        H t;
        t.v  = this->f18;
        vA.v = 0x8000;
        v8.v = t.v + 0x8000;
        t.v  = v8.v;
        v4.v = 0x8000;
        v0.v = t.v;
    }
    func_02027470(&k1a, this->f4, v0);
    func_02027348(&k26, &k1a);
    func_020278ac(&k14, this->f4);
    func_02027348(&k2c, &k14);
    func_02027388(&ke, &k26, w, 2);
    func_02027348(&k20, &ke);
    v2.v = k20.v;
    v6.v = this->f4->fca + k20.v;
    func_02030540(this, k20.f2, v6);
}
