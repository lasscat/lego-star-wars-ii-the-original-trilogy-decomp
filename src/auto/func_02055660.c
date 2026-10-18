/* Reconstructed from USA ARM9 at 0x02055660 (36 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02055660(const void *object) {
    u32 row        = M2C_FIELD(object, const u32 *, 4);
    u32 column     = M2C_FIELD(object, const u32 *, 8);
    const u8 *base = M2C_FIELD(object, const u8 **, 0);
    base += (row << 28) >> 22;
    base += (column << 28) >> 26;
    return M2C_FIELD(base, const s32 *, 0x24);
}
