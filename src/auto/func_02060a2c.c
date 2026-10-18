/* Reconstructed from USA ARM9 at 0x02060a2c (76 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02060a78(void *, s32, u8, M2C_UNK);    /* extern */
extern M2C_UNK data_02103374;
extern M2C_UNK data_02103a94;

void func_02060a2c(s32 arg0) {
    s32 temp_r3;
    u8 temp_r2;

    temp_r3 = arg0 * 0x724;
    temp_r2 = ((u8 *) &data_02103a94)[temp_r3];
    if (temp_r2 == 0) {
        return;
    }
    func_02060a78((void *) ((u8 *) &data_02103374 + temp_r3 + 0x640), (s32) ((char *) ((arg0 << 0xA) + 0x7000000) + 6),
                  temp_r2, 8);
}
