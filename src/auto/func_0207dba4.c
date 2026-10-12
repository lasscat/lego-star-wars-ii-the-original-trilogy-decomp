#include "m2c.h"

s32 func_0205d0f8(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_021027f8;
extern u8 data_021044a4;
extern s32 data_027e02a8;

s32 func_0207dba4(void) {
    if ((func_0205d0f8(&data_021027f8, 1) != 0) || (!(data_027e02a8 & 0x40) && (((u32) (data_021044a4 << 0x1B) >> 0x1F) != 0))) {
        return 1;
    }
    return 0;
}
