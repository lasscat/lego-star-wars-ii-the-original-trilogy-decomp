#include "m2c.h"

M2C_UNK func_020c3504();                            /* extern */
extern M2C_UNK *data_021012ec;
extern M2C_UNK *data_021012f0;
extern M2C_UNK data_02112628;
extern M2C_UNK func_020c3400;
extern M2C_UNK func_020c3490;

void func_020c33a8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(&data_02112628, s32 *, 0xC)  = arg0;
    M2C_FIELD(&data_02112628, s32 *, 0x10) = arg1;
    M2C_FIELD(&data_02112628, s32 *, 0x14) = arg2;
    M2C_FIELD(&data_02112628, s32 *, 0x18) = arg3;
    func_020c3504();
    if (arg4 == 0) {
        return;
    }
    data_021012ec = &func_020c3400;
    data_021012f0 = &func_020c3490;
}
