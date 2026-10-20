#include "m2c.h"

extern u32 data_0210e2f8[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020be930(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {lr}
    sub sp, sp, #0xc
    ldr r3, [r1, #0x4c]
    ldr     r2, =data_0210e2f8
    ldr r0, [sp, #0x18]
    ldr r2, [r2, r3, lsl #0x2]
    ldr r3, [r1, #0x38]
    smull ip, r0, r2, r0
    adds r2, ip, #0x800
    mov ip, r2, lsr #0xc
    adc r0, r0, #0x0
    orr ip, ip, r0, lsl #0x14
    ldr r2, [r1, #0x34]
    ldr r0, [r1, #0x30]
    add r3, r3, ip
    add r2, r2, ip
    add lr, r0, ip
    str lr, [sp, #0x0]
    str r2, [sp, #0x4]
    str r3, [sp, #0x8]
    ldr r0, [r1, #0x30]
    mov ip, #0x0
    cmp r0, lr
    ldreq r0, [r1, #0x34]
    cmpeq r0, r2
    ldreq r0, [r1, #0x38]
    cmpeq r0, r3
    movne ip, #0x1
    cmp ip, #0x0
    addeq sp, sp, #0xc
    ldmeqfd   sp!, {lr}
    addeq sp, sp, #0x10
    bxeq lr
    add r0, sp, #0x0
    add r2, r1, #0x30
    cmp r2, r0
    beq      L_020be9dc
    str lr, [r1, #0x30]
    ldr r0, [sp, #0x4]
    str r0, [r1, #0x34]
    ldr r0, [sp, #0x8]
    str r0, [r1, #0x38]
    L_020be9dc:
    mov r0, #0x1
    strb r0, [r1, #0x45]
    add sp, sp, #0xc
    ldmfd   sp!, {lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
