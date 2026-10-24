/* compiler: 2.0/sp1p5 -O2 */
#include "m2c.h"

extern M2C_UNK data_02101168;

void func_020bd534(void *arg0, s32 arg1) {
    void *var_ip;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_02101168;
    M2C_FIELD(arg0, s32 *, 4)      = 1;
    M2C_FIELD(arg0, s32 *, 8)      = 0x3C;
    M2C_FIELD(arg0, s32 *, 0xC)    = 0x3C;
    M2C_FIELD(arg0, s32 *, 0x10)   = 0;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0;
    M2C_FIELD(arg0, s32 *, 0x18)   = 0;
    M2C_FIELD(arg0, s16 *, 0x1C)   = 0;
    M2C_FIELD(arg0, s16 *, 0x1E)   = 0;
    M2C_FIELD(arg0, s16 *, 0x20)   = 0;
    M2C_FIELD(arg0, s16 *, 0x22)   = 0;
    M2C_FIELD(arg0, s32 *, 0x24)   = 0;
    M2C_FIELD(arg0, s32 *, 0x28)   = 0;
    M2C_FIELD(arg0, s16 *, 0x2C)   = 0;
    M2C_FIELD(arg0, s16 *, 0x2E)   = 0;
    M2C_FIELD(arg0, s16 *, 0x30)   = 0;
    M2C_FIELD(arg0, s16 *, 0x32)   = 0;
    M2C_FIELD(arg0, s32 *, 0x34)   = 0;
    M2C_FIELD(arg0, s32 *, 0x38)   = 0;
    M2C_FIELD(arg0, s32 *, 0x3C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x40)   = 0;
    M2C_FIELD(arg0, s8 *, 0x44)    = 0;
    var_ip                         = arg0 + 0x48;
    do {
        M2C_FIELD(var_ip, s32 *, 0) = 0;
        M2C_FIELD(var_ip, s8 *, 4)  = 0;
        M2C_FIELD(var_ip, s8 *, 6)  = 0;
        M2C_FIELD(var_ip, s8 *, 7)  = 0;
        var_ip += 8;
    } while ((u32) var_ip < (u32) (arg0 + 0x60));
    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
}
