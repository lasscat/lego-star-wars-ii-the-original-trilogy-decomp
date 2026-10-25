#include "m2c.h"

typedef struct {
    u16 v;
} HalfWordArg;

typedef struct {
    s32 v;
} WordArg;

extern s32 func_02017fb8(void *, void *, WordArg, HalfWordArg);
extern void func_020922f4(void *, u32, u32);
extern void func_020b95bc(s32, void *);

void func_0209289c(void *self) {
    HalfWordArg ha;
    WordArg wa;
    u32 idx1;
    u32 idx2;
    void *slot;
    s32 ready1;
    s32 ready2;

    ha.v = 0x2aaa;
    wa.v = 0x14000;
    if (func_02017fb8(((u32 *) self + M2C_FIELD(self, u8 *, 0x92d))[0x13], ((u32 *) self + M2C_FIELD(self, u8 *, 0x92c))[0x13],
                      wa, ha) == 0) {
        return;
    }
    idx1   = M2C_FIELD(self, u8 *, 0x92d);
    slot   = ((u32 *) self + idx1)[0x13];
    ready1 = (((M2C_FIELD(slot, u32 *, 8) & 0x803) == 1) & M2C_FIELD(slot, u8 *, 0x40)) != 0;
    idx2   = M2C_FIELD(self, u8 *, 0x92c);
    slot   = ((u32 *) self + idx2)[0x13];
    ready2 = (((M2C_FIELD(slot, u32 *, 8) & 0x803) == 1) & M2C_FIELD(slot, u8 *, 0x40)) != 0;
    if (ready1 == 0 || ready2 == 0) {
        return;
    }
    func_020922f4(self, idx1, idx2);
    slot = ((u32 *) self + M2C_FIELD(self, u8 *, 0x92d))[0x13];
    if (slot == 0) {
        return;
    }
    func_020b95bc(0xa8, slot);
}
