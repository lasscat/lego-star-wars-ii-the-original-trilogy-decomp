/* Reconstructed from USA ARM9 at 0x020cf624 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s16 func_020ccec8();                                /* extern */
s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */
extern M2C_UNK data_021157c8;

void func_020cf624(void) {
    s32 *temp_r4;
    s16 temp_r0;
    s32 temp_r5;

    temp_r4 = (s32 *) &data_021157c8;
    temp_r5 = func_020ce804();
    if (temp_r4[0] == 0) {
        temp_r0                      = func_020ccec8();
        temp_r4[0]                   = 1;
        M2C_FIELD(temp_r4, s16 *, 4) = temp_r0;
    }
    func_020ce818(temp_r5);
}
