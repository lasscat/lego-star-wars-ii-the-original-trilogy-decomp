/* Reconstructed from USA ARM9 at 0x020c7b10 (76 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern s32 data_02101300;

void func_020c7b10(void *arg0, s32 arg1, void *arg2) {
    u32 var_ip;

    var_ip                      = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) data_02101300;
    M2C_FIELD(arg0, u8 *, 0x19) = (u8) M2C_FIELD(arg2, u8 *, 0x17);
    M2C_FIELD(arg0, s32 *, 8)   = arg1;
    if (!((u32) M2C_FIELD(arg0, u8 *, 0x19) > var_ip)) {
        return;
    }
    do {
        M2C_FIELD((arg0 + (var_ip * 2)), s16 *, 0x1A) = (s16) (var_ip | 0x100);
        var_ip += 1;
    } while (var_ip < (u32) M2C_FIELD(arg0, u8 *, 0x19));
}
