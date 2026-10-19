/* Reconstructed from USA ARM9 at 0x02038610 (68 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02038aa8(void *);                      /* extern */
M2C_UNK func_020b973c();                            /* extern */
extern M2C_UNK data_020fe090;

void *func_02038610(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe090;
    if (M2C_FIELD(arg0, u8 *, 0x19) == 0) {
        func_02038aa8(arg0);
    }
    if (M2C_FIELD(arg0, s32 *, 0x14) != 0) {
        func_020b973c();
        M2C_FIELD(arg0, s32 *, 0x14) = 0;
    }
    return arg0;
}
