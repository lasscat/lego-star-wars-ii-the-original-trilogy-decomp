/* Reconstructed from USA ARM9 at 0x02053ce4 (92 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

u16 *func_020531d8();                               /* extern */
s32 func_020539c8();                                /* extern */

s32 func_02053ce4(M2C_UNK arg0) {
    s32 var_r0;
    u32 temp_r0;

    if (func_020539c8(arg0) != 0) {
        if (((u32) (*func_020531d8(arg0) << 0x10) >> 0x1E) == 0) {
            var_r0 = 0x10;
        } else {
            var_r0 = 0x20;
        }
        return var_r0;
    }
    temp_r0 = (u32) (*func_020531d8(arg0) << 0x10) >> 0x1E;
    switch (temp_r0) {
        case 0:
        case 2:
            return 0x20;
    }
    return 0x40;
}
