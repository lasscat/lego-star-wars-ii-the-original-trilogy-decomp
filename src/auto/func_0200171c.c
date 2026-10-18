/* Reconstructed from USA ARM9 at 0x0200171c (92 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_02103374;
extern s32 data_027e02a8;

void func_0200171c(s32 arg0) {
    if (arg0 != 0) {
        data_027e02a8 |= 0x200;
        return;
    }
    data_027e02a8 &= ~0x200;
    *(u16 *) 0x04000304 |= 0x8000;
    M2C_FIELD(&data_02103374, u8 *, 0x722) = 0x80;
    M2C_FIELD(&data_02103374, u8 *, 0xE46) = 0x80;
}
