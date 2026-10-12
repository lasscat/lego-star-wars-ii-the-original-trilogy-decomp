#include "m2c.h"

M2C_UNK func_0205e84c(s32);                         /* extern */
M2C_UNK func_020654a8(s32);                         /* extern */
M2C_UNK func_020e47fc(s32, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK func_0206afa4;

s32 func_020749d4(s32 arg0) {
    func_020e47fc(arg0 + 0x74, 3, 0xC, &func_0206afa4);
    func_020654a8(arg0 + 0x40);
    func_0205e84c(arg0);
    return arg0;
}
