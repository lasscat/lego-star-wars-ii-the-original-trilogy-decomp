#include "m2c.h"

M2C_UNK func_020ad528(M2C_UNK *);       /* extern */
M2C_UNK func_020ad7a4(M2C_UNK);         /* extern */
M2C_UNK func_020ad8b4(s32);             /* extern */
M2C_UNK func_020addf0(M2C_UNK);         /* extern */
s32 WM_Disconnect(M2C_UNK *, u16);       /* extern */
extern M2C_UNK data_021003b8;
extern M2C_UNK data_021003d0;
extern M2C_UNK data_0210b320;
extern M2C_UNK func_020aee68;

s32 func_020aedc8(void) {
    s32 temp_r0;

    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0xA;
    M2C_FIELD(&data_0210b320, s32 *, 0x30) = 0;
    temp_r0                                = WM_Disconnect(&func_020aee68, 0);
    if (temp_r0 == 0) {
        return 1;
    }
    if (temp_r0 != 2) {
        if (M2C_FIELD(&data_0210b320, s32 *, 0x20) == 8) {
            func_020ad528(&data_021003b8);
            return 1;
        }
        func_020ad8b4(temp_r0);
        return 0;
    }
    func_020ad528(&data_021003d0);
    func_020ad7a4(3);
    func_020addf0(0xB);
    if (M2C_FIELD(&data_0210b320, s32 *, 0x30) == 0) {
        return 1;
    }
    return 0;
}
