#include "m2c.h"
extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fdec8;
extern M2C_UNK data_02106d90;
void *func_02033ad8(void *p, void *arg) {
    *(u32 *) ((u8 *) p + 0x0)                               = (u32) &data_020fdbc4;
    *(u32 *) ((u8 *) p + 0x4)                               = (u32) arg;
    *(u8 *) ((u8 *) p + 0xc)                                = 0;
    *(u8 *) ((u8 *) p + 0xd)                                = 0;
    *(u32 *) ((u8 *) p + 0x0)                               = (u32) &data_020fdec8;
    *(u32 *) ((u8 *) p + 0x10)                              = 0;
    *(u32 *) ((u8 *) p + 0x14)                              = 0;
    *(u32 *) ((u8 *) p + 0x18)                              = 0;
    *(s8 *) ((u8 *) p + 0x1c)                               = -1;
    *(u8 *) ((u8 *) p + 0x1d)                               = 0;
    *(u32 *) (*(u32 *) ((u8 *) &data_02106d90 + 0xad0) + 8) = *(u32 *) ((u8 *) p + 4);
    return p;
}
