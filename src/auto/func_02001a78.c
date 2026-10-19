#include "m2c.h"

M2C_UNK func_0200fe94(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK data_020fcc88;

void *func_02001a78(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
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
    func_0200fe94(arg0, 0x4000, arg1, arg2, (M2C_UNK *) sp4);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fcc88;
    M2C_FIELD(arg0, s32 *, 0x1BC)  = 0;
    M2C_FIELD(arg0, s32 *, 0x1C0)  = 0;
    M2C_FIELD(arg0, s32 *, 0x1C4)  = 0;
    M2C_FIELD(arg0, s32 *, 0x1C8)  = 0;
    M2C_FIELD(arg0, s32 *, 0x1CC)  = 0;
    M2C_FIELD(arg0, s32 *, 0x1D0)  = 0;
    return arg0;
}
