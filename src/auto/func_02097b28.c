/* Reconstructed from USA ARM9 at 0x02097b28 (64 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020975f4();                            /* extern */
extern M2C_UNK data_020ff924;

void *func_02097b28(void *arg0) {
    func_020975f4();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff924;
    M2C_FIELD(arg0, u8 *, 0x3B)    = 0xFF;
    M2C_FIELD(arg0, s8 *, 0x3C)    = 0;
    M2C_FIELD(arg0, s8 *, 0x3D)    = 0;
    M2C_FIELD(arg0, s8 *, 0x3E)    = 0;
    M2C_FIELD(arg0, s8 *, 0x1C)    = 5;
    return arg0;
}
