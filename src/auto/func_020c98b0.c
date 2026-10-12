#include "m2c.h"

extern s16 data_02101538;
extern s16 data_02115364;

void func_020c98b0(void) {
    s32 temp_ip;

    temp_ip = *(s32 *)0x04000000;
    data_02101538 = 0;
    data_02115364 = (s16) ((u32) (temp_ip & 0x30000) >> 0x10);
    *(s32 *)0x04000000 = temp_ip & ~0x30000;
}
