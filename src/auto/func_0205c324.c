#include "m2c.h"

/*
 * Resets a 0x30-byte control block:
 *   +0x00 .. +0x18  seven s32 words cleared in a loop
 *   +0x1C, +0x20, +0x24  three s32 words cleared
 *   +0x28, +0x2C  two u16 fields set to 0xFFFF
 *   +0x2A         one u16 field cleared
 *   +0x2E, +0x2F  two u8 fields cleared
 */
void func_0205c324(M2C_UNK a0) {
    s32 i;
    s32 *p = (s32 *) a0;

    p[7]                        = 0;
    p[8]                        = 0;
    p[9]                        = 0;
    *(u16 *) ((s8 *) a0 + 0x28) = 0xffff;
    *(u16 *) ((s8 *) a0 + 0x2a) = 0;
    *(u16 *) ((s8 *) a0 + 0x2c) = 0xffff;
    *(u8 *) ((s8 *) a0 + 0x2e)  = 0;
    *(u8 *) ((s8 *) a0 + 0x2f)  = 0;

    for (i = 0; i < 7; i++) {
        p[i] = 0;
    }
}
