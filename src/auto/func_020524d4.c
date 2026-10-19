#include "m2c.h"

s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_02063d0c(s32, s32 *, s32 *, M2C_UNK, s32, s32); /* extern */

s32 func_020524d4(void *arg0) {
    s16 *p = arg0;
    s32 sp1C[3];
    s32 sp8[3];
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 temp_r0;

    c       = p[2] << 0xC;
    b       = p[1] << 0xC;
    a       = p[0] << 0xC;
    sp1C[0] = a;
    sp1C[1] = b;
    sp1C[2] = c;
    f       = ((u16 *) arg0)[6] << 0xC;
    e       = ((u16 *) arg0)[5] << 0xC;
    d       = ((u16 *) arg0)[4] << 0xC;
    sp8[0]  = d;
    sp8[1]  = e;
    sp8[2]  = f;
    temp_r0 = func_0205e80c(0x20, 3, 4);
    if (temp_r0 != 0) {
        func_02063d0c(temp_r0, sp1C, sp8, 2, (s32) M2C_FIELD(arg0, u8 *, 0xE), (s32) M2C_FIELD(arg0, u8 *, 0xF));
    }
    return 0;
}
