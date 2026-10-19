#include "m2c.h"

extern M2C_UNK data_021157d4;

u8 func_020d0534(u16 arg0) {
    s32 off = arg0 * 0x18;
    s32 a;
    s32 b;
    s32 v;

    switch (M2C_FIELD(M2C_FIELD(&data_021157d4, s32 *, 0xC) + off, u16 *, 0xE)) {
        case 0:
            return 0U;
        case 1:
            a = b = 0;
            break;
        default:
            a = func_020d0534(M2C_FIELD(M2C_FIELD(&data_021157d4, s32 *, 0xC) + off, u16 *, 0x8));
            b = func_020d0534(M2C_FIELD(M2C_FIELD(&data_021157d4, s32 *, 0xC) + off, u16 *, 0xA));
            break;
    }
    v                                                                   = a + b + 1;
    M2C_FIELD(M2C_FIELD(&data_021157d4, s32 *, 0xC) + off, u16 *, 0x16) = v;
    return (u8) v;
}
