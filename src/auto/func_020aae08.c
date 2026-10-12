#include "m2c.h"

extern M2C_UNK data_021027f8;
extern s32 data_027e02a8;

u8 func_020aae08(s32 arg0, s32 arg1) {
    if (data_027e02a8 & 0x40) {
        return M2C_FIELD((arg0 + arg1), u8 *, 0x208);
    }
    if (arg1 == 0) {
        return M2C_FIELD((arg0 + arg1), u8 *, 0x208);
    }
    return M2C_FIELD((arg0 + M2C_FIELD(&data_021027f8, u8 *, 0x2A)), u8 *, 0x208);
}
