#include "m2c.h"

extern M2C_UNK data_020ff9b4;

M2C_UNK func_0205c280(M2C_UNK *, s32, u8);
M2C_UNK func_01ffa478(M2C_UNK *, s32);
s32 func_01ffa41c(M2C_UNK);

typedef void (*Fn)(M2C_UNK *, M2C_UNK);
extern Fn data_020fe598[];

s32 func_0205c0f0(void *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK *ptr;
    s32 i;
    s32 j;

    M2C_FIELD(arg0, u16 *, 4)     = (u16) arg2;
    M2C_FIELD(arg0, M2C_UNK *, 0) = func_0205c280(arg0, arg2, M2C_FIELD(arg0, u8 *, 8));
    for (i = 0; i < arg2; i++) {
        ptr = func_01ffa478(arg0, i);
        if (M2C_FIELD(arg0, u8 *, 8) == 4) {
            M2C_FIELD(ptr, u8 *, 0x24) = 1;
        } else if (M2C_FIELD(arg0, u8 *, 8) == 0) {
            M2C_FIELD(ptr, u8 *, 0x24) = 0;
        }
        M2C_FIELD(ptr, s32 *, 0) = func_01ffa41c(arg1);
        M2C_FIELD(ptr, s32 *, 4) = func_01ffa41c(arg1);
        M2C_FIELD(ptr, s32 *, 8) = func_01ffa41c(arg1);
        ((Fn) data_020fe598[M2C_FIELD(arg0, u8 *, 8)])(ptr, arg1);
        M2C_FIELD(arg0, u16 *, 6) = (u16) (M2C_FIELD(arg0, u16 *, 6) + 1);
    }
    if (M2C_FIELD(func_01ffa478(arg0, 0), u8 *, 0xF) == 2) {
        for (j = arg2 - 1; j >= 1; j--) {
            M2C_UNK *a                                  = func_01ffa478(arg0, j - 1);
            M2C_UNK *b                                  = func_01ffa478(arg0, j);
            M2C_FIELD(b, s32 *, 0)                      = M2C_FIELD(b, s32 *, 0) - M2C_FIELD(a, s32 *, 0);
            M2C_FIELD(b, s32 *, 4)                      = M2C_FIELD(b, s32 *, 4) - M2C_FIELD(a, s32 *, 4);
            M2C_FIELD(b, s32 *, 8)                      = M2C_FIELD(b, s32 *, 8) - M2C_FIELD(a, s32 *, 8);
            M2C_FIELD(func_01ffa478(arg0, j), s32 *, 4) = 0;
        }
        ptr = func_01ffa478(arg0, 0);
        if (ptr != &data_020ff9b4) {
            M2C_FIELD(ptr, s32 *, 0) = M2C_FIELD(&data_020ff9b4, s32 *, 0);
            M2C_FIELD(ptr, s32 *, 4) = M2C_FIELD(&data_020ff9b4, s32 *, 4);
            M2C_FIELD(ptr, s32 *, 8) = M2C_FIELD(&data_020ff9b4, s32 *, 8);
        }
    }
    return 1;
}
