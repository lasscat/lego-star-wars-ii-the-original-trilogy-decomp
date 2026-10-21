#include "m2c.h"

extern M2C_UNK data_0211748c;

typedef void (*PMCallback)(s32, s32);

void func_020d3a8c(s32 arg0) {
    s32 flag            = M2C_FIELD(&data_0211748c, s32 *, 0x18);
    PMCallback callback = (PMCallback) M2C_FIELD(&data_0211748c, s32 *, 0x1c);
    s32 value           = M2C_FIELD(&data_0211748c, s32 *, 0x20);
    if (flag != 0) {
        M2C_FIELD(&data_0211748c, s32 *, 0x18) = 0;
    }
    if (callback != 0) {
        M2C_FIELD(&data_0211748c, s32 *, 0x1c) = 0;
        callback(arg0, value);
    }
}
