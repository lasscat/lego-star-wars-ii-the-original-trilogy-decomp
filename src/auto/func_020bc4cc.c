/* Reconstructed from USA ARM9 at 0x020bc4cc (100 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020bca64(void *);                      /* extern */

void func_020bc4cc(void *arg0, s32 var_r6) {
    s32 var_r5;

    if (M2C_FIELD(arg0, void **, 0x48) == NULL) {
        return;
    }
    if (var_r6-- == 0) {
        return;
    }
    do {
        var_r5 = 0;
        if ((s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x48), s32 *, 4) > 0) {
            do {
                func_020bca64(arg0);
                var_r5 += 1;
            } while (var_r5 < (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x48), s32 *, 4));
        }
    } while (var_r6-- != 0);
}
