#include "m2c.h"

M2C_UNK func_020654a8(s32);                         /* extern */
M2C_UNK func_020e47fc(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK func_0206afa4;

s32 func_02074a0c(s32 arg0) {
    func_020e47fc(arg0 + 0x74, 3, 0xC, &func_0206afa4);
    func_020654a8(arg0 + 0x40);
    return arg0;
}
