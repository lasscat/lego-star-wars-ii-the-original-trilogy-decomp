#include "m2c.h"

extern void NNS_G3dGlbMaterialColorSpecEmi();
extern u32 data_027e0874[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200ba44(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #8
    ldrb r1, [r0, #1]
    mov r1, r1, lsl #25
    mov r1, r1, lsr #25
    cmp r1, #3
    addls pc, pc, r1, lsl #2
    b      L_0200bd5c
    b      L_0200ba74
    b      L_0200ba8c
    b      L_0200bb84
    b      L_0200bc6c
L_0200ba74:
    mov r1, #0
    ldr     r0, =0x7fff
    mov r2, r1
    bl     NNS_G3dGlbMaterialColorSpecEmi
    add sp, sp, #8
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
L_0200ba8c:
    ldrb r1, [r0]
    ldr     r3, =data_027e0874
    mov r2, #0
    add r1, r1, r1, lsl #1
    mov r1, r1, asr #1
    mov r12, r3
    rsb r1, r1, #32
    mov r6, r3
L_0200baac:
    ldrh r8, [r3, #0xc]
    add r5, r6, r2, lsl #4
    cmp r12, r3
    mov r4, r8, lsl #27
    mov r4, r4, lsr #27
    mul r7, r4, r1
    mov lr, r7, lsl #11
    mov r4, lr, lsr #16
    bic r7, r8, #31
    and r4, r4, #31
    orr r4, r7, r4
    strh r4, [sp, #4]
    ldrh r8, [sp, #4]
    mov r4, r8, lsl #22
    mov r4, r4, lsr #27
    mul r7, r4, r1
    mov lr, r7, lsl #11
    mov r4, lr, lsr #16
    bic r7, r8, #992
    mov r4, r4, lsl #27
    orr r4, r7, r4, lsr #22
    strh r4, [sp, #4]
    ldrh r7, [sp, #4]
    mov r4, r7, lsl #17
    mov r4, r4, lsr #27
    mul lr, r4, r1
    mov lr, lr, lsl #11
    mov r4, lr, lsr #16
    bic r7, r7, #31744
    mov r4, r4, lsl #27
    orr r4, r7, r4, lsr #17
    strh r4, [sp, #4]
    ldrh r4, [sp, #4]
    strh r4, [r5, #0xc]
    beq    L_0200bb50
    ldr r4, [r3]
    str r4, [r6, r2, lsl #4]
    ldr r4, [r3, #4]
    str r4, [r5, #4]
    ldr r4, [r3, #8]
    str r4, [r5, #8]
L_0200bb50:
    add r2, r2, #1
    cmp r2, #4
    add r3, r3, #16
    add r12, r12, #16
    blt    L_0200baac
    ldrb r1, [r0]
    ldr     r0, =0x7fff
    mov r2, #0
    mov r1, r1, lsl #17
    mov r1, r1, lsr #16
    bl     NNS_G3dGlbMaterialColorSpecEmi
    add sp, sp, #8
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
L_0200bb84:
    ldr     r2, =data_027e0874
    mov r1, #0
    mov r3, r2
    mov r5, r2
L_0200bb94:
    ldrh r6, [r2, #0xc]
    add lr, r5, r1, lsl #4
    cmp r3, r2
    mov r4, r6, lsl #27
    mov r4, r4, lsr #27
    mov r12, r4, lsl #14
    mov r4, r12, lsr #16
    bic r6, r6, #31
    and r4, r4, #31
    orr r4, r6, r4
    strh r4, [sp, #2]
    ldrh r6, [sp, #2]
    mov r4, r6, lsl #22
    mov r4, r4, lsr #27
    mov r12, r4, lsl #14
    mov r4, r12, lsr #16
    bic r6, r6, #992
    mov r4, r4, lsl #27
    orr r4, r6, r4, lsr #22
    strh r4, [sp, #2]
    ldrh r6, [sp, #2]
    mov r4, r6, lsl #17
    mov r4, r4, lsr #27
    mov r12, r4, lsl #14
    mov r4, r12, lsr #16
    bic r6, r6, #31744
    mov r4, r4, lsl #27
    orr r4, r6, r4, lsr #17
    strh r4, [sp, #2]
    ldrh r4, [sp, #2]
    strh r4, [lr, #0xc]
    beq    L_0200bc2c
    ldr r4, [r2]
    str r4, [r5, r1, lsl #4]
    ldr r4, [r2, #4]
    str r4, [lr, #4]
    ldr r4, [r2, #8]
    str r4, [lr, #8]
L_0200bc2c:
    add r1, r1, #1
    cmp r1, #4
    add r2, r2, #16
    add r3, r3, #16
    blt    L_0200bb94
    ldrb r3, [r0]
    ldr     r0, =0x7fff
    mov r2, #0
    mov r1, r3, lsl #6
    orr r1, r1, r3, lsl #1
    orr r1, r1, r3, lsl #11
    mov r1, r1, lsl #16
    mov r1, r1, lsr #16
    bl     NNS_G3dGlbMaterialColorSpecEmi
    add sp, sp, #8
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
L_0200bc6c:
    ldrb r0, [r0]
    tst r0, #8
    beq    L_0200bd4c
    ldr     r1, =data_027e0874
    mov r0, #0
    mov r2, r1
    mov lr, r1
L_0200bc88:
    ldrh r4, [r1, #0xc]
    add r12, lr, r0, lsl #4
    cmp r2, r1
    mov r3, r4, lsl #27
    mov r3, r3, lsr #27
    mov r3, r3, lsl #15
    mov r3, r3, lsr #16
    bic r4, r4, #31
    and r3, r3, #31
    orr r3, r4, r3
    strh r3, [sp]
    ldrh r4, [sp]
    mov r3, r4, lsl #22
    mov r3, r3, lsr #27
    mov r3, r3, lsl #15
    mov r3, r3, lsr #16
    bic r4, r4, #992
    mov r3, r3, lsl #27
    orr r3, r4, r3, lsr #22
    strh r3, [sp]
    ldrh r4, [sp]
    mov r3, r4, lsl #17
    mov r3, r3, lsr #27
    mov r3, r3, lsl #15
    mov r3, r3, lsr #16
    bic r4, r4, #31744
    mov r3, r3, lsl #27
    orr r3, r4, r3, lsr #17
    strh r3, [sp]
    ldrh r3, [sp]
    strh r3, [ip, #0xc]
    beq    L_0200bd20
    ldr r3, [r1]
    str r3, [lr, r0, lsl #4]
    ldr r3, [r1, #4]
    str r3, [ip, #4]
    ldr r3, [r1, #8]
    str r3, [ip, #8]
L_0200bd20:
    add r0, r0, #1
    cmp r0, #4
    add r1, r1, #16
    add r2, r2, #16
    blt    L_0200bc88
    ldr     r0, =0x7fff
    mov r2, #0
    sub r1, r0, #23
    bl     NNS_G3dGlbMaterialColorSpecEmi
    add sp, sp, #8
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
L_0200bd4c:
    mov r1, #0
    ldr     r0, =0x7fff
    mov r2, r1
    bl     NNS_G3dGlbMaterialColorSpecEmi
L_0200bd5c:
    add sp, sp, #8
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
