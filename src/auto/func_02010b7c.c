#include "m2c.h"

extern void func_0205c4d4(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);

void func_02010b7c(void *arg0, s32 arg1) {
    s32 v;
    s32 *vp;
    s32 *q;
    M2C_UNK *p;

    p = M2C_FIELD(arg0, M2C_UNK **, 0x190);
    if (p == 0) {
        return;
    }
    if (M2C_FIELD(p, u8 *, 0x2e) == 0 && arg1 == 0 && M2C_FIELD(p, u8 *, 0x2f) == 0) {
        return;
    }
    q  = M2C_FIELD(arg0, s32 **, 0x148);
    vp = &v;
    if (q != 0) {
        v = *q;
    } else {
        v = 0;
    }
    func_0205c4d4(M2C_FIELD(arg0, M2C_UNK **, 0x190), arg0, (u8 *) arg0 + 0x8c, *vp >> 12, arg1);
    M2C_FIELD(arg0, u16 *, 0x1a8) = (u16) (M2C_FIELD(arg0, u16 *, 0x1a8) | 0x200);
}
