#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec;

typedef struct {
    u8 pad[0x4c];
    s32 vals[4];
} Tbl;

extern M2C_UNK data_02104d90;
extern Tbl data_0210930c;

s32 func_02086204(M2C_UNK *, u16);
M2C_UNK func_02091b88(M2C_UNK *, u8, u8, Vec *, s32);

M2C_UNK func_02050c44(void *arg0) {
    Vec pos;
    u8 idx;
    u32 n;
    u32 i;
    s32 vz = M2C_FIELD(arg0, s16 *, 4) << 12;
    s32 vy = M2C_FIELD(arg0, s16 *, 2) << 12;
    s32 vx = M2C_FIELD(arg0, s16 *, 0) << 12;

    pos.x = vx;
    pos.y = vy;
    pos.z = vz;
    idx   = M2C_FIELD(arg0, u8 *, 8);
    if (func_02086204(&data_02104d90, 10) != 0) {
        n = 0;
        for (i = 0; i < 4; i++) {
            if (data_0210930c.vals[i] != 0) {
                n++;
            }
        }
        if (n >= 2) {
            return 0;
        }
    }
    return func_02091b88((M2C_UNK *) &data_0210930c, M2C_FIELD(arg0, u8 *, 9), idx, &pos, 1);
}
