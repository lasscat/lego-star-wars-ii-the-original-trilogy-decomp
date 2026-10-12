#include "m2c.h"

M2C_UNK func_020120ac(s32);                         /* extern */
M2C_UNK func_0205e84c(s32);                         /* extern */
M2C_UNK func_020e47fc(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK func_02024550;

s32 func_020245b4(s32 arg0) {
    func_020e47fc(arg0 + 0x220, 2, 8, &func_02024550);
    func_020120ac(arg0);
    func_0205e84c(arg0);
    return arg0;
}
