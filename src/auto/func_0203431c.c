/* Reconstructed from USA ARM9 at 0x0203431c (52 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0202faac();
M2C_UNK func_02034bd0(void *, M2C_UNK, u16);

void func_0203431c(void *arg0) {
    volatile u16 sp0;
    u16 temp_r2;

    func_0202faac();
    temp_r2                      = M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0xCA);
    sp0                          = temp_r2;
    M2C_FIELD(arg0, u16 *, 0x44) = temp_r2;
    func_02034bd0(arg0, 1, temp_r2);
}
