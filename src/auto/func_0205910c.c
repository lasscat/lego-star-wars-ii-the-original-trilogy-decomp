#include "m2c.h"

M2C_UNK func_02060158(void **, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_020b04f0(M2C_UNK *, M2C_UNK, u8 *, M2C_UNK);        /* extern */
extern void *data_02102900;
extern M2C_UNK data_0210794c;
extern s32 data_027e02a8;

void func_0205910c(M2C_UNK arg0, u8 *arg1) {
    s32 var_r0;
    u8 buf[0x1c];

    if (data_027e02a8 & 0x40) {
        if (data_02102900 != NULL) {
            var_r0 = M2C_FIELD(data_02102900, s32 *, 4);
        } else {
            var_r0 = 0;
        }
        if (var_r0 != 4) {
            return;
        }
        buf[0] = *arg1;
        func_020b04f0(&data_0210794c, 0x32, buf, 0xFF);
    } else {
        if (data_02102900 != NULL) {
            var_r0 = M2C_FIELD(data_02102900, s32 *, 4);
        } else {
            var_r0 = 0;
        }
        if (var_r0 != 4) {
            return;
        }
        func_02060158(&data_02102900, 0, 0x19, 1, *arg1);
    }
}
