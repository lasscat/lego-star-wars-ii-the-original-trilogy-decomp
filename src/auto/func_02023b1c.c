/* Reconstructed from USA ARM9 at 0x02023b1c (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_02023b1c(void *arg0, void **arg1) {
    switch (M2C_FIELD(*arg1, u16 *, 0xC)) {
        case 1:
            if (M2C_FIELD(arg0, u8 *, 0x1BC) != 1) {
                M2C_FIELD(arg0, s32 *, 0x21C) = (s32) (M2C_FIELD(arg0, s32 *, 0x21C) + 1);
            }
            break;
        case 4:
            break;
    }
}
