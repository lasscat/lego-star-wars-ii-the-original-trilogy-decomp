#include "m2c.h"

M2C_UNK func_020601ac(void *, s32, s32, s32, s32, s32);
M2C_UNK func_020696f0(void *);
s32 func_02069cac(void *, s32);
s32 func_02069d4c(void *, s32);
extern M2C_UNK data_02102900;

void func_0206962c(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x2A) != 0) {
        M2C_FIELD(arg0, u8 *, 0x2A) = 0;
        if (M2C_FIELD(arg0, u8 *, 0x28) != 0) {
            if (func_02069d4c(arg0, M2C_FIELD(arg0, s32 *, 0x1C)) != 0) {
                return;
            }
            func_020601ac(&data_02102900, 1, 0x24, -1, 5, 0);
            return;
        }
        if (func_02069cac(arg0, M2C_FIELD(arg0, s32 *, 0x1C)) != 0) {
            return;
        }
        func_020601ac(&data_02102900, 1, 0x23, -1, 5, 0);
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x29) != 0) {
        return;
    }
    func_020696f0(arg0);
}
