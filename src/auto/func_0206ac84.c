#include "m2c.h"
extern void func_02062694(s32 *, s32, s32);
extern M2C_UNK data_020fe83c;

s32 func_0206ac84(s32 *p) {
    u8 i;
    func_02062694(p, 0, 0);
    *(s32 *) p = (s32) &data_020fe83c;
    *(u8 *) ((s8 *) p + 6) = 0;
    *(u8 *) ((s8 *) p + 7) = 0;
    *(u8 *) ((s8 *) p + 8) = 0;
    for (i = 0; i < 4; i++) {
        *(u16 *) ((s8 *) p + 0xa + i * 2) = 0;
    }
    return p;
}
