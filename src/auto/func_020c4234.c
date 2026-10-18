/* Reconstructed from USA ARM9 at 0x020c4234 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_01ffc45c(s32, void *, M2C_UNK);        /* extern */
extern M2C_UNK data_027e0c14;

void func_020c4234(void) {
    func_01ffc45c(*(s32 *) &data_027e0c14, (s32 *) &data_027e0c14 + 1, 0x3E);
    M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & ~1);
    M2C_FIELD(&data_027e0c14, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_027e0c14, s32 *, 0xFC) & ~2);
}
