#include "m2c.h"

typedef struct {
    u16 v;
} H;

typedef struct {
    u16 v;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
} Key;

typedef struct {
    u8 pad[0xca];
    u16 fca;
} Target;

typedef struct {
    u8 pad0[4];
    Target *f4;
    u8 pad8[0x14];
    u8 f1c;
    u8 f1d;
    u8 f1e;
    u8 pad1f[0x35];
    u8 f54;
    u8 f55;
    u8 f56;
} Obj;

extern void func_02034978(Obj *);
extern void func_020344f0(Obj *, s32);
extern void func_02030038(Obj *);
extern void func_0202ff38(Obj *);
extern void func_02034bd0(Obj *, s32);
extern void func_02034c68(Obj *);
extern void func_0202732c(void *);
extern void func_02027348(void *, void *);
extern void func_0202765c(void *, Target *, s32, u8 *, s32, u8, u8, u8 *);
extern void func_020278ac(void *, Target *);
extern void func_02027c70(void *, Target *, s32);
extern void func_02027388(void *, void *, void *, s32);
extern void func_02030540(Obj *, u8, H);
extern const u32 data_020ed284[12];

enum {
    FLAG_SKIP_BLEND = 0x2,
    WEIGHTS_OFFSET  = 13, /* name guessed from callers */
};

/* Advances the key-frame blend one step: computes the blended key and publishes it. */
void func_02035030(Obj *this) {
    Key k44, k3e, k38;
    u8 w[3];
    Key k2e, k28, k22, k1c, k16;
    u8 flag;
    volatile H v6, v2; // FAKE: forces both stack stores of the blended value

    func_02034978(this);
    func_020344f0(this, 0);
    if (this->f1e & FLAG_SKIP_BLEND) {
        func_02030038(this);
        return;
    }
    // FAKE: volatile stores and last read steer the load/store schedule of this 3 byte copy
    ((volatile u8 *) w)[0] = ((const u8 *) data_020ed284)[WEIGHTS_OFFSET];
    ((volatile u8 *) w)[1] = ((const u8 *) data_020ed284)[WEIGHTS_OFFSET + 1];
    ((volatile u8 *) w)[2] = ((const volatile u8 *) data_020ed284)[WEIGHTS_OFFSET + 2];
    func_0202732c(&k38);
    func_0202732c(&k3e);
    func_0202732c(&k44);
    func_0202732c(&k2e);
    flag = 0;
    func_0202765c(&k28, this->f4, this->f54, &this->f55, this->f56, this->f1c, 1, &flag);
    func_02027348(&k38, &k28);
    if (flag != 0) {
        func_02034bd0(this, 1);
        func_02034c68(this);
        return;
    }
    func_020278ac(&k22, this->f4);
    func_02027348(&k3e, &k22);
    func_02027c70(&k1c, this->f4, 2);
    func_02027348(&k44, &k1c);
    func_02027388(&k16, &k38, w, 3);
    func_02027348(&k2e, &k16);
    v2.v = k2e.v;
    v6.v = this->f4->fca + k2e.v;
    func_02030540(this, *(volatile u8 *) &k2e.f2, v6); // FAKE: volatile read keeps the load after the v6 store
    if (k2e.f3 != 0) {
        func_0202ff38(this);
    }
}
