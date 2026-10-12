#include "m2c.h"

M2C_UNK func_020654a8(s32);                         /* extern */
M2C_UNK func_0206d5a8(s32);                         /* extern */

s32 func_0209d9dc(s32 arg0) {
    func_0206d5a8(arg0 + 0x68);
    func_020654a8(arg0 + 0x38);
    return arg0;
}
