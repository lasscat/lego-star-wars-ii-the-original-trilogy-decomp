/* Reconstructed from USA ARM9 at 0x0208afb0 (40 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0208afd8(s32, u8 *, s32, s32);

void func_0208afb0(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    if (*arg1 == (u8) arg2) {
        return;
    }
    func_0208afd8(arg0, arg1, arg2, arg3);
    *arg1 = arg2;
}
