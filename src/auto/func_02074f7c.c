#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02074f7c(s32 a0, s32 a1) {
    ldr r3, [r0, #0x0]
    cmp r3, #0x0
    bne L_02074f9c
    mov r2, #0x0
    str r2, [r1, #0x38]
    str r2, [r1, #0x34]
    str r1, [r0, #0x0]
    bx lr
L_02074f9c:
    ldr ip, [r1, #0x28]
L_02074fa0:
    ldr r2, [r3, #0x28]
    cmp ip, r2
    bgt L_02074fd0
    str r3, [r1, #0x38]
    ldr r2, [r3, #0x34]
    str r2, [r1, #0x34]
    str r1, [r3, #0x34]
    ldr r2, [r1, #0x34]
    cmp r2, #0x0
    strne r1, [r2, #0x38]
    streq r1, [r0, #0x0]
    bx lr
L_02074fd0:
    ldr r2, [r3, #0x38]
    cmp r2, #0x0
    bne L_02074ff0
    str r3, [r1, #0x34]
    mov r0, #0x0
    str r0, [r1, #0x38]
    str r1, [r3, #0x38]
    bx lr
L_02074ff0:
    mov r3, r2
    b L_02074fa0
}
// clang-format on
