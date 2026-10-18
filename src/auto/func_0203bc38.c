/* Reconstructed from USA ARM9 at 0x0203bc38 (104 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02018200(void *, s32, M2C_UNK);        /* extern */

s32 func_0203bc38(void *arg0) {
    s16 temp_r1_4;
    s32 temp_r1;
    void *temp_r1_2;
    void *temp_r1_3;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0x54);
    if (temp_r1 != 0) {
        func_02018200(M2C_FIELD(arg0, void **, 4), temp_r1, 0);
    }
    temp_r1_2 = M2C_FIELD(arg0, void **, 4);
    temp_r1_3 = temp_r1_2 + 0x60;
    if (temp_r1_3 != (arg0 + 0x40)) {
        M2C_FIELD(temp_r1_3, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
        M2C_FIELD(temp_r1_3, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x44);
        M2C_FIELD(temp_r1_3, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x48);
    }
    temp_r1_4                    = M2C_FIELD(arg0, s16 *, 0x32);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) (temp_r1_4 - 1);
    if ((s32) temp_r1_4 <= 0) {
        return 1;
    }
    return 0;
}
