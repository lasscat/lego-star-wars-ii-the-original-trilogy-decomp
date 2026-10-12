#include "m2c.h"
#include "engine.h"

void func_020861bc(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_02104d90;

void func_020b11b0(s32 arg0) {
    if ((M2C_FIELD(arg0, u8 *, 6) == 0) && (M2C_FIELD(arg0, u8 *, 7) == 0) && (M2C_FIELD(arg0, u8 *, 8) == 0)) {
        return;
    }
    M2C_FIELD(arg0, u8 *, 6) = 0U;
    M2C_FIELD(arg0, u8 *, 7) = 0U;
    M2C_FIELD(arg0, u8 *, 8) = 0U;
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    func_020861bc((s32) &data_02104d90, 0xB, 0);
}
