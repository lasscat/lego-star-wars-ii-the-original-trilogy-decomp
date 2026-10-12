#include "m2c.h"

M2C_UNK func_020a99a8();                            /* extern */
extern M2C_UNK data_020ff9b4;

void func_020a9920(void *arg0) {
    func_020a99a8();
    if ((arg0 + 0x29C) != &data_020ff9b4) {
        M2C_FIELD(arg0, s32 *, 0x29C) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0x2A0) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x2A4) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 8);
    }
    M2C_FIELD(arg0, s8 *, 0x23E) = 1;
}
