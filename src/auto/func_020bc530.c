/* Reconstructed from USA ARM9 at 0x020bc530 (56 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_020bc530(s32 *arg0, s32 arg1) {
    s32 t;
    s32 var_r3;

    var_r3 = 0;
    do {
        t = arg0[0x13 + var_r3];
        if (t == arg1) {
            return;
        }
        if (t == 0) {
            break;
        }
        var_r3 += 1;
    } while (var_r3 < 6);
    if (var_r3 != 6) {
        arg0[0x13 + var_r3] = arg1;
    }
}
