/* Reconstructed from USA ARM9 at 0x0207c7d8 (92 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0207ca4c();                            /* extern */
M2C_UNK func_0207cab8();                            /* extern */
M2C_UNK func_0207cda0();                            /* extern */
M2C_UNK func_0207ce0c();                            /* extern */

s32 func_0207c7d8(s32 arg0, s32 arg1) {
    switch (arg1 - 0x1D) {
        case 0:
            func_0207ca4c(arg0);
            return 1;
        case 1:
            func_0207cab8(arg0);
            return 1;
        case 2:
            func_0207cda0(arg0);
            return 1;
        case 3:
            func_0207ce0c(arg0);
            return 1;
        default:
            return 0;
    }
}
