#include "m2c.h"

M2C_UNK func_020a0370(s32, s32);                    /* extern */
M2C_UNK func_020a99a8();                            /* extern */
s32 func_020aaeb4();                                /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02109358;

void func_02058874(void) {
    func_020a0370(func_020aaeb4(), *((M2C_UNK *) ((s8 *) &data_02109358 + (M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 4))));
    func_020aaeb4();
    func_020a99a8();
}
