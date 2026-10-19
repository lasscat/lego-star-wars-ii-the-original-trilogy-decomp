#include "m2c.h"

u32 func_0208da74();                                /* extern */
extern M2C_UNK data_020f2144;
extern M2C_UNK data_020f2414;
extern M2C_UNK data_020f2b1c;
extern M2C_UNK data_020f3490;
extern M2C_UNK data_020f3e68;

s32 func_0208dad8(s32 arg0) {
    switch (func_0208da74()) {
        case 0:
            return (arg0 * 0x28) + (s32) &data_020f2414;
        case 1:
            return ((arg0 - 0x2D) * 0x2C) + (s32) &data_020f3e68;
        case 2:
            return ((arg0 - 0x6B) * 0x24) + (s32) &data_020f3490;
        case 3:
            return ((arg0 - 0xB1) * 0x2C) + (s32) &data_020f2b1c;
        case 4:
            return ((arg0 - 0xE8) * 0x28) + (s32) &data_020f2144;
        default:
            return 0;
    }
}
