#include "m2c.h"

s16 *func_02067b48(s32, M2C_UNK);                   /* extern */

void func_020a9d78(void *arg0, void *arg1, M2C_UNK arg2) {
    s16 temp_r5;
    s16 temp_r6;

    temp_r6                   = M2C_FIELD(func_02067b48(M2C_FIELD(arg1, s32 *, 0x21C), arg2), s16 *, 4);
    temp_r5                   = M2C_FIELD(func_02067b48(M2C_FIELD(arg1, s32 *, 0x21C), arg2), s16 *, 2);
    M2C_FIELD(arg0, s32 *, 0) = (s32) (*func_02067b48(M2C_FIELD(arg1, s32 *, 0x21C), arg2) << 0xC);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (temp_r5 << 0xC);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_r6 << 0xC);
}
