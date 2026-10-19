#include "m2c.h"

void *func_020531d8();
s32 func_02053964();
s32 func_020539c8();

void func_0205375c(M2C_UNK arg0, void *arg1) {
    void *t;

    t                         = func_020531d8(arg0);
    M2C_FIELD(t, s32 *, 0x10) = (s32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(t, s32 *, 0x14) = (s32) M2C_FIELD(arg1, s32 *, 4);
    if ((M2C_FIELD(arg1, s32 *, 0) == 0) && (M2C_FIELD(arg1, s32 *, 4) == 0)) {
        t                               = func_020531d8(arg0);
        M2C_FIELD(t, volatile s32 *, 4) = (s32) (M2C_FIELD(t, volatile s32 *, 4) & ~4);
    } else {
        t                               = func_020531d8(arg0);
        M2C_FIELD(t, volatile s32 *, 4) = (s32) (M2C_FIELD(t, volatile s32 *, 4) | 4);
    }
    if ((func_020539c8(arg0) != 0) || (func_02053964(arg0) != 0)) {
        t                      = func_020531d8(arg0);
        M2C_FIELD(t, s32 *, 4) = (s32) (M2C_FIELD(t, s32 *, 4) | 1);
    } else {
        t                      = func_020531d8(arg0);
        M2C_FIELD(t, s32 *, 4) = (s32) (M2C_FIELD(t, s32 *, 4) | 2);
    }
}
