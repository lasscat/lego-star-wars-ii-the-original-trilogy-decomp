/* Reconstructed from USA ARM9 at 0x02067f48 (88 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0206549c();                         /* extern */
extern M2C_UNK data_020fe76c;

void *func_02067f48(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe76c;
    func_0206549c(arg0 + 4);
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s8 *, 0x38)  = -1;
    M2C_FIELD(arg0, s8 *, 0x50)  = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s8 *, 0x39)  = 0;
    M2C_FIELD(arg0, u8 *, 0x3A)  = 0xFF;
    return arg0;
}
