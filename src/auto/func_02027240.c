#include "m2c.h"

extern u32 data_020ece84[];

extern s32 func_020754e8(s32 a0, s32 a1);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02027240(s32 a0) {
    stmfd sp!, {r4, r5, r6, r7, lr}
    sub sp, sp, #0x14
    mov r5, r0
    ldr r0, [r5, #0x0]
    mov r4, #0x0
    ldr r7, [r0, #0x10]
    str r4, [sp, #0x4]
    str r7, [sp, #0x8]
    str r7, [sp, #0x10]
    str r4, [sp, #0xc]
    cmp r7, #0x0
    beq L_020272b0
    mov r6, r4
L_02027274:
    cmp r4, #0xa
    bhs L_020272b0
    ldr r0, [r5, #0x0]
    mov r1, r7
    bl func_020754e8
    add r1, r5, r4, lsl #0x3
    strb r0, [r1, #0x4]
    ldr r0, [r7, #0x10]
    str r6, [sp, #0x0]
    str r0, [r1, #0x8]
    ldr r7, [r7, #0x2c]
    add r4, r4, #0x1
    str r7, [sp, #0x10]
    cmp r7, r6
    bne L_02027274
L_020272b0:
    cmp r4, #0x0
    ldrne r0, =data_020ece84
    strne r0, [r5, #0x8]
    mov r0, r4
    add sp, sp, #0x14
    ldmia sp!, {r4, r5, r6, r7, pc}
}
// clang-format on
