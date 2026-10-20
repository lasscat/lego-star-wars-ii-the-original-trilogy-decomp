#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

extern M2C_UNK *func_020aaeb4(void);

void func_0205780c(M2C_UNK arg0, s16 *arg1) {
    Vec3 t;
    Vec3 u;
    M2C_UNK *g;

    t.x = arg1[0] << 12;
    t.y = arg1[1] << 12;
    t.z = arg1[2] << 12;
    u   = t;
    g   = func_020aaeb4();
    if ((s32 *) ((u8 *) g + 0x2b0) != (s32 *) &u) {
        M2C_FIELD(g, s32 *, 0x2b0) = u.x;
        M2C_FIELD(g, s32 *, 0x2b4) = u.y;
        M2C_FIELD(g, s32 *, 0x2b8) = u.z;
    }
}
