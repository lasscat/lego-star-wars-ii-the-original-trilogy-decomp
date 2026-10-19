#include "m2c.h"

M2C_UNK func_0202daac(s32, u8, u8, s32 *, s32, s32, s32); /* extern */
s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */

void func_0205927c(M2C_UNK arg0, void *arg1) {
    s32 sp[3];
    s32 temp_r0;
    s32 a;
    s32 b;
    s32 c;

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
    if (temp_r0 == 0) {
        return;
    }
    func_0202daac(temp_r0, M2C_FIELD(arg1, volatile u8 *, 8), M2C_FIELD(arg1, volatile u8 *, 9), sp,
                  (s32) M2C_FIELD(arg1, volatile u8 *, 0xA), (s32) M2C_FIELD(arg1, volatile u8 *, 0xB),
                  (s32) M2C_FIELD(arg1, volatile u8 *, 0xC));
}
