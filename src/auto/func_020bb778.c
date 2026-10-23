#include "m2c.h"

extern M2C_UNK data_0210dd7c;
extern M2C_UNK data_0210dc20;
extern M2C_UNK data_0210dd54;

M2C_UNK func_020bb74c(void);                        /* extern */
M2C_UNK func_020bb488(u8, s32);
s32 func_020bb36c(s32);
void func_020bb6b0(u32, s32);
M2C_UNK SND_WaitForFreeCommand(M2C_UNK);
M2C_UNK SND_StopTimer(s32, M2C_UNK, M2C_UNK, M2C_UNK);
s32 SND_GetCurrentCommandTag();

void func_020bb778(void) {
    s32 i;
    s32 mask = 0;
    s32 tag;
    u8 *e;
    u8 *f;
    u8 *g;

    func_020bb74c();
    e = (u8 *) &data_0210dd7c;
    for (i = 11; i >= 0; i--) {
        if (M2C_FIELD(e, u8 *, 1) == 3) {
            f = (u8 *) &data_0210dc20 + M2C_FIELD(e, u8 *, 0) * 28;
            if (M2C_FIELD(f, u8 *, 0x180) & 0x10) {
                mask |= 1 << M2C_FIELD(e, u8 *, 2);
                func_020bb488(M2C_FIELD(e, u8 *, 2), i | 0x20);
                M2C_FIELD(e, u8 *, 1) = 4;
            } else {
                func_020bb6b0(func_020bb36c(i), 0);
            }
        }
        e -= 28;
    }
    if (mask != 0) {
        SND_WaitForFreeCommand(1);
        SND_StopTimer(mask, 0, 0, 0);
        tag = SND_GetCurrentCommandTag();
        g   = (u8 *) &data_0210dd54;
        for (i = 11; i >= 0; i--) {
            if (mask & (1 << i)) {
                M2C_FIELD(g, s32 *, 0x40) = tag;
            }
            g -= 28;
        }
    }
}
