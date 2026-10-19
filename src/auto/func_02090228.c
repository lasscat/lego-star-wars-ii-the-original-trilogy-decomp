/* Reconstructed from USA ARM9 at 0x02090228 (120 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020902a0(void **, void **, M2C_UNK);   /* extern */
extern void *data_021019f4;

void func_02090228(void **arg0) {
    void **var_ip;
    void *temp_r2;
    u32 var_r3;

    for (var_r3 = 0; var_r3 < (u32) M2C_FIELD(arg0, u32 *, 0x3C8); var_r3++) {
        var_ip  = (void **) ((u8 *) arg0 + var_r3 * 0x24);
        temp_r2 = *var_ip;
        if (M2C_FIELD(arg0, s32 *, 0x3CC) & (1 << var_r3)) {
            M2C_FIELD(temp_r2, s32 *, 8) |= 1;
        } else {
            M2C_FIELD(temp_r2, s32 *, 8) &= ~1;
        }
    }
    func_020902a0(arg0, &data_021019f4, 1);
    func_020902a0(arg0, (void **) ((u8 *) arg0 + 0x390), 0);
}
