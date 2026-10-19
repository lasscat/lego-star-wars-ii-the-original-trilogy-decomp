#include "m2c.h"
M2C_UNK func_020c8228(M2C_UNK *, s16, s16);
M2C_UNK func_020c8260(M2C_UNK *, void *, void *);
extern M2C_UNK data_020f88c4;
void func_02026f00(void *arg0) {
    M2C_UNK sp0[9];
    s32 *temp_r4;
    s32 temp_r2_2;
    s32 var_r1;
    void *temp_r1;
    void *p;
    if (M2C_FIELD(arg0, s32 *, 8) & 0x10) {
        var_r1 = M2C_FIELD(arg0, u8 *, 0xAE);
    } else {
        var_r1 = -1;
    }
    if (var_r1 != 3) {
        return;
    }
    temp_r4 = M2C_FIELD(arg0, s32 **, 0xB4);
    p       = M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x2C);
    *temp_r4 &= ~2;
    temp_r2_2 = ((s32) M2C_FIELD(p, u16 *, 0x220) >> 4) * 2;
    func_020c8228(sp0, *((s16 *) ((s8 *) &data_020f88c4 + (temp_r2_2 * 2))),
                  *((s16 *) ((s8 *) &data_020f88c4 + ((temp_r2_2 + 1) * 2))));
    temp_r1 = (void *) ((s8 *) temp_r4 + 0x28);
    func_020c8260(sp0, temp_r1, temp_r1);
}
