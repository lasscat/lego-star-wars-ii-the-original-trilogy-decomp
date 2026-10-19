#include "m2c.h"

M2C_UNK NNS_G3dDraw(void *);
M2C_UNK func_020ab958(void *);
M2C_UNK func_020c4234();

void func_020acbfc(void *arg0) {
    s32 *dst;
    s32 *src;

    func_020c4234();
    if (M2C_FIELD(arg0, u16 *, 0x18) & 1) {
        dst      = M2C_FIELD(arg0, s32 **, 0x10);
        src      = M2C_FIELD(arg0, s32 **, 0xC);
        dst[2]   = src[0];
        dst[6]   = src[1];
        dst[0xB] = src[2];
        func_020ab958((char *) arg0 + 4);
    }
    NNS_G3dDraw((char *) arg0 + 0x20);
}
