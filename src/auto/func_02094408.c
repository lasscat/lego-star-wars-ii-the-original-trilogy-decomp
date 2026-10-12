#include "m2c.h"

M2C_UNK func_0205d72c(s32);                         /* extern */
M2C_UNK func_02094610();                            /* extern */
M2C_UNK func_020e47fc(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK func_02064f68;

s32 func_02094408(s32 arg0) {
    func_02094610();
    func_020e47fc(arg0 + 0xB0, 4, 0x10, &func_02064f68);
    func_0205d72c(arg0 + 0x70);
    func_0205d72c(arg0 + 0x38);
    func_0205d72c(arg0);
    return arg0;
}
