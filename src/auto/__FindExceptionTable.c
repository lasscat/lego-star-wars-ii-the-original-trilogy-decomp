/* Reconstructed from USA ARM9 at 0x020e4b88 (32 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern char __exception_table_start__[];
extern char __exception_table_end__[];

s32 __FindExceptionTable(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xC)  = (s32) __exception_table_start__;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) __exception_table_end__;
    return 1;
}
