/* Reconstructed from USA ARM9 at 0x02053964 (100 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_02101b78;

s32 func_02053964(void *arg0) {
    s32 temp_r2;

    temp_r2 = M2C_FIELD(((s8 *) &data_02101b78 + (M2C_FIELD(arg0, s32 *, 0) << 5)), s32 *, 4) & 7;
    return ((temp_r2 == 3) && ((s32) M2C_FIELD(arg0, s32 *, 4) >= 3)) ||
           ((temp_r2 == 4) && ((s32) M2C_FIELD(arg0, s32 *, 4) >= 3)) ||
           ((temp_r2 == 5) && ((s32) M2C_FIELD(arg0, s32 *, 4) >= 2));
}
