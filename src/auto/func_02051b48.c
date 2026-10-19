#include "m2c.h"
typedef struct {
    s32 x, y, z;
} V3;
extern M2C_UNK data_0210930c;
M2C_UNK func_02096828(M2C_UNK *, V3, V3, s32, u8, u8);
s32 func_02051b48(void *arg0, s32 arg1, s32 arg2) {
    V3 a;
    V3 b;
    M2C_UNK temp;
    s32 u;
    a.x                          = M2C_FIELD(arg0, s16 *, 0) << 0xC;
    a.y                          = M2C_FIELD(arg0, s16 *, 2) << 0xC;
    a.z                          = M2C_FIELD(arg0, s16 *, 4) << 0xC;
    u                            = ((u16 *) arg0)[4] << 0xC;
    b.x                          = u;
    b.y                          = u;
    b.z                          = u;
    temp                         = func_02096828(&data_0210930c, a, b, 2, arg1, arg2);
    M2C_FIELD(temp, u8 *, 0x2C)  = 1;
    M2C_FIELD(temp, u8 *, 0x2D)  = M2C_FIELD(arg0, u8 *, 0xE);
    M2C_FIELD(temp, u8 *, 0x1E)  = M2C_FIELD(arg0, u8 *, 0xC);
    M2C_FIELD(temp, u8 *, 0x1F)  = M2C_FIELD(arg0, u8 *, 0xD);
    M2C_FIELD(temp, u8 *, 0x2E)  = M2C_FIELD(arg0, u8 *, 0xF);
    M2C_FIELD(temp, u8 *, 0x2F)  = M2C_FIELD(arg0, u8 *, 0x10);
    M2C_FIELD(temp, s16 *, 0x30) = M2C_FIELD(arg0, s16 *, 0xA);
    return 0;
}
