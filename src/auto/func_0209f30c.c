#include "m2c.h"

extern u32 data_020ff9a8[];
extern u32 data_020ff9a0[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0209f30c(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, lr}
    sub sp, sp, #0x8
    ldr r3, [r0, #0x0]
    mov r1, #0x0
    cmp r3, #0x0
    moveq r2, r1
    beq      L_0209f338
    ldr r2, [r3, #0x8]
    ldrh r2, [r2, #0x4]
    mov r2, r2, lsl #0xc
    L_0209f338:
    ldr ip, [r3, #0x0]
    ldr r3, [sp, #0x14]
    add lr, ip, r3
    str lr, [sp, #0x4]
    cmp lr, r2
    blt      L_0209f390
    ldrh r3, [r0, #0x6]
    mov r1, r3, lsl #0x1d
    movs r1, r1, lsr #0x1f
    beq      L_0209f370
    ldr     r1, =data_020ff9a8
    ldr r1, [r1, #0x0]
    str r1, [sp, #0x4]
    b      L_0209f388
    L_0209f370:
    ldr     r1, =data_020ff9a0
    bic r3, r3, #0x1
    ldr r1, [r1, #0x0]
    sub r1, r2, r1
    str r1, [sp, #0x4]
    strh r3, [r0, #0x6]
    L_0209f388:
    mov r1, #0x1
    b      L_0209f3c4
    L_0209f390:
    ldr     r3, =data_020ff9a8
    ldr ip, [r3, #0x0]
    cmp lr, ip
    bge      L_0209f3c4
    ldrh r1, [r0, #0x6]
    mov r3, r1, lsl #0x1d
    movs r3, r3, lsr #0x1f
    addne r1, lr, r2
    strne r1, [sp, #0x4]
    biceq r1, r1, #0x1
    streqh r1, [r0, #0x6]
    streq ip, [sp, #0x4]
    mov r1, #0x1
    L_0209f3c4:
    ldr ip, [sp, #0x4]
    ldr r3, [r0, #0x0]
    mov r2, r1, lsl #0x1f
    str ip, [r3, #0x0]
    ldrh r3, [r0, #0x6]
    str ip, [sp, #0x0]
    bic r3, r3, #0x2
    orr r2, r3, r2, lsr #0x1e
    strh r2, [r0, #0x6]
    mov r0, r1
    add sp, sp, #0x8
    ldmfd   sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
