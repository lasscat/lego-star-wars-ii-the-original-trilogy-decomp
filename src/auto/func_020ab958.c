#include "m2c.h"

M2C_UNK func_020ab9cc(M2C_UNK *, M2C_UNK *, M2C_UNK);   /* extern */
M2C_UNK func_020abad0(M2C_UNK *, M2C_UNK *, M2C_UNK);   /* extern */

s32 func_020ab958(void *arg0) {
    void *temp_r3;
    void *temp_r4;
    s32 temp_r1;

    temp_r3 = (u8 *) M2C_FIELD(arg0, void **, 4) + M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0xe);
    temp_r4 = (u8 *) M2C_FIELD(arg0, void **, 4) + M2C_FIELD(temp_r3, s32 *, 0xc);
    temp_r4 = (u8 *) temp_r4 + M2C_FIELD(temp_r4, s32 *, 8);
    temp_r1 = (u8 *) temp_r4 + M2C_FIELD(temp_r4, u16 *, 0xa);
    temp_r1 = (u8 *) temp_r4 + M2C_FIELD(temp_r1, s32 *, 8);
    temp_r1 = M2C_FIELD(temp_r1, s32 *, 0x14);
    if ((u16) temp_r1 != (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0xc), s32 *, 8)) {
        func_020ab9cc(arg0, temp_r4, M2C_FIELD(arg0, void **, 0xc));
        func_020abad0(arg0, temp_r4, M2C_FIELD(arg0, void **, 0xc));
    }
    return 1;
}
