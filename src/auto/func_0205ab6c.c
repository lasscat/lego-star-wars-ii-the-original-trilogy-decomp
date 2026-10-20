/* Reconstructed from USA ARM9 at 0x0205ab6c (44 bytes).
 * arg0 is a 16-bit index; 0xffff means "none" and skips the update.
 */
#include "m2c.h"

extern s32 data_021027f4;
extern void func_0205b248(M2C_UNK, M2C_UNK);

void func_0205ab6c(u32 arg0) {
    if (arg0 == 0xffff) {
        return;
    }
    func_0205b248(data_021027f4, arg0);
}
