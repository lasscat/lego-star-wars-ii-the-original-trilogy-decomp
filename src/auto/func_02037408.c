#include "m2c.h"

typedef struct {
    s32 x, y, z;
} V3;

void func_02037408(void *arg0) {
    V3 v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    {
        s32 *src  = (s32 *) &v;
        s32 *dest = (s32 *) ((u8 *) (void *) M2C_FIELD(arg0, s32 *, 4) + 0x60);
        if (dest != src) {
            dest[0] = src[0];
            dest[1] = src[1];
            dest[2] = src[2];
        }
    }
}
