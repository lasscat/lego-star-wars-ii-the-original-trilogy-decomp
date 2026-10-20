/* Reconstructed from USA ARM9 at 0x02037308 (44 bytes).
 * func_02004b78 really takes two arguments (the byte flag is passed in r1).
 */
#include "m2c.h"

void func_02004b78(void *arg0, u8 arg1); /* extern */

void func_02037308(void *arg0) {
    u8 temp_r1;
    temp_r1 = M2C_FIELD(arg0, u8 *, 0x14);
    if (temp_r1 != 0) {
        func_02004b78(M2C_FIELD(arg0, void **, 4), temp_r1);
    }
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 1);
}
