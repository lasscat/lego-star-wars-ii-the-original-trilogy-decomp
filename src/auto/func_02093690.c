/* Reconstructed from USA ARM9 at 0x02093690 (112 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02010af0(void *);                      /* extern */
M2C_UNK func_02055128(void *, void *);              /* extern */
M2C_UNK func_02092b74(void *, void *);              /* extern */

void func_02093690(void *arg0, void *arg1) {
    s32 var_r5;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x68);
    if ((temp_r0 != NULL) && (M2C_FIELD(temp_r0, s32 *, 0x384) != 0)) {
        var_r5 = 0;
        func_02010af0(arg1);
        func_02055128((s8 *) arg0 + 0x1A0, arg1);
        while ((M2C_FIELD(arg1, u8 *, 0x40) == 0) && ((var_r5 += 1) < 0xA)) {
            M2C_FIELD(arg1, s32 *, 0x64) = -0x5000;
            func_02092b74(arg0, arg1);
        }
    }
}
