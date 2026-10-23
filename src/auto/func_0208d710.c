#include "m2c.h"

extern u16 *data_020ff4dc[];

u32 func_0208d710(u16 arg0) {
    u32 res = 0;
    u8 i;
    u16 j;

    for (i = 0; i < 7; i++) {
        for (j = 0; data_020ff4dc[i][j] != 0xFA; j++) {
            if (arg0 == data_020ff4dc[i][j]) {
                res |= 1 << i;
                break;
            }
        }
    }
    return res;
}
