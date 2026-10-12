#include "m2c.h"

M2C_UNK func_020cea74();                            /* extern */
extern s16 data_0211578c;

void func_020ce8e8(s32 arg0, s32 arg1) {
    if (((u32) ((arg1 & 0x7F00) << 8) >> 0x10) == 0x10) {
        data_0211578c = 1;
        return;
    }
    func_020cea74();
}
