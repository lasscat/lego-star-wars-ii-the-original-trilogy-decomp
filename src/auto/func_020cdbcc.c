#include "m2c.h"

void *func_020cd068(void *);                        /* extern */
M2C_UNK func_020cd4e4();                            /* extern */

void func_020cdbcc(void *arg0) {
    void *temp_r0;

    if (M2C_FIELD(arg0, s32 *, 0x88) == 0) {
        return;
    }
    do {
        temp_r0 = func_020cd068(arg0 + 0x88);
        M2C_FIELD(temp_r0, s32 *, 0xC) = 0;
        M2C_FIELD(temp_r0, s32 *, 8) = 0;
        func_020cd4e4();
    } while (M2C_FIELD(arg0, s32 *, 0x88) != 0);
}
