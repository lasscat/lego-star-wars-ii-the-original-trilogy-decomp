#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02001070(s32 a0, s32 a1, s32 a2) {
    cmp r2, #0x10
L_02001074:
    blt L_02001074
    mov ip, #0x10
    cmp ip, #0x10
L_02001080:
    bne L_02001080
}
// clang-format on
