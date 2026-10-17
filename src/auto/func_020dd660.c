#include "m2c.h"

M2C_UNK CpuSet(s32 *, M2C_UNK *, s32);              /* extern */
s16 func_020ccec8();                                /* extern */
extern M2C_UNK data_0211e458;
extern M2C_UNK data_0211e45c;

void func_020dd660(void) {
    s32 sp0;

    sp0 = 0;
    CpuSet(&sp0, &data_0211e45c, 0x05000001);
    M2C_FIELD(&data_0211e458, s16 *, 6) = func_020ccec8();
}
