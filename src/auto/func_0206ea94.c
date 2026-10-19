#include "m2c.h"

M2C_UNK func_0205ecc4(void *, s32, s32, s32, s32, s32);
M2C_UNK func_0206eb90(void *);
M2C_UNK func_0208896c(void *);
M2C_UNK func_02093c6c(void *, s32);
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104df4;
extern M2C_UNK data_0210930c;

void func_0206ea94(void *arg0) {
    switch (M2C_FIELD(arg0, s32 *, 0x68)) {
        case 0:
            func_0206eb90(arg0);
            return;
        case 4:
            func_0208896c(&data_02104df4);
            func_02093c6c(&data_0210930c, 0);
            if (M2C_FIELD(arg0, s32 *, 0x6C) == 7) {
                func_0205ecc4(&data_02102900, 0x20, 1, 0, 1, 0);
            } else {
                func_0205ecc4(&data_02102900, 4, 0, 0x11, 0xE, 0);
                func_0205ecc4(&data_02102900, 0x30, 1, 0, 0, 0);
            }
            M2C_FIELD(arg0, s32 *, 0x68) = 0xE;
            return;
        case 0xE:
            return;
    }
}
