#include "m2c.h"

s32 func_0205365c(s32 *, s32);
s32 func_02086f20(s32, s32);
void func_0206574c(void *, s32, s32);
M2C_UNK *func_02066708(M2C_UNK);
s32 func_02065be8(M2C_UNK, M2C_UNK, s32, s32, s32, s32);
extern M2C_UNK data_02104d90;

s32 func_0207df90(void *arg0) {
    s32 i;
    s32 v;

    func_0205365c(M2C_FIELD(arg0, s32 *, 0x10), 0);
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        goto fail;
    }
    if (func_02086f20(&data_02104d90, M2C_FIELD(arg0, s32 *, 0)) != 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x2c) = 0x8c;
    func_0206574c(M2C_FIELD(arg0, s32 *, 8), 6, -1);
    i = 0;
    v = 0x45;
    for (; i < 2; i++) {
        M2C_UNK *tmp = func_02066708(i + 0x151);
        M2C_FIELD(arg0, s32 *, 0x2c) =
            func_02065be8(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0x2c), 0x80, v, (s32) tmp, 1);
        v += 0x21;
    }
    M2C_FIELD(arg0, u8 *, 0x27) = 0xa;
    return 1;
fail:
    return 0;
}
