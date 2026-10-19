/* Reconstructed from USA ARM9 at 0x02059244 (56 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern s32 data_02104d90;

void func_02059244(s32 arg0, u8 *arg1) {
    if (*arg1 != 0) {
        data_02104d90 &= ~2;
        data_02104d90 |= 2;
        return;
    }
    data_02104d90 &= ~2;
}
