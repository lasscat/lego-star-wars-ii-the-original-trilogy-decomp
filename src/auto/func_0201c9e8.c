/* Reconstructed from USA ARM9 at 0x0201c9e8 (52 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

u32 func_0201c9e8(void *arg0) {
    u16 temp_r2;
    u32 var_r3;
    u32 var_ip;

    var_r3 = 0;
    var_ip = 0;
    do {
        temp_r2 = ((u16 *) arg0)[var_ip + 1];
        var_ip += 1;
        if (temp_r2 != 0xFFFF) {
            var_r3 += 1;
        }
    } while (var_ip < 4U);
    return var_r3;
}
