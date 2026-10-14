#include "m2c.h"

M2C_UNK func_020ccb34(M2C_UNK);                     /* extern */
extern M2C_UNK data_02115778;

void func_020ce7a8(void) {
    if (M2C_FIELD(&data_02115778, u16 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_02115778, u16 *, 0)    = 1U;
    M2C_FIELD(&data_02115778, s32 *, 0xC)  = 0;
    M2C_FIELD(&data_02115778, s32 *, 0x10) = 0;
    func_020ccb34(4);
    M2C_FIELD(&data_02115778, s32 *, 8) = 0;
    M2C_FIELD(&data_02115778, s32 *, 4) = 0;
}
