/* Reconstructed from USA ARM9 at 0x02029324 (40 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"
extern void func_0202928c(s32 *, s32, s32, s32);
void func_02029324(s32 *destination, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 == 0) {
        *destination = 0;
        *destination -= 0x80000001;
        return;
    }
    func_0202928c(destination, arg1, arg2 + 0xb0, arg3);
}
