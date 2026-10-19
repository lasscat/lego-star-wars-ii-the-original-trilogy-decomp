/* Reconstructed from USA ARM9 at 0x0204c864 (40 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern void func_0205ab6c(u32);
u16 *func_0204c864(u16 *object) {
    u32 value = *object;
    if (value != 0xffff) {
        func_0205ab6c(value);
    }
    return object;
}
