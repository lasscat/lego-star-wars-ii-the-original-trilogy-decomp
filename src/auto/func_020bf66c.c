#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020bf66c(s32 a0, s32 a1) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0xc
    ldr r2, [r1, #0x48]
    ldr r9, [r0, #0x14]
    ldr r4, [r2, #0x2c]
    ldr lr, [r0, #0x28]
    ldr r8, [r0, #0x18]
    ldr r7, [r0, #0x1c]
    ldr ip, [r2, #0x28]
    ldr r3, [r0, #0x24]
    ldr r10, [r0, #0x20]
    ldr r2, [r2, #0x24]
    mov r6, r9, lsl #0x1
    ldr r0, [r1, #0x2c]
    add r4, r4, lr
    sub lr, r0, r4
    mov r5, r8, lsl #0x1
    ldr r0, [r1, #0x28]
    add r3, ip, r3
    sub ip, r0, r3
    ldr r0, [r1, #0x24]
    add r2, r2, r10
    sub r0, r0, r2
    sub r6, r6, #0x1
    add r0, r9, r0
    and r0, r6, r0
    sub r0, r0, r9
    add r2, r0, r2
    sub r5, r5, #0x1
    add r0, r8, ip
    and r0, r5, r0
    mov r11, r7, lsl #0x1
    sub r0, r0, r8
    add r0, r0, r3
    sub r5, r11, #0x1
    add r3, r7, lr
    and r3, r5, r3
    sub r3, r3, r7
    add r4, r3, r4
    str r2, [sp, #0x0]
    str r0, [sp, #0x4]
    str r4, [sp, #0x8]
    ldr r3, [r1, #0x24]
    cmp r3, r2
    ldreq r3, [r1, #0x28]
    cmpeq r3, r0
    ldreq r0, [r1, #0x2c]
    cmpeq r0, r4
    movne r0, #0x1
    moveq r0, #0x0
    cmp r0, #0x0
    addeq sp, sp, #0xc
    ldmeqia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
    add r0, sp, #0x0
    add r3, r1, #0x24
    cmp r3, r0
    beq L_020bf764
    str r2, [r1, #0x24]
    ldr r0, [sp, #0x4]
    str r0, [r1, #0x28]
    ldr r0, [sp, #0x8]
    str r0, [r1, #0x2c]
L_020bf764:
    mov r0, #0x1
    strb r0, [r1, #0x45]
    add sp, sp, #0xc
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
