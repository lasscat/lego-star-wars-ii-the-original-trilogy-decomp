#include "m2c.h"

s32 func_02065be8(s32, s32, M2C_UNK, M2C_UNK, s32, s32); /* extern */
s32 func_02066708(s32);                             /* extern */
s32 func_02086204(M2C_UNK *, M2C_UNK);              /* extern */
s32 func_02086f20(M2C_UNK *, s32);                  /* extern */
extern M2C_UNK data_02104d90;
extern s32 data_027e02a8;

s32 func_0207dee4(void *arg0) {
    if (data_027e02a8 & 0x40) {
        return 0;
    }
    if (func_02086204(&data_02104d90, 0xA) == 0) {
        if (func_02086f20(&data_02104d90, M2C_FIELD(arg0, s32 *, 0)) != 0) {
            return 0;
        }
        M2C_FIELD(arg0, s32 *, 0x2C) =
            func_02065be8(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0x2C), 0x80, 0x45, func_02066708(0x12A), 1);
        M2C_FIELD(arg0, s8 *, 0x27) = 8;
        return 1;
    }
    return 0;
}
