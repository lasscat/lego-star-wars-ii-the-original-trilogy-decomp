#include "m2c.h"

void func_020a98f8(void *arg0, void *arg1) {
    if ((arg0 + 0x1F0) == arg1) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x1F0) = (s32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x1F4) = (s32) M2C_FIELD(arg1, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x1F8) = (s32) M2C_FIELD(arg1, s32 *, 8);
}
