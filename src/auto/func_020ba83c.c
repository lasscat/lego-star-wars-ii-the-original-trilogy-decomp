#include "m2c.h"
#include "engine.h"

M2C_UNK func_020bb918(M2C_UNK);

extern M2C_UNK data_0210dc48;

s32 func_020ba83c(s32 arg0) {
    if (func_020bb918(arg0) == 0) {
        return 0;
    }
    return ((u8) arg0 * 0x1C) + (s32) &data_0210dc48;
}
