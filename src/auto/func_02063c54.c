#include "m2c.h"

extern M2C_UNK func_020b9584(M2C_UNK, void *);

s32 func_02063c54(s32 *arg0, s32 index, M2C_UNK arg2) {
    u8 *flags = (u8 *) arg0 + 0x48;
    s32 v;

    if (flags[index] == 0) {
        s32 buf[3];
        buf[0]                                    = 0;
        buf[1]                                    = 0;
        buf[2]                                    = 0;
        v                                         = func_020b9584(arg2, buf);
        *(s32 *) ((u8 *) arg0 + index * 4 + 0x38) = v;
        *(u8 *) ((u8 *) arg0 + index + 0x4c)      = *(u8 *) ((u8 *) arg0 + 0x60) - 1;
    }
    flags[index]++;
    return *(s32 *) ((u8 *) arg0 + index * 4 + 0x38);
}
