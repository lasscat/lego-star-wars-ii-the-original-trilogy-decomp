/* Reconstructed from USA ARM9 at 0x02025aa0 (132 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020120ac(void *);                      /* extern */
extern M2C_UNK data_020fda80;

void *func_02025aa0(void *arg0) {
    void **var_r0;
    void **var_r1;
    void **var_r1_2;
    void *temp_r0;
    void *var_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fda80;
    var_r1                         = M2C_FIELD(arg0, void ***, 0x224);
    var_r0                         = var_r1;
    if (var_r1 != NULL) {
        var_r0 = (void **) ((s8 *) var_r1 - 4);
    }
    if (var_r0 != NULL) {
        if (var_r1 != NULL) {
            var_r1 = (void **) ((s8 *) var_r1 - 4);
        }
        M2C_FIELD(var_r1, s32 *, 8) = (s32) (M2C_FIELD(var_r1, s32 *, 8) | 2);
    }
    var_r1_2 = M2C_FIELD(arg0, void ***, 0x224);
    if (var_r1_2 != NULL) {
        var_r2  = *var_r1_2;
        temp_r0 = arg0 + 0x224;
        if (var_r2 != temp_r0) {
            do {
                var_r1_2 = var_r2 + 4;
                var_r2   = M2C_FIELD(var_r2, void **, 4);
            } while (var_r2 != temp_r0);
        }
        *var_r1_2 = M2C_FIELD(arg0, void **, 0x228);
    }
    func_020120ac(arg0);
    return arg0;
}
