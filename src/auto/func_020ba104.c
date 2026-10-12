#include "m2c.h"

M2C_UNK func_0205e6e0(void *, void *, M2C_UNK);     /* extern */
M2C_UNK func_020ba140();                            /* extern */
extern M2C_UNK data_021009a8;

void func_020ba104(u8 *arg0) {
    u8 temp_r2;

    temp_r2 = *arg0;
    if ((u32) temp_r2 < 2U) {
        func_0205e6e0(arg0 + 0xC, (M2C_UNK *)((s8 *)&data_021009a8 + (temp_r2 << 5)), 0x20);
        return;
    }
    if ((u32) temp_r2 >= 7U) {
        return;
    }
    func_020ba140();
}
