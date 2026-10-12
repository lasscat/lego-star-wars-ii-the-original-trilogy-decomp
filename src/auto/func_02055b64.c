#include "m2c.h"

M2C_UNK func_02055d34(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_02101efc;

void func_02055b64(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    func_02055d34(arg0, arg1, arg2, (0x408 * arg3) + (s32) &data_02101efc);
}
