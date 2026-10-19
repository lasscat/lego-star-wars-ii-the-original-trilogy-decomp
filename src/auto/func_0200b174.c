#include "m2c.h"

M2C_UNK func_02017908(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_020e46bc(void *, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK data_020fcd70;
extern M2C_UNK func_0200b23c;
extern M2C_UNK func_0200b24c;

void *func_0200b174(void *arg0, M2C_UNK arg1, s8 arg2, s8 arg3, s32 arg4, s32 arg5, u8 arg6) {
    u8 sp4[0x48];

    M2C_FIELD(sp4, s32 *, 0x24) = 0;
    M2C_FIELD(sp4, s32 *, 0x28) = 0;
    M2C_FIELD(sp4, s32 *, 0x2C) = 0;
    M2C_FIELD(sp4, s32 *, 0x30) = 0x1000;
    M2C_FIELD(sp4, s32 *, 0x34) = 0x1000;
    M2C_FIELD(sp4, s32 *, 0x38) = 0x1000;
    M2C_FIELD(sp4, u16 *, 0x3C) = 0;
    M2C_FIELD(sp4, u16 *, 0x3E) = 0;
    M2C_FIELD(sp4, u16 *, 0x40) = 0;
    M2C_FIELD(sp4, s8 *, 0x44)  = 1;
    M2C_FIELD(sp4, s8 *, 0x45)  = 1;
    func_02017908(arg0, 0x80, arg1, (M2C_UNK *) sp4);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fcd70;
    M2C_FIELD(arg0, s32 *, 0xD4)   = 0;
    func_020e46bc(arg0 + 0xD8, 3, 8, &func_0200b23c, &func_0200b24c);
    M2C_FIELD(arg0, s16 *, 0xF0) = 0;
    M2C_FIELD(arg0, s8 *, 0xF2)  = (s8) arg4;
    M2C_FIELD(arg0, s8 *, 0xF3)  = arg2;
    M2C_FIELD(arg0, s8 *, 0xF4)  = (s8) arg5;
    M2C_FIELD(arg0, s8 *, 0xF5)  = arg3;
    M2C_FIELD(arg0, u8 *, 0xF6)  = arg6;
    return arg0;
}
