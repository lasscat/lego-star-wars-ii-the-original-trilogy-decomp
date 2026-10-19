#include "m2c.h"
typedef struct {
    s32 x, y, z;
} V3;
extern M2C_UNK data_0210930c;
M2C_UNK func_02096828(M2C_UNK *, V3, V3, s32, u8, u8);
s32 func_02051ef0(void *arg0, s32 arg1, s32 arg2) {
    V3 a;
    V3 b;
    V3 v;
    void *temp;
    s32 u;
    s32 w;
    a.x                         = M2C_FIELD(arg0, s16 *, 0) << 0xC;
    a.y                         = M2C_FIELD(arg0, s16 *, 2) << 0xC;
    a.z                         = M2C_FIELD(arg0, s16 *, 4) << 0xC;
    u                           = ((u16 *) arg0)[4] << 0xC;
    w                           = ((u16 *) arg0)[5] << 0xC;
    b.x                         = u;
    b.y                         = w;
    b.z                         = u;
    temp                        = (void *) func_02096828(&data_0210930c, a, b, 3, arg1, arg2);
    M2C_FIELD(temp, u8 *, 0x2C) = 2;
    M2C_FIELD(temp, u8 *, 0x2D) = M2C_FIELD(arg0, u8 *, 0x14);
    M2C_FIELD(temp, u8 *, 0x1E) = M2C_FIELD(arg0, u8 *, 0x12);
    M2C_FIELD(temp, u8 *, 0x1F) = M2C_FIELD(arg0, u8 *, 0x13);
    {
        s32 vx;
        s32 vy;
        s32 vz;
        vx  = M2C_FIELD(arg0, s16 *, 0xC) << 0xC;
        vz  = M2C_FIELD(arg0, s16 *, 0x10) << 0xC;
        vy  = M2C_FIELD(arg0, s16 *, 0xE) << 0xC;
        v.x = vx;
        v.y = vy;
        v.z = vz;
    }
    {
        s32 *src = (s32 *) &v;
        if ((s32 *) ((u8 *) temp + 0x30) != src) {
            M2C_FIELD(temp, s32 *, 0x30) = M2C_FIELD(src, s32 *, 0);
            M2C_FIELD(temp, s32 *, 0x34) = M2C_FIELD(src, s32 *, 4);
            M2C_FIELD(temp, s32 *, 0x38) = M2C_FIELD(src, s32 *, 8);
        }
    }
    return 0;
}
