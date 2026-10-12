#include "m2c.h"

M2C_UNK func_020d2e28();                            /* extern */
extern s32 data_021173d8;

void func_020d2870(s32 arg0) {
    if (data_021173d8 != 0) {
        return;
    }
    data_021173d8 = 1;
    func_020d2e28(arg0);
}
