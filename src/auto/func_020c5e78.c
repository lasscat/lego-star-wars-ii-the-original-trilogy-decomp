#include "m2c.h"

M2C_UNK func_01ffc3d8();                            /* extern */
M2C_UNK func_020c8b9c(M2C_UNK *, s32);              /* extern */
s32 func_020cb038(M2C_UNK *);                       /* extern */
s32 func_020cb068(s32);                             /* extern */

void func_020c5e78(s32 arg0, s32 arg1) {
    u8 sp0[64];

    func_01ffc3d8();
    M2C_FIELD((void *) 0x04000440, s32 *, 0)    = 0;
    M2C_FIELD((void *) 0x04000440, s32 *, 4)    = 0;
    M2C_FIELD((void *) 0x04000440, s32 *, 0x14) = 0;
    if (arg0 != 0) {
        do {

        } while (func_020cb038(sp0) != 0);
        func_020c8b9c(sp0, arg0);
    }
    if (arg1 != 0) {
        do {

        } while (func_020cb068(arg1) != 0);
    }
    M2C_FIELD((void *) 0x04000448, s32 *, 0)  = 1;
    M2C_FIELD((void *) 0x04000448, s32 *, -8) = 2;
}
