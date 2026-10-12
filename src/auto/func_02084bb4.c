#include "m2c.h"

M2C_UNK func_02062748(s32);                         /* extern */
M2C_UNK func_020654a8(s32);                         /* extern */
M2C_UNK func_0206d5a8(s32);                         /* extern */

s32 func_02084bb4(s32 arg0) {
    func_020654a8(arg0 + 0xCD8);
    func_0206d5a8(arg0 + 0xCAC);
    func_0206d5a8(arg0 + 0xC80);
    func_02062748(arg0 + 0x30);
    func_02062748(arg0 + 0x28);
    return arg0;
}
