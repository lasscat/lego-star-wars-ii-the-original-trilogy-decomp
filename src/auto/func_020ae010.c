#include "m2c.h"

M2C_UNK func_020ad528(M2C_UNK *);                   /* extern */
M2C_UNK func_020ad8b4(s32);                         /* extern */
M2C_UNK func_020addf0(M2C_UNK);                     /* extern */
M2C_UNK func_020af0b4();                            /* extern */
s32 WM_Reset(M2C_UNK *);                       /* extern */
extern M2C_UNK data_021000e8;
extern M2C_UNK data_02100104;
extern M2C_UNK data_0210b320;
extern M2C_UNK func_020ae094;

s32 func_020ae010(void) {
    s32 temp_r0;

    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x1C;
    M2C_FIELD(&data_0210b320, s32 *, 0x30) = 0;
    temp_r0                                = WM_Reset(&func_020ae094);
    if (temp_r0 != 2) {
        func_020af0b4();
        func_020ad528(&data_021000e8);
        func_020ad8b4(temp_r0);
        return 0;
    }
    func_020addf0(0x1D);
    if (M2C_FIELD(&data_0210b320, s32 *, 0x30) == 0) {
        return 1;
    }
    func_020ad528(&data_02100104);
    return 0;
}
