#include "m2c.h"

s32 func_020ca774();                                /* extern */
extern M2C_UNK data_02115384;

void func_020cc2a8(void) {
    M2C_FIELD(&data_02115384, s32 *, 0x18) = func_020ca774();
}
