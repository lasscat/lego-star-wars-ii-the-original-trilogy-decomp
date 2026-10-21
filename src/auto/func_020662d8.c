#include "m2c.h"

extern void func_02066238(void *arg0, u8 *arg1);

void func_020662d8(void *arg0, u32 *arg1, s32 arg2, u16 *arg3, s32 arg4) {
    s32 size;

    if (arg2-- == 0) {
        return;
    }
    do {
        s32 words;
        s32 cnt;
        u32 *src;

        size  = M2C_FIELD(arg0, s32 *, 0x28);
        src   = (u32 *) (((*arg3 & 0x3ff) * size) + arg4);
        words = size / 4;
        cnt   = words - 1;
        if (words != 0) {
            do {
                *arg1++ = *src++;
            } while (cnt--);
        }
        if (*arg3 & 0x400) {
            func_02066238(arg0, (u8 *) arg1 - M2C_FIELD(arg0, s32 *, 0x28));
        }
        arg3 += M2C_FIELD(arg0, s32 *, 0x24);
    } while (arg2--);
}
