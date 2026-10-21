/* compiler: 2.0/sp1p5 -O1,p */
/* Reconstructed from USA ARM9 at 0x02019450 (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02018cf4(void *, void *); /* extern */
M2C_UNK func_02018e74(void *, void *); /* extern */

void func_02019450(void *arg0, void **arg1) {
    void *temp_r1;

    if (M2C_FIELD(arg0, u8 *, 0x1C1) != 0) {
        return;
    }
    if ((M2C_FIELD(arg0, s32 *, 8) & 2) == 2) {
        return;
    }
    temp_r1 = *arg1;
    if (temp_r1 == NULL) {
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x1C2) != 0) {
        func_02018e74(arg0, temp_r1);
    } else {
        func_02018cf4(arg0, temp_r1);
    }
}
