#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0209adb4(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    ldrsh r4, [sp, #0x20]
    mov ip, r2, asr #0x2
    add ip, r2, ip, lsr #0x1d
    mov r2, r4, asr #0x2
    add lr, r4, r2, lsr #0x1d
    mov r4, r3, asr #0x2
    mov r5, lr, asr #0x3
    mov r7, ip, asr #0x3
    mov r2, r1, asr #0x2
    mov lr, r7, lsl #0x10
    add r4, r3, r4, lsr #0x1d
    add ip, r1, r2, lsr #0x1d
    ldrh r6, [sp, #0x28]
    ldrh r8, [sp, #0x24]
    mov r5, r5, lsl #0x10
    mov r1, r6, lsl #0xd
    mov r2, r8, lsl #0xd
    ldr r7, [r0, #0xa4]
    mov r1, r1, lsr #0x10
    mov r3, ip, lsl #0xd
    mov r6, lr, asr #0xb
    add r6, r6, r3, asr #0x10
    mov r4, r4, lsl #0xd
    mov r5, r5, asr #0xb
    add r3, r5, r4, asr #0x10
    add r6, r7, r6, lsl #0x1
    add r7, r7, r3, lsl #0x1
    mov r8, #0x0
    cmp r1, #0x0
    mov r0, r2, lsr #0x10
    ldmleia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov lr, r8
    L_0209ae38:
    mov r9, lr
    cmp r0, #0x0
    ble      L_0209ae6c
    mov r2, r8, lsl #0x5
    add r5, r6, r2, lsl #0x1
    add r3, r7, r2, lsl #0x1
    L_0209ae50:
    mov ip, r9, lsl #0x1
    ldrh r4, [ip, r5]
    add r2, r9, #0x1
    and r9, r2, #0xff
    strh r4, [ip, r3]
    cmp r9, r0
    blt      L_0209ae50
    L_0209ae6c:
    add r2, r8, #0x1
    and r8, r2, #0xff
    cmp r8, r1
    blt      L_0209ae38
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
