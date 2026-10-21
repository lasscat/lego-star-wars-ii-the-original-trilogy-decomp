#include "m2c.h"

extern u32 data_020ff380[];

/* Initialises a 0x38 byte object and returns it.
 *
 *   +0x00 : pointer to the class table stored in data_020ff380
 *   +0x04 : three words copied from a2
 *   +0x10 : three words copied from a3
 *   +0x1c : one byte taken from a1
 *   +0x20 : six bytes, three (0xff, 0x00) pairs
 */
s32 func_0208345c(u8 *a0, s32 a1, s32 *a2, s32 *a3) {
    u8 *p = a0 + 0x20;

    *(u32 *) a0          = (u32) &data_020ff380[0];
    *(u32 *) (a0 + 4)    = a2[0];
    *(u32 *) (a0 + 8)    = a2[1];
    *(u32 *) (a0 + 0xc)  = a2[2];
    *(u32 *) (a0 + 0x10) = a3[0];
    *(u32 *) (a0 + 0x14) = a3[1];
    *(u32 *) (a0 + 0x18) = a3[2];
    a0[0x1c]             = (u8) a1;

    do {
        *p++ = 0xff;
        *p++ = 0x00;
    } while (p < a0 + 0x26);

    return (s32) a0;
}
