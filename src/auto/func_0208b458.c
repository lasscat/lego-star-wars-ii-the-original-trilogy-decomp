#include "m2c.h"

s32 func_02053b14(void *);                          /* extern */
M2C_UNK func_0208adb8(void *, s32, M2C_UNK *);      /* extern */
s32 func_0208c72c(M2C_UNK *, s32);                  /* extern */
s32 func_0208c77c(M2C_UNK *, s32);                  /* extern */
M2C_UNK func_020e0c54(M2C_UNK *, M2C_UNK *, s32);   /* extern */
extern M2C_UNK data_020ff458;
extern M2C_UNK data_02104dc4;

void func_0208b458(void *arg0, s32 arg1) {
    u8 sp0[16];
    s32 temp_r4;
    void *temp_r1;
    void *temp_r2;

    if (arg1 >= 0x15) {
        return;
    }
    temp_r2                      = M2C_FIELD(arg0, void **, 0x64);
    M2C_FIELD(temp_r2, s32 *, 8) = (s32) (M2C_FIELD(temp_r2, s32 *, 8) | 1);
    temp_r4                      = func_02053b14(arg0 + 8);
    func_020e0c54(sp0, &data_020ff458, func_0208c72c(&data_02104dc4, arg1));
    func_0208adb8(arg0, temp_r4 + 0x40A, sp0);
    if (func_0208c77c(&data_02104dc4, arg1) == 0) {
        return;
    }
    temp_r1                      = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(temp_r1, s32 *, 8) = (s32) (M2C_FIELD(temp_r1, s32 *, 8) | 1);
}
