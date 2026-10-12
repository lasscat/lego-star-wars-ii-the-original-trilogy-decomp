#include "m2c.h"

M2C_UNK func_020cea74();                            /* extern */
extern s16 data_0211e45c;

void func_020ddbe0(s32 arg0, s32 arg1) {
    if ((arg1 & 0x3F) == 1) {
        data_0211e45c = 1;
        return;
    }
    func_020cea74();
}
