/* Reconstructed from USA ARM9 at 0x0204a880 (88 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02073034();                                /* extern */
extern M2C_UNK data_021027f8;
extern s32 data_027e02a8;

s32 func_0204a880(void *arg0) {
    if (!(data_027e02a8 & 0x40)) {
        if (M2C_FIELD(arg0, u8 *, 0xC) == M2C_FIELD(&data_021027f8, u8 *, 0x2A)) {
            return 1;
        }
    } else {
        if ((s32) M2C_FIELD(arg0, u8 *, 0xC) < func_02073034()) {
            return 1;
        }
    }
    return 0;
}
