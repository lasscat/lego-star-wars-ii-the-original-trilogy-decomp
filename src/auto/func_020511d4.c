#include "m2c.h"
typedef struct {
    s32 x, y, z;
} V3;
extern M2C_UNK data_0210930c;
M2C_UNK func_02096828(M2C_UNK *, V3, V3, s32, u8, u8);
M2C_UNK func_020976d0(void *, u8, M2C_UNK, u16);
s32 func_020511d4(void *arg0, s32 arg1, s32 arg2) {
    V3 a;
    V3 b;
    M2C_UNK temp;
    a.x = M2C_FIELD(arg0, s16 *, 0) << 0xC;
    a.y = M2C_FIELD(arg0, s16 *, 2) << 0xC;
    a.z = M2C_FIELD(arg0, s16 *, 4) << 0xC;
    b.x = ((u16 *) arg0)[4] << 0xC;
    b.y = ((u16 *) arg0)[5] << 0xC;
    b.z = ((u16 *) arg0)[6] << 0xC;
    if (M2C_FIELD(arg0, u8 *, 0x13) != 0) {
        b.y = 0xFFFFFF;
    }
    temp                        = func_02096828(&data_0210930c, a, b, 5, arg1, arg2);
    M2C_FIELD(temp, u8 *, 0x1D) = M2C_FIELD(arg0, u8 *, 0x11);
    M2C_FIELD(temp, u8 *, 0x1E) = M2C_FIELD(arg0, u8 *, 0x12);
    M2C_FIELD(temp, u8 *, 0x1F) = M2C_FIELD(arg0, u8 *, 0x13);
    func_020976d0(temp, M2C_FIELD(arg0, u8 *, 0x10), M2C_FIELD(arg0, u8 *, 0x14) != 0, M2C_FIELD(arg0, u16 *, 0xE));
    if (M2C_FIELD(arg0, u8 *, 0x14) == 2) {
        M2C_FIELD(temp, s8 *, 0x2C) = 1;
    }
    return 0;
}
