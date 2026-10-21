#include "m2c.h"

extern void func_020bd884(s32 *obj, s32 a1, s32 a2);

void func_020bd9b0(void *arg0) {
    volatile s32 v1, v2, v3;
    s32 a;

    a  = M2C_FIELD(arg0, s32 *, 0x68) << 1;
    v1 = a;
    func_020bd884((s32 *) ((u8 *) arg0 + 0x48), a, 1);
    a  = M2C_FIELD(arg0, s32 *, 0x6C) << 1;
    v2 = a;
    func_020bd884((s32 *) ((u8 *) arg0 + 0x50), a, 1);
    a  = M2C_FIELD(arg0, s32 *, 0x70) << 1;
    v3 = a;
    func_020bd884((s32 *) ((u8 *) arg0 + 0x58), a, 1);
}
