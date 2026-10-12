#include "m2c.h"

void func_02016b64(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x212) == 0x1A) {
        M2C_FIELD(arg0, s32 *, 0x194) = 0;
    }
}
