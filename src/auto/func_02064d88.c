#include "m2c.h"

extern u8 data_021044fc[];

void func_02064d88(u32 a0, u32 a1, u32 a2) {
    s32 end;
    s32 mask;
    u8 byte;

    end = a0 + a1;
    if (a0 >= end) {
        return;
    }
    do {
        u32 idx = a0 >> 3;
        u32 bit = a0 & 7;
        if (bit == 0 && end - a0 >= 8) {
            mask = 0xff;
            a0 += 8;
        } else {
            mask = 1u << bit;
            a0 += 1;
        }
        byte                           = data_021044fc[(a2 << 7) + idx];
        data_021044fc[(a2 << 7) + idx] = byte | mask;
    } while (a0 < end);
}
