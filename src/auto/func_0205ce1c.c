#include "m2c.h"

extern void func_02059e30(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0205ce1c(s32 a0) {
    stmfd sp!, {r4, r5, r6, lr}
    mov r6, r0
    mov r5, r6
    add r4, r6, #0x28
L_0205ce2c:
    mov r0, r5
    bl func_02059e30
    add r5, r5, #0xa
    cmp r5, r4
    blo L_0205ce2c
    mov r0, #0x1
    strb r0, [r6, #0x29]
    mov r1, #0x0
    strb r1, [r6, #0x28]
    mov r0, r6
    strb r1, [r6, #0x2a]
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
