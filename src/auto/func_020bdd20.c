#include "m2c.h"

extern void func_020bd884(s32 *obj, s32 a1, s32 a2);

void func_020bdd20(void *arg0) {
    volatile s32 v1, v2;
    s32 d, e;

    d  = M2C_FIELD(arg0, s32 *, 0x6C) - M2C_FIELD(arg0, s32 *, 0x68);
    v1 = d;
    func_020bd884((s32 *) ((u8 *) arg0 + 0x50), d, 1);
    e  = 0x10000;
    v2 = e;
    func_020bd884((s32 *) ((u8 *) arg0 + 0x48), e, 0);
    func_020bd884((s32 *) ((u8 *) arg0 + 0x58), M2C_FIELD(arg0, s32 *, 0x70), 1);
}
