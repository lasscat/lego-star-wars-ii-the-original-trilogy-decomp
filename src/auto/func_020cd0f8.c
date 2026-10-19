/* Reconstructed from USA ARM9 at 0x020cd0f8 (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_02115424;

void func_020cd0f8(void *arg0) {
    void *var_r1;
    void *var_r2;

    var_r2 = NULL;
    var_r1 = M2C_FIELD(&data_02115424, void **, 0x2C);
    while ((var_r1 != NULL) && (var_r1 != arg0)) {
        var_r2 = var_r1;
        var_r1 = M2C_FIELD(var_r1, void **, 0x68);
    }
    if (var_r2 == NULL) {
        M2C_FIELD(&data_02115424, void **, 0x2C) = (void *) M2C_FIELD(arg0, void **, 0x68);
        return;
    }
    M2C_FIELD(var_r2, void **, 0x68) = (void *) M2C_FIELD(arg0, void **, 0x68);
}
