/* Reconstructed from USA ARM9 at 0x020908e4 (36 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern s32 OS_GetTick(void *, s32);
int func_020908e4(void *object, s32 index) {
    s32 value                      = OS_GetTick(object, index);
    u8 *entry                      = (u8 *) object + index * 16;
    M2C_FIELD(entry, s32 *, 0x428) = value;
    M2C_FIELD(entry, u8 *, 0x435)  = 1;
    return 1;
}
