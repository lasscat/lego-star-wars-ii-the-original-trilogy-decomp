/* Reconstructed from USA ARM9 at 0x020594cc (56 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern s32 data_02104d90;

void func_020594cc(s32 arg0, u8 *arg1) {
    if (*arg1 != 0) {
        data_02104d90 &= ~4;
        data_02104d90 |= 4;
        return;
    }
    data_02104d90 &= ~4;
}
