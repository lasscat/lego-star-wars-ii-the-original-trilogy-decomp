#include "m2c.h"

M2C_UNK func_02062694(void *, M2C_UNK, M2C_UNK);    /* extern */
s16 func_02062b10(s32);                             /* extern */
extern M2C_UNK data_02100978;

void *func_020b0c74(void *arg0) {
    func_02062694(arg0, 0, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_02100978;
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s8 *, 7) = 0;
    M2C_FIELD(arg0, s8 *, 6) = 0;
    M2C_FIELD(arg0, s8 *, 8) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = func_02062b10(0xFFFF);
    M2C_FIELD(arg0, s8 *, 0xC) = 0;
    M2C_FIELD(arg0, s8 *, 0xE) = 1;
    return arg0;
}
