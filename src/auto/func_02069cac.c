#include "m2c.h"

s32 func_020861a0(M2C_UNK *);                              /* extern */
M2C_UNK func_02085948(M2C_UNK *);                          /* extern */
s32 func_02085e88(M2C_UNK *, M2C_UNK);                     /* extern */
M2C_UNK func_02086184(M2C_UNK *, M2C_UNK);                 /* extern */
M2C_UNK func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104d90;

s32 func_02069cac(s32 arg0, M2C_UNK arg1) {
    if (func_020861a0(&data_02104d90) == 0) {
        func_02085948(&data_02104d90);
        if (func_02085e88(&data_02104d90, arg1) != 0) {
            func_02086184(&data_02104d90, arg1);
            func_0205ecc4(&data_02102900, 4, 0, 6, 0xE, 0);
            func_0205ecc4(&data_02102900, 0x30, 1, 0, 0, 0);
            return 1;
        }
    }
    return 0;
}
