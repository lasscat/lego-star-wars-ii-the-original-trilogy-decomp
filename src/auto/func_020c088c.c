/* Reconstructed from USA ARM9 at 0x020c088c (24 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern u32 *func_020be664(void *);
u32 *func_020c088c(void *object) {
    u32 *cursor                    = func_020be664(object);
    u32 value                      = *cursor++;
    M2C_FIELD(object, u32 *, 0x14) = value;
    return cursor;
}
