/* Reconstructed from USA ARM9 at 0x0202921c (64 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern void func_0204a5f8(void *a0, u16 *a1);
extern void func_020291d4(void *a0, u32 a1);

void func_0202921c(void *arg0, u16 arg1) {
    if (arg0 == NULL) {
        return;
    }
    func_0204a5f8((u8 *) arg0 + 0x5ce, &arg1);
    func_020291d4(arg0, 0x40);
}
