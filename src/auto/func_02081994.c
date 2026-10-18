/* Reconstructed from USA ARM9 at 0x02081994 (124 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s8 func_020832b0(void *, M2C_UNK);                  /* extern */
s8 func_02083340(void *, s32);                      /* extern */
extern M2C_UNK data_02104de2;

void func_02081994(void *arg0, s32 arg1) {
    s32 temp_r4;
    void *temp_r6;

    temp_r4                                     = arg1 * 6;
    temp_r6                                     = (M2C_UNK *) ((s8 *) &data_02104de2 + temp_r4);
    *((s8 *) ((s8 *) &data_02104de2 + temp_r4)) = func_020832b0(arg0, 0);
    M2C_FIELD(temp_r6, s8 *, 1)                 = func_020832b0(arg0, 2);
    M2C_FIELD(temp_r6, s8 *, 2)                 = func_020832b0(arg0, 1);
    M2C_FIELD(temp_r6, s8 *, 3)                 = func_020832b0(arg0, 3);
    M2C_FIELD(temp_r6, s8 *, 4)                 = func_020832b0(arg0, 4);
    M2C_FIELD(temp_r6, s8 *, 5)                 = func_02083340(arg0, M2C_FIELD(arg0, s32 *, 0x100));
}
