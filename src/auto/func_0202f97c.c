/* Reconstructed from USA ARM9 at 0x0202f97c (120 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020184a0(M2C_UNK *, s32);              /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_020b973c();                            /* extern */
extern M2C_UNK data_020fdd84;
extern M2C_UNK data_02101ae4;

void *func_0202f97c(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdd84;
    if (M2C_FIELD(arg0, s32 *, 0x24) != 0) {
        func_020184a0(&data_02101ae4, M2C_FIELD(arg0, s32 *, 0x24));
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x28) != 0) {
        func_020184a0(&data_02101ae4, M2C_FIELD(arg0, s32 *, 0x28));
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x2C) != 0) {
        func_020b973c();
        M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    }
    func_0205e84c(arg0);
    return arg0;
}
