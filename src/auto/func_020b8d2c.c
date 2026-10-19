/* Reconstructed from USA ARM9 at 0x020b8d2c (84 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205e624(void *, M2C_UNK, M2C_UNK);    /* extern */
extern s32 data_0210daf0;

void func_020b8d2c(s32 arg0) {
    void *temp_r4;

    if (arg0 == 0xFF) {
        return;
    }
    temp_r4 = data_0210daf0 + 0x4BC + (arg0 << 5);
    func_0205e624(temp_r4, 0, 0x20);
    M2C_FIELD(temp_r4, u8 *, 0xA)   = 0xFF;
    M2C_FIELD(temp_r4, u8 *, 0x11)  = (u8) (M2C_FIELD(temp_r4, u8 *, 0x11) & ~0xC);
    M2C_FIELD(temp_r4, s16 *, 0x12) = 0x400;
}
