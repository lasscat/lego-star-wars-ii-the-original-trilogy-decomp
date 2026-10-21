#include "m2c.h"

extern s32 func_0208d8cc(s32, s32);

s32 func_0208da0c(s32 a0, u16 *a1) {
    u8 i;
    for (i = 0; i < 5; i++) {
        u16 v = a1[0x374 + i];
        if (v != 0xfa) {
            if (func_0208d8cc(a0, v) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
