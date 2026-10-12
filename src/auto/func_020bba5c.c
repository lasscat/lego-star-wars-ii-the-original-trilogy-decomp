#include "m2c.h"
#include "engine.h"

M2C_UNK func_02062b10(M2C_UNK);

s32 func_020bba5c(s32 arg0) {
    u32 temp_r0;

    if ((u32) arg0 < 0x10000U) {
        return func_02062b10((s32) (u16) arg0);
    }
    temp_r0 = (u32) func_02062b10((s32) ((u32) (arg0 * 2) >> 0x10));
    if (temp_r0 < (u32) ((u32) arg0 >> 0xF)) {
        return func_02062b10(0x7FFF) | (temp_r0 << 0xF);
    }
    return func_02062b10((s32) (u16) (arg0 & 0x7FFF)) | (temp_r0 << 0xF);
}
