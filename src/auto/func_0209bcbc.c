#include "m2c.h"

void func_0209bcbc(s32 arg0, s32 arg1) {
    s16 *p;

    if (*(u8 *) (arg0 + 0x50) == 0) {
        return;
    }
    p  = (s16 *) (arg0 + 0x24) + arg1;
    *p = *p + 1;
}
