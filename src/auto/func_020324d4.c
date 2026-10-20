#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fddf0;

/* Initialises the object pointed to by a0.
 * Offset 0x00 holds a pointer that is first set to data_020fdbc4 and then
 * overwritten with data_020fddf0; 0x04 receives a1; the byte fields at 0x0c
 * and 0x0d are cleared; 0x10 is cleared; 0x14 receives the low halfword of
 * a2 and the byte at 0x16 is cleared.
 */
void func_020324d4(u8 *a0, s32 a1, u16 a2, ...) {
    M2C_FIELD(a0, M2C_UNK **, 0x0) = &data_020fdbc4;
    M2C_FIELD(a0, s32 *, 0x4)      = a1;
    M2C_FIELD(a0, u8 *, 0xc)       = 0;
    M2C_FIELD(a0, u8 *, 0xd)       = 0;
    M2C_FIELD(a0, M2C_UNK **, 0x0) = &data_020fddf0;
    M2C_FIELD(a0, s32 *, 0x10)     = 0;
    M2C_FIELD(a0, u16 *, 0x14)     = *(u16 *) &a2;
    M2C_FIELD(a0, u8 *, 0x16)      = 0;
}
