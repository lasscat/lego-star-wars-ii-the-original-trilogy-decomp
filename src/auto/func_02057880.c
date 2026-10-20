#include "m2c.h"

extern void *func_020aaeb4();

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

void func_02057880(s32 arg0, s16 *arg1) {
    Vec3 scaled = {arg1[0] << 12, arg1[1] << 12, arg1[2] << 12};
    Vec3 pos    = scaled;
    void *g     = func_020aaeb4();
    if ((s8 *) g + 0x2bc != (s8 *) &pos) {
        M2C_FIELD(g, s32 *, 0x2bc) = pos.x;
        M2C_FIELD(g, s32 *, 0x2c0) = pos.y;
        M2C_FIELD(g, s32 *, 0x2c4) = pos.z;
    }
}
