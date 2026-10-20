#include "m2c.h"
s32 func_0205e818(s32 size, M2C_UNK align, M2C_UNK flag);
void func_02095f28(s32 arg0) {
    s32 i;
    M2C_FIELD(arg0, s32 *, 0) = func_0205e818(14, 3, 4);
    for (i = 0; i < 14; i++) {
        *(u8 *) (M2C_FIELD(arg0, s32 *, 0) + i) = 0xFF;
    }
    M2C_FIELD(arg0, s32 *, 0x304) = 0;
}
