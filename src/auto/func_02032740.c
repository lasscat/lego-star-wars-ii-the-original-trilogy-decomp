#include "m2c.h"

M2C_UNK func_02005854(void *, u8, s32, M2C_UNK, s32); /* extern */
s32 func_02062ae4(M2C_UNK);                         /* extern */
extern M2C_UNK data_020f6bac;

s32 func_02032740(void *arg0, s32 arg1, M2C_UNK arg2) {
    s32 var_r2;
    void *temp_r0;
    void *temp_r1;

    if (arg1 == 0xB) {
        var_r2 = 0;
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0xC) & 2) {
            var_r2 = func_02062ae4(0xC);
        }
        temp_r0 = M2C_FIELD(arg0, void **, 4);
        func_02005854(temp_r0, *((u8 *) ((s8 *) &data_020f6bac + (M2C_FIELD(temp_r0, u8 *, 0x6C3) * 0x24))), var_r2, arg2,
                      M2C_FIELD(arg0, s32 *, 0x10));
        M2C_FIELD(arg0, s8 *, 0x16)      = 1;
        temp_r1                          = M2C_FIELD(arg0, void **, 4);
        M2C_FIELD(temp_r1, u16 *, 0x186) = (u16) (M2C_FIELD(temp_r1, u16 *, 0x186) & ~8);
        M2C_FIELD(arg0, u8 *, 0xC)       = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 1);
        return 1;
    }
    return 0;
}
