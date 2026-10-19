/* Reconstructed from USA ARM9 at 0x02003970 (40 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

u8 func_02003970(s32 unused, const u8 *bytes) {
    u8 index = 0;
    if (bytes[index] == 0xfa) {
        return index;
    }
    do {
        ++index;
    } while (bytes[index] != 0xfa);
    return index;
}
