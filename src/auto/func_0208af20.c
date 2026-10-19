#include "m2c.h"

void *func_02053b14(s32);                           /* extern */
extern M2C_UNK data_020f0278;
extern M2C_UNK data_0210930c;

void func_0208af20(void *arg0) {
    u8 sp[3];
    u8 v;
    u8 flag;
    u16 temp_r2;
    u16 var_r1;
    void *temp_r0;

    sp[0]   = M2C_FIELD(&data_020f0278, volatile u8 *, 0);
    sp[1]   = M2C_FIELD(&data_020f0278, volatile u8 *, 1);
    sp[2]   = M2C_FIELD(&data_020f0278, volatile u8 *, 2);
    temp_r0 = func_02053b14(arg0 + 8);
    flag    = M2C_FIELD(&data_0210930c, volatile u8 *, 0x19A);
    v       = sp[flag];
    if (flag == 1) {
        var_r1 = v | 0x4000;
    } else {
        var_r1 = v | 0x3000;
    }
    temp_r2                                  = var_r1 + (M2C_FIELD(arg0, volatile u8 *, 0x80) * 2);
    M2C_FIELD(temp_r0, volatile u16 *, 0x4C) = temp_r2;
    M2C_FIELD(temp_r0, volatile s16 *, 0x4E) = (s16) (temp_r2 + 1);
    M2C_FIELD(temp_r0, volatile s16 *, 0x8C) = (s16) (temp_r2 + 0x20);
    M2C_FIELD(temp_r0, volatile s16 *, 0x8E) = (s16) (temp_r2 + 0x21);
}
