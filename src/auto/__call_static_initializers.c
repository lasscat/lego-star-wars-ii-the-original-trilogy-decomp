/* Reconstructed from USA ARM9 at 0x020e4534 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern void (*ARM9_CTOR_START[])(void);

void __call_static_initializers(void) {
    M2C_UNK (**var_r4)();
    M2C_UNK (*temp_r0)();

    var_r4 = (M2C_UNK(**)()) ARM9_CTOR_START;
    while (var_r4 != NULL && (temp_r0 = *var_r4) != NULL) {
        temp_r0();
        var_r4 += 1;
    }
}
