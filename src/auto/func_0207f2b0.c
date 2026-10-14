#include "m2c.h"

M2C_UNK func_02086e1c(M2C_UNK *, s32);              /* extern */
s32 func_02086e4c(M2C_UNK *, s32);                  /* extern */
M2C_UNK func_02086ea0(M2C_UNK *, s32);              /* extern */
s32 func_02093fd0(s32);                             /* extern */
extern M2C_UNK data_02104d90;

void func_0207f2b0(void *arg0) {
    func_02086ea0(&data_02104d90, func_02093fd0(M2C_FIELD(arg0, s32 *, 4)));
    if (func_02093fd0(M2C_FIELD(arg0, s32 *, 4)) == 0) {
        func_02086e1c(&data_02104d90, 1);
        func_02086e1c(&data_02104d90, 5);
        func_02086e1c(&data_02104d90, 0xA);
        return;
    }
    if ((func_02093fd0(M2C_FIELD(arg0, s32 *, 4)) == 4) || (func_02093fd0(M2C_FIELD(arg0, s32 *, 4)) == 9) ||
        (func_02093fd0(M2C_FIELD(arg0, s32 *, 4)) == 0xE)) {
        if (func_02086e4c(&data_02104d90, func_02093fd0(M2C_FIELD(arg0, s32 *, 4))) != 1) {
            return;
        }
        if (func_02086e4c(&data_02104d90, func_02093fd0(M2C_FIELD(arg0, s32 *, 4))) != 1) {
            return;
        }
        if (func_02086e4c(&data_02104d90, func_02093fd0(M2C_FIELD(arg0, s32 *, 4))) != 1) {
            return;
        }
        func_02086e1c(&data_02104d90, 0xF);
        return;
    }
    if (func_02093fd0(M2C_FIELD(arg0, s32 *, 4)) == 0xF) {
        return;
    }
    func_02086e1c(&data_02104d90, func_02093fd0(M2C_FIELD(arg0, s32 *, 4)) + 1);
}
