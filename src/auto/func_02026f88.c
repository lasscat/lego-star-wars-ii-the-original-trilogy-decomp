#include "m2c.h"

M2C_UNK func_020c8228(M2C_UNK *, s16, s16);         /* extern */
M2C_UNK func_020c8244(M2C_UNK *, s16, s16);         /* extern */
M2C_UNK func_020c8260(M2C_UNK *, void *, void *);   /* extern */
extern M2C_UNK data_020f88c4;

void func_02026f88(void *arg0) {
    M2C_UNK sp0[9];
    s32 temp_r1_2;
    s32 temp_r2;
    u16 temp_r1;
    s32 var_r0;
    void *temp_r1_3;
    void *temp_r4;
    s32 *temp_r5;

    if (M2C_FIELD(arg0, s32 *, 8) & 0x10) {
        var_r0 = M2C_FIELD(arg0, u8 *, 0xAE);
    } else {
        var_r0 = -1;
    }
    if (var_r0 != 2) {
        return;
    }
    temp_r4                            = M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x2C);
    temp_r5                            = M2C_FIELD(arg0, s32 **, 0xB4);
    M2C_FIELD(arg0, volatile s32 *, 8) = (s32) (M2C_FIELD(arg0, volatile s32 *, 8) | 0x40);
    *temp_r5 &= ~2;
    temp_r2 = ((s32) M2C_FIELD(temp_r4, u16 *, 0x220) >> 4) * 2;
    func_020c8244((void *) ((s8 *) temp_r5 + 0x28), *((s16 *) ((s8 *) &data_020f88c4 + (temp_r2 * 2))),
                  *((s16 *) ((s8 *) &data_020f88c4 + ((temp_r2 + 1) * 2))));
    temp_r1 = M2C_FIELD(temp_r4, u16 *, 0x224);
    if ((s16) temp_r1 != 0) {
        temp_r1_2 = ((s32) temp_r1 >> 4) * 2;
        func_020c8228(sp0, *((s16 *) ((s8 *) &data_020f88c4 + (temp_r1_2 * 2))),
                      *((s16 *) ((s8 *) &data_020f88c4 + ((temp_r1_2 + 1) * 2))));
        temp_r1_3 = (void *) ((s8 *) temp_r5 + 0x28);
        func_020c8260(sp0, temp_r1_3, temp_r1_3);
    }
    M2C_FIELD(arg0, M2C_UNK(**)(s32 *), 0xEC)(M2C_FIELD(arg0, s32 **, 0xB4));
}
