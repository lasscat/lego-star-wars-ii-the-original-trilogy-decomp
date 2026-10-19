#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

extern M2C_UNK data_0210930c;
M2C_UNK func_02096828(M2C_UNK *, V3, V3, s32, u8, u8);

s32 func_02052840(void *arg0, s32 arg1, s32 arg2) {
    V3 f;
    V3 c;
    s32 temp;

    f.x                          = M2C_FIELD(arg0, s16 *, 0) << 0xC;
    f.y                          = M2C_FIELD(arg0, s16 *, 2) << 0xC;
    f.z                          = M2C_FIELD(arg0, s16 *, 4) << 0xC;
    c.x                          = 0x19000;
    c.y                          = 0x19000;
    c.z                          = 0x19000;
    temp                         = (s32) func_02096828(&data_0210930c, f, c, 0xB, arg1, arg2);
    M2C_FIELD(temp, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, u8 *, 8);
    return 0;
}
