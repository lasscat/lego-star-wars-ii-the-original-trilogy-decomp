#include "m2c.h"

s32 func_02065be8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_02066118(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020661b4(s32, s32);                    /* extern */
s32 func_02066708(s32);                             /* extern */
M2C_UNK func_0207ee68(void *);                      /* extern */
s32 func_0207ef78();                                /* extern */

s32 func_0207edb0(void *arg0) {
    s32 temp_r0;

    temp_r0 = func_0207ef78();
    if (temp_r0 == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + temp_r0);
    func_02066118(M2C_FIELD(arg0, s32 *, 8), 2, 0xA, 0x1E);
    func_02066118(M2C_FIELD(arg0, s32 *, 8), 2, 0xB, 0x1E);
    func_02066118(M2C_FIELD(arg0, s32 *, 8), 2, 0xC, 0x1E);
    func_020661b4(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0x30));
    M2C_FIELD(arg0, s32 *, 0x2C) = func_02065be8(M2C_FIELD(arg0, s32 *, 8), 0xF0, 0x80, 0x55, func_02066708(0x157), 1);
    func_0207ee68(arg0);
    return 1;
}
