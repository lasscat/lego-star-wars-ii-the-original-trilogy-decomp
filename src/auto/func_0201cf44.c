#include "m2c.h"

u32 func_0201cf44(s32 *arg0) {
    u32 i;

    for (i = 0; i < 8; i++) {
        if (arg0[i] == 0) {
            return i;
        }
    }
    return 0xFFFF;
}
