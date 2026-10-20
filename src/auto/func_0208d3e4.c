#include "m2c.h"

extern void func_020534e0(M2C_UNK);

/* Constructor of the 0x10-byte sub-object embedded at +0x94 of the parent object. */
s32 func_0208d3e4(M2C_UNK arg0) {
    func_020534e0(arg0);
    M2C_FIELD(arg0, s8 *, 8)    = 3;
    M2C_FIELD(arg0, u16 *, 0xa) = 0xffff;
    M2C_FIELD(arg0, s8 *, 0xc)  = 0;
    M2C_FIELD(arg0, s8 *, 0xd)  = 0;
    M2C_FIELD(arg0, s8 *, 0xe)  = 0;
    return arg0;
}
