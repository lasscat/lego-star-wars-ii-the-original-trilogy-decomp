#include "m2c.h"
typedef struct {
    s32 x, y, z;
} V3;
extern M2C_UNK data_0210930c;
M2C_UNK func_02096828(M2C_UNK *, V3, V3, s32, u8, u8);
M2C_UNK func_0209820c(void *, u8, u8, void *, M2C_UNK);
s32 func_02052d14(void *arg0, s32 arg1, s32 arg2) {
    V3 a;
    V3 b;
    M2C_UNK temp;
    a.x  = M2C_FIELD(arg0, s16 *, 0) << 0xC;
    a.y  = M2C_FIELD(arg0, s16 *, 2) << 0xC;
    a.z  = M2C_FIELD(arg0, s16 *, 4) << 0xC;
    b.x  = ((u16 *) arg0)[4] << 0xC;
    b.y  = ((u16 *) arg0)[5] << 0xC;
    b.z  = ((u16 *) arg0)[6] << 0xC;
    temp = func_02096828(&data_0210930c, a, b, 0xC, arg1, arg2);
    func_0209820c(temp, M2C_FIELD(arg0, u8 *, 0xE), M2C_FIELD(arg0, u8 *, 0xF), (u8 *) ((s8 *) arg0 + 0x12),
                  M2C_FIELD(arg0, u8 *, 0x10) != 0);
    M2C_FIELD(temp, u8 *, 0x2D) = M2C_FIELD(arg0, u8 *, 0x11) != 0;
    return 0;
}
