/* Reconstructed from USA ARM9 at 0x0200c9e4 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0200c9e4(s32 arg0, s32 arg1, void *arg2) {
    s32 *temp_ip;
    s32 temp_lr;

    temp_lr = arg1 * 0x28;
    temp_ip = arg0 + 0x1BC + temp_lr;
    if (temp_ip == arg2) {
        return;
    }
    *temp_ip                                = M2C_FIELD(arg2, s32 *, 0);
    M2C_FIELD(arg0 + temp_lr, s32 *, 0x1C0) = (s32) M2C_FIELD(arg2, s32 *, 4);
    M2C_FIELD(arg0 + temp_lr, s32 *, 0x1C4) = (s32) M2C_FIELD(arg2, s32 *, 8);
}
