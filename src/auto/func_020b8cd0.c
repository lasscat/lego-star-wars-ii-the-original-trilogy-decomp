/* Reconstructed from USA ARM9 at 0x020b8cd0 (92 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205e624(void *, M2C_UNK, M2C_UNK);    /* extern */
extern s32 data_0210daf0;

void func_020b8cd0(s32 arg0) {
    void *temp_r4;
    u8 *temp_r1;

    if (arg0 == 0xFF) {
        return;
    }
    temp_r4 = data_0210daf0 + 0x3C + arg0 * 0x24;
    func_0205e624(temp_r4, 0, 0x24);
    M2C_FIELD(temp_r4, u8 *, 0x8) = 0xFF;
    temp_r1                       = (u8 *) temp_r4 + 0x21;
    temp_r1[0] &= ~3;
    temp_r1[0] &= ~0xC;
    temp_r1[0] &= ~0x30;
}
