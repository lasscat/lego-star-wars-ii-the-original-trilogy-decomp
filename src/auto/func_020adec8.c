#include "m2c.h"

M2C_UNK func_020ad528(M2C_UNK *);                   /* extern */
M2C_UNK func_020ad8b4();                            /* extern */
M2C_UNK func_020addf0(M2C_UNK);                     /* extern */
s32 func_020d7094(M2C_UNK *);                       /* extern */
extern M2C_UNK data_0210009c;
extern M2C_UNK data_021000b4;
extern M2C_UNK data_0210b320;
extern M2C_UNK func_020adf4c;

s32 func_020adec8(void) {
    s32 temp_r0;

    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x2F;
    M2C_FIELD(&data_0210b320, s32 *, 0x30) = 0;
    temp_r0                                = func_020d7094(&func_020adf4c);
    if (temp_r0 == 0) {
        func_020ad528(&data_0210009c);
        return 1;
    }
    if (temp_r0 != 2) {
        func_020ad8b4();
        return 0;
    }
    func_020ad528(&data_021000b4);
    func_020addf0(0x30);
    if (M2C_FIELD(&data_0210b320, s32 *, 0x30) == 0) {
        return 1;
    }
    return 0;
}
