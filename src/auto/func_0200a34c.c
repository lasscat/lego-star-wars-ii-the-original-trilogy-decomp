#include "m2c.h"

s32 FX_Sqrt(s32);

// clang-format off
asm void func_0200a34c(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, ...) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r4, lr}
    ldr r3, [sp, #0xc]
    ldr r2, [sp, #0x10]
    smull r1, r4, r3, r3
    adds lr, r1, #0x800
    mov r1, r2, asr #0x1f
    mov r3, r1, lsl #0xe
    mov r1, #0x800
    adc ip, r4, #0x0
    adds r4, r1, r2, lsl #0xe
    orr r3, r3, r2, lsr #0x12
    mov lr, lr, lsr #0xc
    adc r1, r3, #0x0
    mov r2, r4, lsr #0xc
    orr lr, lr, ip, lsl #0x14
    orr r2, r2, r1, lsl #0x14
    mov r4, r0
    sub r0, lr, r2
    bl FX_Sqrt
    ldr r2, [sp, #0xc]
    mov r1, #0x0
    rsb r3, r2, #0x0
    add r2, r3, r0
    mov r2, r2, asr #0x1
    sub r0, r3, r0
    str r1, [r4, #0x0]
    cmp r2, #0x0
    mov r0, r0, asr #0x1
    ble L_0200a3ec
    str r2, [r4, #0x0]
    cmp r0, #0x0
    ldmleia sp!, {r4, lr}
    addle sp, sp, #0x10
    bxle lr
    cmp r0, r2
    strlt r0, [r4, #0x0]
    ldmia sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
L_0200a3ec:
    str r0, [r4, #0x0]
    ldmia sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
