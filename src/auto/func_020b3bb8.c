#include "m2c.h"

s32 func_0205e540(s32, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK func_0205e624(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_0210daf0;
extern M2C_UNK data_0210daf4;

void func_020b3bb8(void) {
    func_0205e624(&data_0210daf4, 0, 0x20);
    M2C_FIELD(&data_0210daf0, s32 *, 8)    = func_0205e540(0x7A120, 3, 4);
    M2C_FIELD(&data_0210daf0, s32 *, 0x18) = 0;
    M2C_FIELD(&data_0210daf0, s32 *, 0x1C) = 0x7A120;
    M2C_FIELD(&data_0210daf0, s32 *, 0x20) = 0;
    M2C_FIELD(&data_0210daf0, s32 *, 0)    = 0;
}
