#include "m2c.h"

M2C_UNK func_020ad528(M2C_UNK *);                   /* extern */
M2C_UNK func_020ad7a4(M2C_UNK);                     /* extern */
M2C_UNK func_020ad8b4(s32);                         /* extern */
M2C_UNK func_020addf0(M2C_UNK);                     /* extern */
s32 func_020aedc8();                                /* extern */
s32 func_020d7a84(M2C_UNK *);                       /* extern */
extern M2C_UNK data_02100104;
extern M2C_UNK data_02100184;
extern M2C_UNK data_0210019c;
extern M2C_UNK data_0210b320;
extern M2C_UNK func_020aeda0;

s32 func_020aecfc(void) {
    s32 temp_r0;

    M2C_FIELD(&data_0210b320, s32 *, 0x30) = 0;
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0xE;
    func_020ad7a4(3);
    temp_r0 = func_020d7a84(&func_020aeda0);
    if (temp_r0 == 0) {
        return func_020aedc8();
    }
    if (temp_r0 != 2) {
        func_020ad528(&data_02100184);
        func_020ad8b4(temp_r0);
        return 0;
    }
    func_020addf0(0xF);
    if (M2C_FIELD(&data_0210b320, s32 *, 0x30) == 0) {
        func_020ad528(&data_0210019c);
        return func_020aedc8();
    }
    func_020ad528(&data_02100104);
    return 0;
}
