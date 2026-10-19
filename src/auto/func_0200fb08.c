/* Reconstructed from USA ARM9 at 0x0200fb08 (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_021019f4;
extern s32 data_027e02a4;

void func_0200fb08(s32 arg0) {
    void *temp_r2;
    void *var_r3;

    var_r3 = M2C_FIELD(((s8 *) &data_021019f4 + data_027e02a4 * 0x38), void **, 4);
    if (var_r3 == NULL) {
        return;
    }
    do {
        temp_r2                      = M2C_FIELD(var_r3, void **, 0);
        M2C_FIELD(temp_r2, s32 *, 8) = (s32) (M2C_FIELD(temp_r2, s32 *, 8) | arg0);
        var_r3                       = M2C_FIELD(var_r3, void **, 4);
    } while (var_r3 != NULL);
}
