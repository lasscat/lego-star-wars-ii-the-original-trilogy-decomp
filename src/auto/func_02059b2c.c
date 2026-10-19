#include "m2c.h"

s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */
M2C_UNK func_02094bf0(M2C_UNK *, s32, s32 *, u8);   /* extern */
extern M2C_UNK data_021093b0;

void func_02059b2c(M2C_UNK arg0, void *arg1) {
    s32 sp[3];
    s32 a;
    s32 b;
    s32 c;
    s32 temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, volatile u8 *, 6), M2C_FIELD(arg1, volatile u8 *, 7));
    if (temp_r0 == 0) {
        return;
    }
    a     = M2C_FIELD(arg1, volatile s16 *, 4) << 0xC;
    b     = M2C_FIELD(arg1, volatile s16 *, 2) << 0xC;
    c     = M2C_FIELD(arg1, volatile s16 *, 0) << 0xC;
    sp[0] = c;
    sp[1] = b;
    sp[2] = a;
    func_02094bf0(&data_021093b0, temp_r0 + 0xB0, sp, M2C_FIELD(arg1, volatile u8 *, 8));
}
