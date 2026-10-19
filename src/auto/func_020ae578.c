/* Reconstructed from USA ARM9 at 0x020ae578 (40 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020ad8b4();                            /* extern */
extern M2C_UNK data_0210b320;

void func_020ae578(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020ad8b4();
    } else {
        M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x15;
    }
}
