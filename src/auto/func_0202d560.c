/* Reconstructed from USA ARM9 at 0x0202d560 (144 bytes). */
#include "m2c.h"

extern M2C_UNK data_020f6a6c;
extern M2C_UNK data_020f6a6e;
extern M2C_UNK data_020f6a70;
extern M2C_UNK data_020f6a72;
extern M2C_UNK data_020ff7de;
extern void func_0202d5f0(void *, s32, s8);

void func_0202d560(void *arg0, s32 arg1) {
    s32 off  = *((u8 *) ((s8 *) &data_020ff7de + (M2C_FIELD(arg0, u8 *, 1) * 8)));
    s8 level = 0;
    s16 val  = M2C_FIELD(arg0, s16 *, 4);

    off <<= 4;
    if (val > *(s16 *) ((s8 *) &data_020f6a6c + off)) {
        if (val > *(s16 *) ((s8 *) &data_020f6a70 + off)) {
            if (val > *(s16 *) ((s8 *) &data_020f6a72 + off)) {
                M2C_FIELD(arg0, s16 *, 4) = *(s16 *) ((s8 *) &data_020f6a72 + off);
            }
            level = 3;
        } else if (val > *(s16 *) ((s8 *) &data_020f6a6e + off)) {
            level = 2;
        } else {
            level = 1;
        }
    }
    if (level != M2C_FIELD(arg0, u8 *, 2)) {
        func_0202d5f0(arg0, arg1, level);
    }
}
