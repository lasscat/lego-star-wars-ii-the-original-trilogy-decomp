/* Reconstructed from USA ARM9 at 0x020881d0 (148 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_021027f8;
extern M2C_UNK data_0210930c;
extern M2C_UNK data_02109358;

void func_020881d0(void) {
    M2C_UNK (*temp_r1)(void *, M2C_UNK, s32);
    s32 temp_r2;
    s32 var_r2;
    u32 temp_lr;
    u32 var_r1;
    void *temp_r0;

    var_r1  = 0;
    temp_lr = M2C_FIELD(*((M2C_UNK *) ((s8 *) &data_02109358 + (M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 4))), u32 *, 0x7FC);
    while (var_r1 < temp_lr) {
        temp_r0 =
            (void *) ((s32 *) ((u8 *) M2C_FIELD(
                          ((M2C_UNK *) ((s8 *) &data_0210930c + (M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 4))), s32 *, 0x4C)) +
                      0x1BE)[var_r1 * 2];
        if (M2C_FIELD(temp_r0, u16 *, 0xC) == 4) {
            if (M2C_FIELD(temp_r0, u16 *, 0x212) == 0x40) {
                var_r2 = 1;
            } else {
                var_r2 = 0;
            }
            temp_r2 = var_r2 | 0x46;
            if (temp_r2 != 0) {
                temp_r1 = M2C_FIELD(M2C_FIELD(temp_r0, void **, 0), M2C_UNK(**)(void *, M2C_UNK, s32), 0x40);
                temp_r1(temp_r0, temp_r1, temp_r2);
                return;
            }
        }
        var_r1 += 1;
    }
}
