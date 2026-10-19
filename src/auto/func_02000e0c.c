#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02000e0c(s32 a0, s32 a1, s32 a2) {
    cmp r2, #0x0
L_02000e10:
    beq L_02000e10
    mov ip, #0x10
    cmp ip, #0x10
L_02000e1c:
    bne L_02000e1c
}
// clang-format on
