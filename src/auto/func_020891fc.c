#include "m2c.h"

extern M2C_UNK data_020ff9b4;

void func_020891fc(s32 arg0) {
    *(u8 *) ((s8 *) arg0 + 0x10) = 0xff;
    *(u8 *) ((s8 *) arg0 + 0x11) = 0;
    *(s32 *) ((s8 *) arg0 + 0xc) = -1;
    if ((s8 *) arg0 != (s8 *) &data_020ff9b4) {
        *(s32 *) ((s8 *) arg0 + 0x0) = *(s32 *) ((s8 *) &data_020ff9b4 + 0x0);
        *(s32 *) ((s8 *) arg0 + 0x4) = *(s32 *) ((s8 *) &data_020ff9b4 + 0x4);
        *(s32 *) ((s8 *) arg0 + 0x8) = *(s32 *) ((s8 *) &data_020ff9b4 + 0x8);
    }
    *(u8 *) ((s8 *) arg0 + 0x12) = 0;
    *(u8 *) ((s8 *) arg0 + 0x13) = 0;
    *(u8 *) ((s8 *) arg0 + 0x14) = 0;
}
