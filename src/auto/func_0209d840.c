#include "m2c.h"

extern u16 data_020f7758[];

M2C_UNK func_0205e624(M2C_UNK *, M2C_UNK, s32); /* extern */

s16 func_0209d840(s8 *a0, u8 a1, u32 a2) {
    s16 buf[3];
    u16 i;
    u8 j;

    func_0205e624((M2C_UNK *) buf, -1, 6);
    for (i = 0; i < 30; i++) {
        if (a0[i + 6] == a1) {
            u8 k;
            for (j = 0; j < 2; j++) {
                s16 v = buf[j];
                if (v == -1 || data_020f7758[v] < data_020f7758[i]) {
                    for (k = j; k < 1; k++) {
                        buf[k + 1] = buf[k];
                    }
                    buf[j] = i;
                    break;
                }
            }
        }
    }
    if (buf[a2] == -1) {
        return -1;
    }
    return buf[a2] + 301;
}
