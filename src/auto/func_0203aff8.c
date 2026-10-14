#include "m2c.h"

M2C_UNK func_0201c778(void *);                      /* extern */
extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fe168;

void *func_0203aff8(void *arg0, s32 arg1, void *arg2) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s8 *, 0xC)     = 0;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe168;
    M2C_FIELD(arg0, void **, 0x10) = arg2;
    M2C_FIELD(arg0, s32 *, 0x1C)   = 0x276;
    M2C_FIELD(arg0, s32 *, 0x20)   = 0;
    func_0201c778(arg0 + 0x24);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), u8 *, 0x5DA);
    return arg0;
}
