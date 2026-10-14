#include "m2c.h"

M2C_UNK func_0205e624(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_02062694(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_0209b6e4(void *);                      /* extern */
extern M2C_UNK data_020ffa78;

void *func_0209b61c(void *arg0) {
    func_02062694(arg0, 0, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ffa78;
    M2C_FIELD(arg0, s8 *, 6)       = 0;
    M2C_FIELD(arg0, s32 *, 8)      = 0;
    M2C_FIELD(arg0, s32 *, 0x10)   = 0;
    M2C_FIELD(arg0, s32 *, 0x34)   = 0;
    M2C_FIELD(arg0, s32 *, 0x38)   = 0x80000000;
    M2C_FIELD(arg0, s8 *, 0x40)    = 5;
    M2C_FIELD(arg0, s8 *, 0x41)    = -1;
    M2C_FIELD(arg0, s8 *, 0x42)    = 0;
    M2C_FIELD(arg0, s32 *, 0x44)   = 0;
    M2C_FIELD(arg0, s32 *, 0x48)   = 0;
    M2C_FIELD(arg0, s32 *, 0x4C)   = 0;
    M2C_FIELD(arg0, s8 *, 0x50)    = 0;
    M2C_FIELD(arg0, s16 *, 0xB2)   = 0;
    func_0205e624(arg0 + 0x14, 0, 8);
    func_0205e624(arg0 + 0x1C, 0, 8);
    func_0205e624(arg0 + 0x24, 0, 8);
    func_0205e624(arg0 + 0x51, 0, 0x60);
    M2C_FIELD(arg0, s32 *, 0x3C) = 0x12C;
    func_0209b6e4(arg0);
    return arg0;
}
