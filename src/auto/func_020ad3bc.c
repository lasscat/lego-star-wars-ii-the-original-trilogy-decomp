#include "m2c.h"

M2C_UNK func_0205e860();                            /* extern */
extern M2C_UNK data_0210b320;

void func_020ad3bc(void) {
    if (M2C_FIELD(&data_0210b320, s32 *, 0x80) != 0) {
        func_0205e860();
    }
    M2C_FIELD(&data_0210b320, s32 *, 0x80) = 0;
    M2C_FIELD(&data_0210b320, s16 *, 0x84) = 0;
    M2C_FIELD(&data_0210b320, s16 *, 0x86) = 0;
    M2C_FIELD(&data_0210b320, s32 *, 0x88) = 0x400141;
    M2C_FIELD(&data_0210b320, s16 *, 0x8C) = 0;
    M2C_FIELD(&data_0210b320, s16 *, 0x8E) = 1;
    M2C_FIELD(&data_0210b320, s16 *, 0x90) = 3;
    M2C_FIELD(&data_0210b320, s16 *, 0x92) = 0;
    M2C_FIELD(&data_0210b320, s16 *, 0x94) = 0;
    M2C_FIELD(&data_0210b320, s16 *, 0x96) = 0;
    M2C_FIELD(&data_0210b320, s16 *, 0x98) = 0xC8;
    M2C_FIELD(&data_0210b320, s16 *, 0xB2) = 0;
    M2C_FIELD(&data_0210b320, s16 *, 0xB4) = 0x200;
    M2C_FIELD(&data_0210b320, s16 *, 0xB6) = 0x7C;
}
