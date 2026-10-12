#include "m2c.h"

M2C_UNK func_020016c0();                            /* extern */
extern s32 data_027e02a0;

void func_020016f0(void) {
    if (data_027e02a0 == 0) {
        return;
    }
    do {
        func_020016c0();
    } while (data_027e02a0 != 0);
}
