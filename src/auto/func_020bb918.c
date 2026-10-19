#include "m2c.h"

extern M2C_UNK data_0210dc48;

s32 func_020bb918(u32 arg0) {
    u16 idx;
    M2C_UNK *p;

    if (arg0 != 0xFFFFFFFFU) {
        idx = arg0 & 0xFF;
        p   = (M2C_UNK *) ((s8 *) &data_0210dc48 + (idx * 0x1C));
        if ((u32) idx < 0xCU) {
            if (M2C_FIELD(p, u8 *, 1) >= 3U) {
                if (M2C_FIELD(p, s32 *, 0x10) == (arg0 >> 8)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
