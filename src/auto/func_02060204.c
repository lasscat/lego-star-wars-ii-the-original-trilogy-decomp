/* Reconstructed from USA ARM9 at 0x02060204 (32 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern u8 data_021029fa[];
extern u8 data_021029fc[];
void func_02060204(s32 unused, u32 index, u16 first, u16 second) {
    u32 byte_offset                        = index << 5;
    *(u16 *) (data_021029fa + byte_offset) = second;
    *(u16 *) (data_021029fc + byte_offset) = first;
}
