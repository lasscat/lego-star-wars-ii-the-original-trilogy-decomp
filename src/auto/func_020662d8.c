#include "m2c.h"

extern void func_02066238(s32 a0, s32 a1);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020662d8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    stmfd sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    movs r6, r2
    ldr r4, [sp, #0x20]
    mov r8, r0
    mov r7, r1
    mov r5, r3
    sub r6, r6, #0x1
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr r9, =0x3ff
L_020662fc:
    ldrh r0, [r5, #0x0]
    ldr r2, [r8, #0x28]
    and r1, r0, r9
    mov r0, r2, asr #0x1
    add r0, r2, r0, lsr #0x1e
    movs r0, r0, asr #0x2
    mla r2, r1, r2, r4
    sub r1, r0, #0x1
    beq L_02066334
L_02066320:
    ldr r0, [r2], #0x4
    cmp r1, #0x0
    str r0, [r7], #0x4
    sub r1, r1, #0x1
    bne L_02066320
L_02066334:
    ldrh r0, [r5, #0x0]
    tst r0, #0x400
    beq L_02066350
    ldr r1, [r8, #0x28]
    mov r0, r8
    sub r1, r7, r1
    bl func_02066238
L_02066350:
    ldr r0, [r8, #0x24]
    cmp r6, #0x0
    add r5, r5, r0, lsl #0x1
    sub r6, r6, #0x1
    bne L_020662fc
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
