/* Reconstructed from USA ARM9 at 0x02085d94 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_02085d94(s32 arg0, void *arg1) {
    s16 *p;
    u32 i;

    p             = (s16 *) arg1;
    *(s32 *) arg1 = 0x88CC44FF;
    for (i = 0; i < 2U; i++) {
        p[i + 2] = 0x64;
    }
    *(s8 *) ((s8 *) arg1 + 8) = 0x4A;
    *(s8 *) ((s8 *) arg1 + 9) = 0;
}
