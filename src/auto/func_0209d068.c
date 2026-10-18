/* Reconstructed from USA ARM9 at 0x0209d068 (36 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0209d068(s32 arg0, const u8 *arg1) {
    u8 i = arg1[0x5DA];
    if (i >= 4) {
        return;
    }
    *(u16 *)(arg0 + 0xF2 + i * 2) += 1;
}
