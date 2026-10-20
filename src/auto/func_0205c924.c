#include "m2c.h"

extern void func_02008288(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0205c924(s32 a0, s32 a1) {
    stmfd sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r4, #0x0
    mov r6, r0
    mov r5, r1
    mov r8, r4
    mov r9, #0x1
    mov r7, r4
L_0205c940:
    cmp r4, #0x0
    bne L_0205c954
    ldrb r0, [r6, #0x2f]
    cmp r0, #0x0
    bne L_0205c980
L_0205c954:
    add r0, r5, r4, lsl #0x2
    ldr r0, [r0, #0x20]
    cmp r0, #0x0
    movne r0, r9
    moveq r0, r8
    cmp r0, #0x0
    beq L_0205c980
    mov r1, r4
    mov r2, r7
    add r0, r5, #0x10
    bl func_02008288
L_0205c980:
    add r4, r4, #0x1
    cmp r4, #0x2
    blt L_0205c940
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
