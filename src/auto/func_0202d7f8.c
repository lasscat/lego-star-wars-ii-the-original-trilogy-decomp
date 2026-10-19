#include "m2c.h"

s32 func_02095eb8(M2C_UNK *, u8, u8);               /* extern */
extern M2C_UNK data_0210786c;

s32 func_0202d7f8(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    if (M2C_FIELD(arg0, u16 *, 0xC) == 1) {
        if (M2C_FIELD(arg2, u16 *, 0xC) == 1) {
            return 0;
        }
        if ((u32) (arg3 - 8) <= 1U) {
            return 1;
        }
        return func_02095eb8(&data_0210786c, arg1, arg3);
    }
    if ((u32) (arg1 - 8) <= 1U) {
        if (M2C_FIELD(arg2, u16 *, 0xC) == 1) {
            return 1;
        }
    } else if (func_02095eb8(&data_0210786c, arg1, arg3) != 0) {
        return 1;
    }
    return 0;
}
