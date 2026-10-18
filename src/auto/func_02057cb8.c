/* Reconstructed from USA ARM9 at 0x02057cb8 (64 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020a98f8(s32, s32 *);                  /* extern */
void *func_020aaeb4();                              /* extern */

void func_02057cb8(s32 arg0, s16 *arg1) {
    s32 a;
    s32 b;
    s32 c;
    s32 sp0[3];

    a      = arg1[0] << 0xC;
    c      = arg1[2] << 0xC;
    b      = arg1[1] << 0xC;
    sp0[0] = a;
    sp0[1] = b;
    sp0[2] = c;
    func_020a98f8((s32) func_020aaeb4(), sp0);
}
