#include "m2c.h"

M2C_UNK func_02027068(); /* extern */

/* Completes initialization of an embedded state record. Its companion
 * func_02027068 clears the leading word and three nearby flag bytes; this
 * routine clears the remaining words and trailing bytes. Callers use it on
 * sub-blocks within larger objects, at +0x28 and +0x10.
 */
void *func_02029520(void *state) {
    func_02027068();
    M2C_FIELD(state, s32 *, 0x58) = 0;
    M2C_FIELD(state, s32 *, 0x5C) = 0;
    M2C_FIELD(state, s32 *, 0x60) = 0;
    M2C_FIELD(state, s32 *, 0x64) = 0;
    M2C_FIELD(state, s32 *, 0x68) = 0;
    M2C_FIELD(state, s32 *, 0x6C) = 0;
    M2C_FIELD(state, s32 *, 0x70) = 0;
    M2C_FIELD(state, s32 *, 0x74) = 0;
    M2C_FIELD(state, s32 *, 0x78) = 0;
    M2C_FIELD(state, s32 *, 0x7C) = 0;
    M2C_FIELD(state, s32 *, 0x80) = 0;
    M2C_FIELD(state, s32 *, 0x84) = 0;
    M2C_FIELD(state, s32 *, 0x88) = 0;
    M2C_FIELD(state, s8 *, 0x8C)  = 0;
    M2C_FIELD(state, s8 *, 0x8D)  = 0;
    M2C_FIELD(state, s8 *, 0x8E)  = 0;
    M2C_FIELD(state, s8 *, 0x8F)  = 0;
    M2C_FIELD(state, s8 *, 0x90)  = 0;
    M2C_FIELD(state, s8 *, 0x91)  = 0;
    M2C_FIELD(state, s8 *, 0x92)  = 0;
    M2C_FIELD(state, s8 *, 0x93)  = 0;
    return state;
}
