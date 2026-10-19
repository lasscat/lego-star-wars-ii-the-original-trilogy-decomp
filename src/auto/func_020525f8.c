#include "m2c.h"

s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_02063d0c(s32, s32 *, s32 *, M2C_UNK, s32, s32);

s32 func_020525f8(void *arg0) {
    s32 sp14[3];
    s32 sp8[3];
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 temp_r0;

    a       = M2C_FIELD(arg0, volatile s16 *, 4) << 0xC;
    b       = M2C_FIELD(arg0, volatile s16 *, 2) << 0xC;
    c       = M2C_FIELD(arg0, volatile s16 *, 0) << 0xC;
    sp14[0] = c;
    sp14[1] = b;
    sp14[2] = a;
    d       = M2C_FIELD(arg0, volatile u16 *, 0xA) << 0xC;
    e       = M2C_FIELD(arg0, volatile u16 *, 8) << 0xC;
    sp8[0]  = e;
    sp8[1]  = d;
    sp8[2]  = 0;
    temp_r0 = func_0205e80c(0x20, 3, 4);
    if (temp_r0 != 0) {
        func_02063d0c(temp_r0, sp14, sp8, 1, (s32) M2C_FIELD(arg0, volatile u8 *, 0xC),
                      (s32) M2C_FIELD(arg0, volatile u8 *, 0xD));
    }
    return 0;
}
