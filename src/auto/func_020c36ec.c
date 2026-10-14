#include "m2c.h"

M2C_UNK func_020c3850();                            /* extern */
extern M2C_UNK *data_021012f4;
extern M2C_UNK *data_021012f8;
extern M2C_UNK data_02112644;
extern M2C_UNK func_020c3740;
extern M2C_UNK func_020c380c;

void func_020c36ec(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(&data_02112644, s32 *, 8)    = arg0;
    M2C_FIELD(&data_02112644, s32 *, 0xC)  = arg1;
    M2C_FIELD(&data_02112644, s32 *, 0x10) = arg2;
    func_020c3850();
    if (arg3 == 0) {
        return;
    }
    data_021012f4 = &func_020c3740;
    data_021012f8 = &func_020c380c;
}
