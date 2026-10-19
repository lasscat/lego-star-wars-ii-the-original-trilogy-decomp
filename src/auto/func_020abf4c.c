/* Reconstructed from USA ARM9 at 0x020abf4c (76 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_020abf4c(void *arg0) {
    void *var_ip;

    var_ip = arg0;
    do {
        M2C_FIELD(var_ip, s32 *, 0)   = 0;
        M2C_FIELD(var_ip, s32 *, 4)   = 0;
        M2C_FIELD(var_ip, s32 *, 8)   = 0;
        M2C_FIELD(var_ip, u16 *, 0xC) = 0xFFFF;
        var_ip += 0x10;
    } while ((u32) var_ip < (u32) (arg0 + 0x40));
    M2C_FIELD(arg0, u16 *, 0x52) = 0;
    M2C_FIELD(arg0, u16 *, 0x50) = 0;
    M2C_FIELD(arg0, u16 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = -1;
    M2C_FIELD(arg0, u16 *, 0x56) = 0;
}
