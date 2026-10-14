#include "m2c.h"

M2C_UNK func_020cea74();                            /* extern */
M2C_UNK func_020d3f8c(s32);                         /* extern */
M2C_UNK func_020d6178(M2C_UNK, M2C_UNK);            /* extern */

void func_020d60e4(void) {
    s32 temp_r0;

    temp_r0 = (s32) (*(u16 *) 0x027FFFA8 & 0x8000) >> 0xF;
    if (temp_r0 != 0) {
        func_020d3f8c(temp_r0);
    }
    func_020d6178(1, 1);
    func_020cea74();
}
