#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

extern M2C_UNK data_0210930c;
M2C_UNK func_02096828(M2C_UNK *, V3, V3, s32, u8, u8);
M2C_UNK func_02097b98(void *, u8, u16, M2C_UNK);

s32 func_02050fbc(void *arg0, s32 arg1, s32 arg2) {
    V3 f;
    V3 c;
    void *temp;

    f.x                         = M2C_FIELD(arg0, s16 *, 0) << 0xC;
    f.y                         = M2C_FIELD(arg0, s16 *, 2) << 0xC;
    f.z                         = M2C_FIELD(arg0, s16 *, 4) << 0xC;
    c.x                         = M2C_FIELD(arg0, u16 *, 0xA) << 0xC;
    c.y                         = M2C_FIELD(arg0, u16 *, 0xC) << 0xC;
    c.z                         = M2C_FIELD(arg0, u16 *, 0xE) << 0xC;
    temp                        = (void *) func_02096828(&data_0210930c, f, c, 6, (u8) arg1, (u8) arg2);
    M2C_FIELD(temp, u8 *, 0x1E) = (u8) M2C_FIELD(arg0, u8 *, 0x13);
    func_02097b98(temp, M2C_FIELD(arg0, u8 *, 0x12), M2C_FIELD(arg0, u16 *, 8), (M2C_FIELD(arg0, u8 *, 0x14) == 1) ? 1 : 0);
    return 0;
}
