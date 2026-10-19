/* Reconstructed from USA ARM9 at 0x020514d8 (68 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020b9584(u8, s32 *);                   /* extern */

s32 func_020514d8(void *arg0) {
    s16 *p = arg0;
    s32 a;
    s32 b;
    s32 c;
    s32 sp0[3];

    a      = p[0] << 0xC;
    c      = p[2] << 0xC;
    b      = p[1] << 0xC;
    sp0[0] = a;
    sp0[1] = b;
    sp0[2] = c;
    func_020b9584(((u8 *) arg0)[8], sp0);
    return 0;
}
