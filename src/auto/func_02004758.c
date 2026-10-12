#include "m2c.h"

M2C_UNK func_020045c8(void *);                      /* extern */
M2C_UNK func_0200c834(void *, M2C_UNK);             /* extern */

void func_02004758(void *arg0) {
    u8 temp_r1;
    u8 temp_r1_2;
    void *temp_r2;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x6C4);
    if (temp_r1 & 1) {
        return;
    }
    if (temp_r1 & 4) {
        return;
    }
    temp_r1_2 = M2C_FIELD(arg0, u8 *, 0x6C3);
    if ((temp_r1_2 != 0x26) && (temp_r1_2 != 0x27) && (M2C_FIELD(arg0, u8 *, 0x4E4) != 0)) {
        temp_r2 = M2C_FIELD(arg0, void **, 0x298);
        if (temp_r2 != NULL) {
            if (M2C_FIELD(temp_r2, u16 *, 0xAE) != 0xD) {
                return;
            }
            if (((u32) (M2C_FIELD(temp_r2, u16 *, 0x7A) << 0x1E) >> 0x1F) != 1) {
                return;
            }
            func_0200c834(arg0, 5);
            func_0200c834(arg0, 4);
            func_020045c8(arg0);
        }
    }
}
