/* Reconstructed from USA ARM9 at 0x0209f53c (32 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern u8 data_020eb7bc[];
extern s32 func_0209f55c(s32, u16, u32);
s32 func_0209f53c(s32 value, u32 index) {
    return func_0209f55c(value, *(u16 *) (data_020eb7bc + index * 8), index);
}
