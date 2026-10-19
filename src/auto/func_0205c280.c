#include "m2c.h"

s32 func_0205e540(s32, M2C_UNK, M2C_UNK);           /* extern */

s32 func_0205c280(s32 arg0, s32 arg1, u32 arg2) {
    switch (arg2) {
        case 0:
        case 4:
            return func_0205e540(arg1 * 0x28, 3, 4);
        case 5:
            return func_0205e540(arg1 * 0x1C, 3, 4);
        case 3:
            return func_0205e540(arg1 * 0x1C, 3, 4);
        case 11:
            return func_0205e540(arg1 << 5, 3, 4);
        default:
            return 0;
    }
}
