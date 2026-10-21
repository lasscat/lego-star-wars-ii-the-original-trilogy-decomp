#include "m2c.h"

extern M2C_UNK data_020fe5c8;

s32 func_0205ccf8(void *arg0) {
    u32 c;
    M2C_FIELD(&data_020fe5c8, u32 *, 4) = (u32) arg0;
    c                                   = *(s32 *) arg0;
    M2C_FIELD(&data_020fe5c8, u32 *, 8) = (u32) ((u8 *) arg0 + 4);
    M2C_FIELD(&data_020fe5c8, u32 *, 0) = (u32) ((u8 *) arg0 + c);
    return 0;
}
