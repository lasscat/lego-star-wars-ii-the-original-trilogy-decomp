/* Reconstructed from USA ARM9 at 0x0208b4f8 (84 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02053b14(void *);                          /* extern */

void func_0208b4f8(void *arg0) {
    s32 temp_r0;
    u32 var_r3;
    void *temp_r1;
    void *temp_r2;
    void *temp_r2_2;

    temp_r2                        = M2C_FIELD(arg0, void **, 0x64);
    M2C_FIELD(temp_r2, s32 *, 8)   = (s32) (M2C_FIELD(temp_r2, s32 *, 8) & ~1);
    temp_r2_2                      = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(temp_r2_2, s32 *, 8) = (s32) (M2C_FIELD(temp_r2_2, s32 *, 8) & ~1);
    temp_r0                        = func_02053b14(arg0 + 8);
    var_r3                         = 0;
    do {
        temp_r1                          = temp_r0 + (var_r3 * 2);
        M2C_FIELD(temp_r1, s16 *, 0x40A) = 0x40;
        var_r3 += 1;
        M2C_FIELD(temp_r1, s16 *, 0x44A) = 0x40;
    } while (var_r3 < 6U);
}
