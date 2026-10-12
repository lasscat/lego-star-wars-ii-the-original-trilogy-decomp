#include "m2c.h"

M2C_UNK func_02054e78();                            /* extern */
extern s32 data_027e02a8;

void func_02054e58(s32 arg0) {
    if (!(data_027e02a8 & 0x800)) {
        return;
    }
    func_02054e78(arg0);
}
