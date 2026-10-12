#include "m2c.h"

M2C_UNK func_0205a0bc(s32, u16);                    /* extern */

void func_02019bb8(void *arg0) {
    if (!(M2C_FIELD(arg0, s32 *, 8) & 8)) {
        return;
    }
    M2C_FIELD(arg0, u16 *, 0xF2) = (u16) (M2C_FIELD(arg0, u16 *, 0xF2) + 1);
    if ((u32) M2C_FIELD(arg0, u16 *, 0xF2) < (u32) M2C_FIELD(arg0, u16 *, 0xEC)) {
        return;
    }
    M2C_FIELD(arg0, u16 *, 0xF2) = 0U;
    M2C_FIELD(arg0, u16 *, 0xF0) = (u16) (M2C_FIELD(arg0, u16 *, 0xF0) + 1);
    if ((u32) M2C_FIELD(arg0, u16 *, 0xF0) >= (u32) M2C_FIELD(arg0, u16 *, 0xEE)) {
        M2C_FIELD(arg0, u16 *, 0xF0) = 0U;
    }
    func_0205a0bc(M2C_FIELD(arg0, s32 *, 0xD4), M2C_FIELD(arg0, u16 *, 0xF0));
}
