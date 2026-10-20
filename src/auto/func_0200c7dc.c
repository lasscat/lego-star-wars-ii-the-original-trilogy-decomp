#include "m2c.h"

extern void func_0200c894(s32 a0, s32 a1);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200c7dc(s32 a0, s32 a1) {
    stmfd sp!, {r4, r5, r6, lr}
    mov r2, #0x28
    mul r6, r1, r2
    mov r4, r0
    add r5, r4, #0x1d0
    ldr r0, [r5, r6]
    cmp r0, #0x0
    beq L_0200c814
    beq L_0200c80c
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx r1
L_0200c80c:
    mov r0, #0x0
    str r0, [r5, r6]
L_0200c814:
    add r0, r4, r6
    mov r1, #0x0
    strb r1, [r0, #0x1df]
    add r0, r0, #0x100
    ldrsb r1, [r0, #0xe1]
    mov r0, r4
    bl func_0200c894
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
