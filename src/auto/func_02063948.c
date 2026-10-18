/* Reconstructed from USA ARM9 at 0x02063948 (32 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_021043c4;

u8 func_02063948(s32 arg0, s32 arg1) {
    u8 *base = (u8 *) &data_021043c4;
    return base[arg0 * 0x32 + arg1 * 0xA];
}
