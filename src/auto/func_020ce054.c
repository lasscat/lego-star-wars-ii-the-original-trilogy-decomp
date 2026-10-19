/* Reconstructed from USA ARM9 at 0x020ce054 (168 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020cd8c0();                                /* extern */
extern M2C_UNK data_021156a0;

s32 func_020ce054(u32 arg0) {
    switch (arg0) {
        case 0:
            return 0x0211EFA0;
        case 2:
            if ((M2C_FIELD(&data_021156a0, s32 *, 4) == 0) || ((func_020cd8c0() & 3) == 1)) {
                return 0;
            }
            return 0x023E0000;
        case 3:
            return 0x01FFD5C0;
        case 4:
            return 0x027E0EA0;
        case 5:
            return 0x027FF000;
        case 6:
            return 0x037F8000;
        default:
            return 0;
    }
}
