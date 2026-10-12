#include "m2c.h"

extern M2C_UNK data_020fdc60;

void func_0202cbd4(s32 *arg0, void *arg1) {
    *arg0 = *((M2C_UNK *)((s8 *)&data_020fdc60 + (M2C_FIELD(arg1, u8 *, 8) * 0x14)));
}
