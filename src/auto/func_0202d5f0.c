/* Reconstructed from USA ARM9 at 0x0202d5f0 (48 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_020f6a74;
extern M2C_UNK data_020ff7de;

void func_0202d5f0(void *arg0, s32 arg1, s8 arg2) {
    u8 byteval                = *((u8 *) ((s8 *) &data_020ff7de + (M2C_FIELD(arg0, u8 *, 1) * 8)));
    s16 *tbl                  = (s16 *) ((s8 *) &data_020f6a74 + (byteval * 0x10));
    M2C_FIELD(arg0, s16 *, 4) = tbl[arg2];
    M2C_FIELD(arg0, s8 *, 2)  = arg2;
}
