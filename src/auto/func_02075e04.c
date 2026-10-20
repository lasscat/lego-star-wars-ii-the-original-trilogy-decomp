#include "m2c.h"

extern u32 data_020fed00[];

extern void func_0205e84c(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02075e04(s32 a0) {
    stmfd sp!, {r4, r5, r6, lr}
    ldr r1, =data_020fed00
    mov r6, r0
    mov r5, #0x0
    str r1, [r6, #0x0]
    mov r4, r5
L_02075e1c:
    add r0, r6, r5, lsl #0x2
    ldr r0, [r0, #0xc]
    cmp r0, #0x0
    beq L_02075e38
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx r1
L_02075e38:
    add r0, r6, r5, lsl #0x2
    add r5, r5, #0x1
    str r4, [r0, #0xc]
    cmp r5, #0x4
    blt L_02075e1c
    mov r0, r6
    bl func_0205e84c
    mov r0, r6
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
