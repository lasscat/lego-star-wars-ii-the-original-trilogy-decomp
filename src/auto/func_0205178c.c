#include "m2c.h"

typedef struct {
    s32 x, y, z;
} V3;

extern M2C_UNK data_0210930c;

M2C_UNK func_02096828(M2C_UNK *, V3, V3, s32, u8, u8);

s32 func_0205178c(void *arg0, s32 arg1, s32 arg2) {
    V3 a;
    V3 b;
    M2C_UNK temp;

    a.x                         = M2C_FIELD(arg0, s16 *, 0) << 0xC;
    a.y                         = M2C_FIELD(arg0, s16 *, 2) << 0xC;
    a.z                         = M2C_FIELD(arg0, s16 *, 4) << 0xC;
    b.x                         = ((u16 *) arg0)[4] << 0xC;
    b.y                         = ((u16 *) arg0)[5] << 0xC;
    b.z                         = ((u16 *) arg0)[6] << 0xC;
    temp                        = func_02096828(&data_0210930c, a, b, 8, arg1, arg2);
    M2C_FIELD(temp, u8 *, 0x3B) = M2C_FIELD(arg0, u8 *, 0xE);
    return 0;
}
