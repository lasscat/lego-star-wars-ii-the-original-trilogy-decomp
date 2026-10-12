#include "m2c.h"

M2C_UNK func_02004b78(void *, M2C_UNK);             /* extern */

void func_02038314(void *arg0) {
    void *temp_r0;

    if (M2C_FIELD(arg0, u8 *, 0xD) != 1) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, void **, 4);
    if (((u32) (M2C_FIELD(temp_r0, u16 *, 0x14E) << 0x1E) >> 0x1F) != 1) {
        return;
    }
    func_02004b78(temp_r0, 5);
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 1);
}
