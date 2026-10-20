#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02055348(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0xc
    ldr r4, [sp, #0x30]
    ldr r3, [r3, #0x0]
    mov lr, #0x0
    str r3, [sp, #0x4]
    mov r3, r4
    ldr r5, [r3, #0x0]
    ldr r3, [sp, #0x4]
    str r4, [sp, #0x30]
    mov r4, lr
    cmp r3, r5
    ldr r10, [sp, #0x34]
    ldr r9, [sp, #0x38]
    bgt L_02055468
L_02055384:
    ldr r3, [r1, #0x0]
    ldr r5, [r2, #0x0]
    str r3, [sp, #0x0]
    cmp r3, r5
    bgt L_0205544c
    ldr r3, [sp, #0x4]
    mov r11, #0x0
    and r3, r3, #0xf
    add r3, r0, r3, lsl #0x2
    str r3, [sp, #0x8]
    mov r3, #0x1
L_020553b0:
    ldr r5, [sp, #0x0]
    mov r6, r5, lsl #0x1c
    ldr r5, [sp, #0x8]
    add r5, r5, r6, lsr #0x16
    ldr r5, [r5, #0x24]
    cmp r5, #0x0
    beq L_02055434
L_020553cc:
    cmp r4, r9
    bhs L_0205541c
    cmp r4, #0x0
    mov r6, r11
    ldr r8, [r5, #0x0]
    mov r7, r11
    bls L_02055404
L_020553e8:
    ldr ip, [r10, r7, lsl #0x2]
    cmp ip, r8
    moveq r6, r3
    beq L_02055404
    add r7, r7, #0x1
    cmp r7, r4
    blo L_020553e8
L_02055404:
    cmp r6, #0x0
    bne L_02055428
    str r8, [r10, lr, lsl #0x2]
    add r4, r4, #0x1
    add lr, lr, #0x1
    b L_02055428
L_0205541c:
    add sp, sp, #0xc
    mov r0, r4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
L_02055428:
    ldr r5, [r5, #0x4]
    cmp r5, #0x0
    bne L_020553cc
L_02055434:
    ldr r5, [sp, #0x0]
    ldr r6, [r2, #0x0]
    add r5, r5, #0x1
    str r5, [sp, #0x0]
    cmp r5, r6
    ble L_020553b0
L_0205544c:
    ldr r3, [sp, #0x30]
    ldr r5, [r3, #0x0]
    ldr r3, [sp, #0x4]
    add r3, r3, #0x1
    str r3, [sp, #0x4]
    cmp r3, r5
    ble L_02055384
L_02055468:
    mov r0, r4
    add sp, sp, #0xc
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
