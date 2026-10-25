#include "m2c.h"

struct Inner {
    u8 pad0[0x40];
    u8 flag40;
    u8 pad41[0x23];
    s32 val64;
};

struct Obj {
    u8 pad0[4];
    Inner *inner;
    u8 pad8[5];
    u8 flagD;
    u8 pad0E[8];
    u8 kind16;
    u8 pad17[4];
    u8 flag1B;
};

extern "C" void func_02007f24(s32 *, double);

extern "C" void func_02047008(Obj *obj, s32 arg1) {
    if (arg1 == 0) {
        return;
    }
    obj->flag1B = 0;
    if (obj->kind16 == 14 || obj->kind16 == 8) {
        s32 b, a;
        obj->inner->flag40 = 0;
        func_02007f24(&a, 1.4);
        func_02007f24(&b, 1.55);
        s32 *pb = &b;
        if (pb) { // FAKE: always-true null test keeps &b in a register (unfolded add/ldr [r0])
            obj->inner->val64 = (s32) (((s64) *pb * a + 0x800) >> 12);
        }
        obj->flagD = 1;
    } else {
        s32 c;
        func_02007f24(&c, 1.55);
        obj->inner->val64 = c;
    }
}
