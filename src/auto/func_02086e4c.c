/* Reconstructed from USA ARM9 at 0x02086e4c (84 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02086e4c(s32 arg0, u32 arg1) {
    u32 v;

    v = arg1;
    if (arg1 > 0x15) {
        switch (arg1) {
            case 0x16:
                v = 0;
                break;
            case 0x17:
                v = 5;
                break;
            case 0x18:
                v = 0xA;
                break;
        }
    }
    return ((M2C_FIELD((arg0 + (((s32) v >> 5) * 4)), s32 *, 0x451C) & (1 << (v & 0x1F))) != 0);
}
