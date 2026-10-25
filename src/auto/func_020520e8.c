#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

extern M2C_UNK data_0210930c;
M2C_UNK func_02096828(M2C_UNK *, V3, V3, s32, u8, u8);

s32 func_020520e8(void *arg0, s32 arg1, s32 arg2) {
    V3 a;
    V3 b;
    void *temp;
    volatile u16
        tmp[2]; // FAKE: local volatile forces the original store/reload through the stack (tmp[1] store, reload, tmp[0] store)
    u16 w;
    s32 x;
    s32 bv;

    a.x                          = M2C_FIELD(arg0, s16 *, 0) << 0xC;
    a.y                          = M2C_FIELD(arg0, s16 *, 2) << 0xC;
    a.z                          = M2C_FIELD(arg0, s16 *, 4) << 0xC;
    bv                           = ((u16 *) arg0)[4] << 0xC;
    b.x                          = bv;
    b.y                          = bv;
    b.z                          = bv;
    temp                         = (void *) func_02096828(&data_0210930c, a, b, 4, arg1, arg2);
    M2C_FIELD(temp, u8 *, 0x2C)  = 1;
    M2C_FIELD(temp, u8 *, 0x2D)  = M2C_FIELD(arg0, u8 *, 0xE);
    M2C_FIELD(temp, u8 *, 0x1E)  = M2C_FIELD(arg0, u8 *, 0xC);
    M2C_FIELD(temp, u8 *, 0x1F)  = M2C_FIELD(arg0, u8 *, 0xD);
    x                            = M2C_FIELD(arg0, s16 *, 0xA) << 16;
    tmp[1]                       = (u16) (x / 360);
    w                            = tmp[1];
    tmp[0]                       = w;
    M2C_FIELD(temp, u16 *, 0x2E) = w;
    return 0;
}
